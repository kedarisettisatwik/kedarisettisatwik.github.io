"""Browser-only Python tracing harness. No imported solution runs on the host."""
import ast
import collections
import inspect
import json
import sys
import time
import types
from collections import deque


class ListNode:
    def __init__(self, val=0, next=None):
        self.val, self.next = val, next


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val, self.left, self.right = val, left, right


def linked(values):
    dummy = tail = ListNode()
    for value in values or []:
        tail.next = ListNode(value)
        tail = tail.next
    return dummy.next


def tree(values):
    if not values or values[0] is None:
        return None
    root = TreeNode(values[0])
    pending = deque([root])
    i = 1
    while pending and i < len(values):
        node = pending.popleft()
        if values[i] is not None:
            node.left = TreeNode(values[i])
            pending.append(node.left)
        i += 1
        if i < len(values) and values[i] is not None:
            node.right = TreeNode(values[i])
            pending.append(node.right)
        i += 1
    return root


def encode(value, depth=0, visited=None):
    if value is None or isinstance(value, (bool, int, float)):
        if isinstance(value, int) and abs(value) > 9007199254740991:
            return str(value)
        if isinstance(value, float) and (abs(value) == float('inf') or value != value):
            return str(value)
        return value
    if isinstance(value, str):
        return value[:500]
    if depth > 3:
        return '…'
    visited = set() if visited is None else set(visited)
    if id(value) in visited:
        return '(cycle)'
    visited.add(id(value))
    if isinstance(value, ListNode):
        items, seen = [], set()
        while value and len(items) < 20:
            if id(value) in seen:
                items.append('(cycle)')
                break
            seen.add(id(value))
            items.append(encode(value.val, depth + 1, visited))
            value = value.next
        return {'type': 'LinkedList', 'values': items}
    if isinstance(value, TreeNode):
        items, queue = [], deque([value])
        while queue and len(items) < 31:
            node = queue.popleft()
            items.append(node.val if node else None)
            if node:
                queue.extend([node.left, node.right])
        while items and items[-1] is None:
            items.pop()
        return {'type': 'Tree (level order)', 'values': items}
    if isinstance(value, dict):
        return {str(k)[:60]: encode(v, depth + 1, visited) for k, v in list(value.items())[:24]}
    if isinstance(value, (list, tuple, set, frozenset, deque)):
        return [encode(v, depth + 1, visited) for v in list(value)[:32]]
    if isinstance(value, (types.ModuleType, types.FunctionType, type)):
        return None
    if hasattr(value, '__dict__'):
        return {k: encode(v, depth + 1, visited) for k, v in list(vars(value).items())[:10] if not k.startswith('__')}
    return str(value)[:120]


def run_payload(payload):
    code = payload['code']
    args = payload['args']
    frames, result, error, truncated = [], None, '', False
    start = time.monotonic()
    namespace = {'ListNode': ListNode, 'TreeNode': TreeNode}
    prelude = '''from __future__ import annotations
from typing import *
from collections import *
from functools import *
from itertools import *
from heapq import *
from bisect import *
from math import *
from operator import *
import math, heapq, bisect, collections, functools, itertools, random, re, string
inf = float('inf')
'''
    exec(prelude, namespace)
    if 'SortedList' in code or 'SortedDict' in code or 'SortedSet' in code:
        exec('from sortedcontainers import SortedList, SortedDict, SortedSet', namespace)
    parsed = ast.parse(code)
    classes = [n for n in parsed.body if isinstance(n, ast.ClassDef)]

    def trace(frame, event, arg):
        nonlocal truncated
        if frame.f_code.co_filename != '<maikal-solution>':
            return trace
        if time.monotonic() - start > 5 or len(frames) >= 1200:
            truncated = True
            raise TimeoutError('Trace stopped at 1,200 events or 5 seconds. Try a smaller example.')
        if event in ('line', 'return') and frame.f_code.co_name not in {'<module>', '__annotate__'} and frame.f_code.co_name not in {c.name for c in classes}:
            variables = {}
            for key, value in list(frame.f_locals.items())[:22]:
                if key.startswith('__') or isinstance(value, (types.ModuleType, types.FunctionType, type)):
                    continue
                variables[key] = encode(value)
            frames.append({'line': frame.f_lineno, 'event': event,
                           'function': frame.f_code.co_name, 'variables': variables,
                           'result': encode(arg) if event == 'return' else None})
        return trace

    def convert(value, annotation):
        annotation = str(annotation)
        if 'ListNode' in annotation and isinstance(value, list):
            return [linked(v) for v in value] if ('List[' in annotation or 'list[' in annotation) else linked(value)
        if 'TreeNode' in annotation and isinstance(value, list):
            return tree(value)
        return value

    try:
        # Keep submitted-source line numbers stable; annotations are deferred at compile time.
        import __future__
        compiled = compile(code, '<maikal-solution>', 'exec', flags=__future__.annotations.compiler_flag)
        sys.settrace(trace)
        exec(compiled, namespace)
        if 'Solution' in namespace:
            solution_class = next(c for c in classes if c.name == 'Solution')
            methods = [n.name for n in solution_class.body if isinstance(n, (ast.FunctionDef, ast.AsyncFunctionDef)) and not n.name.startswith('_')]
            if not methods:
                raise ValueError('No public solution method found.')
            instance = namespace['Solution']()
            method = getattr(instance, payload.get('method') or methods[0])
            params = list(inspect.signature(method).parameters.values())
            converted = [convert(v, p.annotation) for v, p in zip(args, params)]
            required = sum(p.default is inspect.Parameter.empty for p in params)
            if not required <= len(args) <= len(params):
                raise ValueError(f'{method.__name__} expects {required}–{len(params)} arguments; received {len(args)}.')
            result = method(*converted)
            if result is None:
                result = {'in_place_arguments': [encode(v) for v in converted]}
        else:
            if len(args) != 2 or not isinstance(args[0], list) or not isinstance(args[1], list):
                raise ValueError('Design problems need [operation names, argument lists] as two JSON arguments.')
            operations, arguments = args
            if len(operations) != len(arguments) or not operations:
                raise ValueError('Operations and argument lists must have the same nonzero length.')
            klass = namespace.get(operations[0])
            if not isinstance(klass, type):
                raise ValueError(f'Class {operations[0]} is not available in this solution.')
            instance = klass(*arguments[0])
            result = [None]
            for name, values in zip(operations[1:], arguments[1:]):
                result.append(getattr(instance, name)(*values))
    except Exception as exc:
        error = f'{type(exc).__name__}: {exc}'
    finally:
        sys.settrace(None)
    return json.dumps({'frames': frames, 'result': encode(result), 'error': error,
                       'truncated': truncated, 'elapsed': round(time.monotonic() - start, 3)}, allow_nan=False)
