# MaikalCode

A static DSA learning dashboard with light and dark themes. Browse **3,687 coding problems**, search by title or number, filter by topic/difficulty/solution coverage, and save study progress locally.

[Dark theme preview](preview-dark.png) · [Light theme preview](preview-light.png)

## Start locally

From this folder:

```sh
python -m http.server 8000
```

Open http://localhost:8000/. No npm install, build, server API, account, or API key is required. You can also open `index.html` directly to read problems and use the built-in Two Sum animation; the Python execution worker requires HTTP(S) hosting.

## Features

- Searchable, paginated problem library; SQL/database, shell, and standalone Pandas/JavaScript exercises excluded.
- Statement, examples, constraints and original problem link.
- Full solution tabs for C++, Python and Java, with source attribution and copying.
- Four expandable hints: official hints where available; explicitly labeled study prompts fill remaining slots.
- Written approaches and complexity explanations from the source collection, where available.
- Two Sum complement-lookup animation that works without a Python runtime.
- For other problems, an execution visualizer runs the real Python solution in a browser worker and records code lines, variables and return values. Arrays, matrices, maps and standard linked-list/tree values have visual representations.
- Play/pause, forward/back, reset, speed control, timeline and paginated dry-run log.
- Editable example arguments, execution cancellation, input errors and timeout feedback.
- Light/dark theme preference and per-problem study progress stored in browser local storage. Export/import progress as JSON.
- Responsive layout and keyboard-accessible tabs. No analytics or external accounts.

## Coverage and limits

All 3,687 included problems have a description. **3,554** have complete solutions in all three requested languages; **3,561** have a Python solution. **133 problems have at least one missing language** in the imported sources. The library includes them with visible coverage labels; it never presents a starter stub as a full solution. Select “Solution gaps” to review them. See `coverage.json` for the exact list.

The catalogue is the existing 4,096-problem snapshot, not a live mirror. Exclusions: 323 database/SQL entries, four shell problems, and 82 standalone Pandas/JavaScript exercises. The two solution collections are imported separately and may not cover every newer problem.

Python execution is a general line/state walkthrough, not a hand-authored geometric animation for every algorithm. It requires an internet connection for the initial Pyodide runtime download. Standard JSON arguments, linked lists, binary trees and operation-sequence design classes are supported. Custom judge interfaces (for example `Master`, `read4`, `NestedInteger`, graph-specific `Node` types, concurrency callbacks, or interactive APIs) need a problem-specific harness and may report an explicit error. Presence of a Python solution does not guarantee the generic harness supports that problem.

Traces stop after 1,200 events or five execution seconds; initial runtime loading has a 90-second timeout. Variable previews are limited to avoid huge displays. A trace records state **before** a highlighted line, and return events record the returned value. It shows the result of execution, not an independent correctness verdict. Only Python is executed; C++ and Java are displayed for the LeetCode judge environment. C++ solutions may use C++20/23.

## Inputs

Enter an outer JSON array containing the function's arguments:

```json
[[2, 7, 11, 15], 9]
```

For linked-list arguments, use arrays of node values. For binary trees, use level-order arrays with `null` for missing nodes. Design-class exercises use two arguments: operation names and their corresponding argument arrays. The first operation is the constructor name.

## Publish on GitHub Pages

1. Create a repository named `MaikalCode` and upload **the contents of this folder** to its root, including `content/`, both license files, and `.nojekyll`.
2. Configure GitHub Pages to deploy the repository's main branch from its root folder.
3. The entry page is `index.html`. Hash links such as `#104` deep-link to individual problems and work under a repository subpath.

No secrets or build-time environment variables are needed. Keep all files together. If you publish this folder as a subdirectory of a different project, its URL ends in `/MaikalCode/`.

## Project files

- `index.html`, `styles.css`, `app.js`: interface, filtering, themes, local progress and visualization playback.
- `catalog.js`: lightweight problem index.
- `content/*.js`: lazily loaded problem descriptions, hints, approaches and attributed solution code, grouped by problem number.
- `runner.worker.js`, `trace_runner.py`: browser-only Python worker and tracing harness.
- `coverage.json`: content coverage and remaining gaps.
- `ATTRIBUTION.md`, `CONTENT-LICENSE.txt`, `WALKCCC-LICENSE.txt`, `LICENSE`: content provenance and license terms.

The imported content is a static snapshot. The original data-export workspace contains the content builder and source archives; those large build inputs are not needed to run or publish this project. Edit the problem records in `content/` and matching metadata in `catalog.js` when adding curated material.
