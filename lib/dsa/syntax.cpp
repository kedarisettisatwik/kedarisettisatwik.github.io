
#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int>vec){
    cout << endl;
    for (int i = 0;i <vec.size();i++){
        cout << vec[i] << " "; 
    }
    // vec[2] = -1; -> this will change here but not in the original vec
}

void reverseVector(vector<int>& vec){
    reverse(vec.begin(),vec.end()); // this will effect the original vector also because we used & -> reference
}

void vector_ds(){
    vector<int>v1;
    v1 = {10,1,3};
    v1.push_back(4);
    cout << v1[3] << endl;

    v1.pop_back();  // 4 got removed

    v1.insert(v1.begin()+1,3,5);
    // v1 = {1,2,3} now 5 got inserted 3 times at begin + 1 -> v1 = {1,5,5,5,2,3} 
    for (auto it:v1){
        cout << it << " ";
    }
    // cout << v.begin() << v.back(); -> 1,3
    // cout << v1.size(); now its 6
    // v1.clear() -> v1 = {}
    // v1.empty() -> now its true
    v1.erase(v1.begin()+1,v1.begin()+3);
    // v1[1] and v1[2] got removed -> v1 = {1,5,2,3}
    printVector(v1);

    reverseVector(v1);
    
    printVector(v1);

    sort(v1.begin(),v1.end()); // ascending order
    printVector(v1);

    vector<pair<string,int>>v2;
    v2.push_back({"sat",2});
    cout << "\n" << v2[0].first << " " << v2[0].second << endl;
}

void printPairs(pair<int,int>arr[]){
    cout << arr[1].first;
}

void pair_ds(){
    pair<int,int>p1={1,3};
    cout << p1.first << " " << p1.second << endl;
    pair<int,pair<string,int>>p2 = {1,{"sat",3}};
    cout << p2.first << " " << p2.second.first << " " << p2.second.second << endl;
    pair<int,int>arr[] = {{1,2},{3,4},{5,6}};
    cout << arr[1].second << endl;
    printPairs(arr);
}

void queue_ds(){
    queue<int>q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.back() += 4;
    // q = {1,2,7}
    cout << q.front() << " " << q.back() << endl;
    q.pop(); // queue - pop means 1 got out
    cout << q.front() << endl; 
    cout << q.empty() << endl;
}

void deque_ds(){
    deque<int>dq;
    // deque<int>dq = {5,7};
    dq.push_back(2);
    dq.push_front(1);
    dq.push_back(3);
    cout << dq.front() << " " << dq.back() << endl;
    dq.pop_front();
    cout << dq.front() << " " << dq.back() << endl;
    dq.push_front(6);
    dq.pop_back();
    dq.insert(dq.begin(),2,10);
    // two 10's got inserted at the dq.begin() of dq
    cout << dq.front() << " " << dq.back() << endl;
    cout << dq.empty() << endl;
}

void stack_ds(){
    stack<int>st;
    st.push(1);
    st.push(2);
    st.push(3);
    cout << st.top() << endl; // -> 3
    st.pop(); // 3 got removed
    cout << st.top() << endl; // now 2;
    // st.size(), st.empty()
}

void priorityQueue_ds(){
    priority_queue<int>pq; // large element on top
    pq.push(5);
    pq.push(10);
    pq.push(2);
    cout << pq.top() << endl;
    pq.pop();
    cout << pq.top();
    // pq.size() pq.empty()
}

void set_ds(){
    set<int>s;
    s.insert(1);
    s.insert(3);
    s.insert(2); // s = {1,3,2}
    s.insert(1); // s = {1,2} unique elments
    auto it = s.find(3); // address of 3 in s
    s.erase(it);
    for (auto it = s.begin();it != s.end();it++){
        cout << *it << " ";
    }
    s = {4,5,6};
    s.erase(5);
    cout << endl;
    for (auto it = s.begin();it != s.end();it++){
        cout << *it << " ";
    }
    cout << endl;
}

void multiSet_ds(){
    multiset<int>ms;
    ms.insert(1);
    ms.insert(2);
    ms.insert(1); // ms = {1,1,2};
    cout << ms.count(1) << endl; // 2
    ms.erase(1); // all 1's removed
    ms = {1,1,1,3,2}; // ms = {1,1,1,2,3}
    auto it = ms.find(3);
    cout << *it << endl;
}

void unorderedSet_ds(){
    unordered_set<int>s;
    // no sorting but unique elements
}

void map_ds(){
    // stores in order wrt key here key is int
    map<int,string>mp;
    mp.insert(pair<int,string>(2,"apple"));
    mp.insert(pair<int,string>(1,"ball"));
    for (auto it = mp.begin(); it != mp.end();it++) {
        cout << it->first << " " << it->second << endl;
    }
    // unordered_map -> same without sort
}

struct Node{
    int data;
    Node* next;
    Node(int v){
        data = v;
        next = NULL;
    }
};

Node* buildList(vector<int>vec){
    Node* head = new Node(vec[0]);
    Node* temp = head;
    for (int i = 1;i<vec.size();i++){
        temp->next = new Node(vec[i]);
        temp = temp->next;
    }
    return head;
}


struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        data = val;
        left = right = NULL;
    }
};

TreeNode* buildTree(){
    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->right->right->left = new TreeNode(8);
    root->right->right->right = new TreeNode(7);

    // Node* root = new Node(-10);
    // root->left = new Node(9);
    // root->right = new Node(20);
    // root->right->left = new Node(15);
    // root->right->right = new Node(7);

    return root;
}

int main(){
    // vector_ds();
    // pair_ds();
    // queue_ds();
    // deque_ds();
    // stack_ds();
    // priorityQueue_ds();
    // set_ds();
    // multiSet_ds();
    // unorderedSet_ds();
    // map_ds();


    // Node* x = new Node(3);
    // x->next = new Node(4);

    // Node* l = buildList({1,2,3,4,5,6,7});
    // printList(l);

    // TreeNode* root = buildTree();

    return 0;
}

// Java

import java.util.*;

public class JavaNotes {

    /* ============================================================
       1. BASIC SYNTAX & DATA TYPES  (compare with C++)
       ============================================================
       - No pointers, no manual memory management (Garbage Collected)
       - Every file's public class name must == file name
       - Entry point: public static void main(String[] args)
       - Semicolons required, blocks in {}

       PRIMITIVE TYPES (stored by value, NOT objects):
         byte    1 byte   -128 to 127
         short   2 bytes
         int     4 bytes  (default for whole numbers)
         long    8 bytes  -> needs 'L' suffix: long x = 100000000000L;
         float   4 bytes  -> needs 'f' suffix: float f = 3.14f;
         double  8 bytes  (default for decimals)
         char    2 bytes  -> single quotes: char c = 'A';
         boolean true/false

       WRAPPER CLASSES (Object versions, required for generics like ArrayList<Integer>):
         Integer, Long, Double, Float, Character, Boolean, Short, Byte
         Autoboxing:   Integer x = 5;  // int -> Integer automatically
         Unboxing:     int y = x;      // Integer -> int automatically

       STRING (like std::string, but IMMUTABLE):
         String s = "hello";
         s.length(), s.charAt(0), s.substring(1,3), s.equals("hello")
         // NEVER use == to compare String content, only .equals()
         s + " world"        -> concatenation
         StringBuilder sb = new StringBuilder();
         sb.append("a"); sb.toString();
         // Use StringBuilder for lots of concatenation (String is immutable -> slow otherwise)

       VARIABLES:
         int a = 10;
         final int b = 20;   // like 'const' in C++, cannot be reassigned

       CONDITIONALS / LOOPS  (basically identical to C++):
         if / else if / else
         switch(x) { case 1: ...; break; default: ...; }
         for (int i = 0; i < n; i++) {}
         while (cond) {}
         do {} while(cond);
         for (int val : arr) {}   // like C++ range-based for
    */

    // ============================================================
    // 2. ARRAYS  (fixed size, like C++ raw arrays / C-style arrays)
    // ============================================================
    static void array_ds(){
        int[] arr = new int[5];          // default all 0
        int[] arr2 = {10, 1, 3, 4};      // direct init
        arr2[0] = 99;                     // access/modify
        System.out.println(arr2.length);  // NOTE: .length is a field here, NOT a method (no parentheses)

        // 2D array
        int[][] grid = new int[3][3];     // all 0
        int[][] grid2 = {{1,2},{3,4}};
        System.out.println(grid2[1][0]);  // 3

        // Arrays utility class (like <algorithm> for C-arrays)
        Arrays.sort(arr2);                        // ascending sort
        System.out.println(Arrays.toString(arr2)); // print whole array nicely
        int[] copy = Arrays.copyOf(arr2, arr2.length); // clone
        Arrays.fill(arr, 7);                       // fill all with 7
        int idx = Arrays.binarySearch(arr2, 4);    // array must already be sorted
    }

    // arrays are reference types -> passed "by reference" automatically (like C++ passing by &)
    static void reverseArray(int[] arr){
        int i = 0, j = arr.length - 1;
        while (i < j){
            int t = arr[i]; arr[i] = arr[j]; arr[j] = t;
            i++; j--;
        }
        // this WILL change the original array, same as C++ pass-by-reference
    }

    // ============================================================
    // 3. ArrayList  <-- this is Java's "vector"
    // ============================================================
    static void arrayList_ds(){
        ArrayList<Integer> v1 = new ArrayList<>();
        v1.add(10); v1.add(1); v1.add(3);
        v1.add(4);                  // push_back equivalent
        System.out.println(v1.get(3)); // access -> like v1[3]

        v1.remove(v1.size() - 1);   // pop_back equivalent (removes by INDEX)
        // WATCH OUT: remove(int index)   removes by index
        //            remove(Object o)    removes by value -> v1.remove(Integer.valueOf(4));

        v1.add(1, 5);                // insert 5 at index 1 (only inserts once, no "count" param like C++)
        for (int i = 0; i < 2; i++) v1.add(1, 5); // to insert 3 times, just loop it

        for (int it : v1) System.out.print(it + " ");
        System.out.println();

        // v1.isEmpty(), v1.size(), v1.clear()
        // remove a RANGE, like C++'s erase(begin+1, begin+3):
        v1.subList(1, 3).clear();    // removes index 1 and 2

        Collections.reverse(v1);     // reverse (like std::reverse)
        Collections.sort(v1);        // ascending sort (like std::sort)
        // Collections.sort(v1, Collections.reverseOrder()); // descending

        System.out.println(v1);      // ArrayList prints nicely by default, no loop needed!

        // "vector of pairs" -> no built-in pair, so use a List of a custom Pair class (see section 4)
    }

    // ============================================================
    // 4. "PAIR" equivalent -> Java has NO built-in std::pair
    //    Most common fix in DSA: write your own tiny generic class
    // ============================================================
    static class Pair<A, B> {
        A first; B second;
        Pair(A a, B b){ first = a; second = b; }
    }
    static void pair_ds(){
        Pair<Integer,Integer> p1 = new Pair<>(1, 3);
        System.out.println(p1.first + " " + p1.second);

        Pair<Integer, Pair<String,Integer>> p2 = new Pair<>(1, new Pair<>("sat", 3));
        System.out.println(p2.first + " " + p2.second.first + " " + p2.second.second);

        // Alternative that needs no custom class: AbstractMap.SimpleEntry
        AbstractMap.SimpleEntry<Integer,Integer> e = new AbstractMap.SimpleEntry<>(1, 2);
        System.out.println(e.getKey() + " " + e.getValue());
    }

    // ============================================================
    // 5. QUEUE  (this is an INTERFACE - you must instantiate it as a LinkedList or ArrayDeque)
    // ============================================================
    static void queue_ds(){
        Queue<Integer> q = new LinkedList<>();
        q.add(1); q.add(2); q.add(3);   // .offer() is a safer alternative (no exception on failure)
        System.out.println(q.peek());    // front() equivalent
        q.poll();                         // pop() equivalent -> removes AND returns front
        System.out.println(q.peek());
        System.out.println(q.isEmpty());
        // NOTE: Queue interface has no "last element" method, unlike C++'s q.back()
    }

    // ============================================================
    // 6. DEQUE  (ArrayDeque is the standard choice; also doubles as a Stack, see section 7)
    // ============================================================
    static void deque_ds(){
        Deque<Integer> dq = new ArrayDeque<>();
        dq.addLast(2);        // push_back
        dq.addFirst(1);       // push_front
        dq.addLast(3);
        System.out.println(dq.peekFirst() + " " + dq.peekLast());
        dq.pollFirst();        // pop_front
        System.out.println(dq.peekFirst() + " " + dq.peekLast());
        dq.addFirst(6);
        dq.pollLast();         // pop_back
        System.out.println(dq.isEmpty());
    }

    // ============================================================
    // 7. STACK
    // ============================================================
    static void stack_ds(){
        // Option A: legacy java.util.Stack class (works, but Vector-based & synchronized -> slower)
        Stack<Integer> st = new Stack<>();
        st.push(1); st.push(2); st.push(3);
        System.out.println(st.peek());  // top() equivalent -> 3
        st.pop();                        // removes AND returns top
        System.out.println(st.peek());   // now 2
        // st.size(), st.isEmpty()

        // Option B (PREFERRED in modern Java / competitive programming): ArrayDeque as a stack
        Deque<Integer> st2 = new ArrayDeque<>();
        st2.push(1); st2.push(2); st2.push(3);  // push = addFirst
        System.out.println(st2.peek());           // 3
        st2.pop();                                 // pop = removeFirst
    }

    // ============================================================
    // 8. PRIORITY QUEUE  (MIN-heap by default! this is the OPPOSITE of C++'s default max-heap)
    // ============================================================
    static void priorityQueue_ds(){
        PriorityQueue<Integer> pq = new PriorityQueue<>(); // MIN heap by default
        pq.add(5); pq.add(10); pq.add(2);
        System.out.println(pq.peek()); // 2 (smallest on top - opposite of C++!)
        pq.poll();
        System.out.println(pq.peek());

        // For a MAX heap (like C++'s default priority_queue), pass a comparator:
        PriorityQueue<Integer> maxPq = new PriorityQueue<>(Collections.reverseOrder());
        maxPq.add(5); maxPq.add(10); maxPq.add(2);
        System.out.println(maxPq.peek()); // 10
    }

    // ============================================================
    // 9. SET  (TreeSet = sorted/std::set, HashSet = unordered_set, LinkedHashSet = insertion order)
    // ============================================================
    static void set_ds(){
        TreeSet<Integer> s = new TreeSet<>();  // sorted, unique -> matches std::set
        s.add(1); s.add(3); s.add(2);
        s.add(1);                       // duplicate silently ignored
        s.remove(3);
        for (int it : s) System.out.print(it + " ");
        System.out.println();

        // s.first(), s.last(), s.contains(2)
        // TreeSet-only navigation (no HashSet equivalent): s.higher(1), s.lower(2), s.ceiling(x), s.floor(x)

        HashSet<Integer> hs = new HashSet<>();       // no order, faster O(1) avg
        hs.add(1); hs.add(2);

        LinkedHashSet<Integer> lhs = new LinkedHashSet<>(); // keeps insertion order, still unique
    }

    // ============================================================
    // 10. MULTISET equivalent -> Java has NO built-in multiset.
    //     Standard fix: use a HashMap<Integer,Integer> as a frequency counter
    // ============================================================
    static void multiSet_ds(){
        HashMap<Integer,Integer> freq = new HashMap<>();
        int[] vals = {1,1,1,3,2};
        for (int v : vals){
            freq.put(v, freq.getOrDefault(v, 0) + 1); // ms.count(v) equivalent
        }
        System.out.println(freq.get(1)); // 3, like ms.count(1)
        freq.remove(1);                  // removes the key entirely (all copies, since we store a count)
    }

    // ============================================================
    // 11. MAP  (TreeMap = sorted/std::map, HashMap = unordered_map)
    // ============================================================
    static void map_ds(){
        TreeMap<Integer,String> mp = new TreeMap<>(); // sorted by key
        mp.put(2, "apple");
        mp.put(1, "ball");
        for (Map.Entry<Integer,String> it : mp.entrySet()){
            System.out.println(it.getKey() + " " + it.getValue());
        }
        // mp.get(1), mp.containsKey(1), mp.remove(1), mp.getOrDefault(3,"none")

        HashMap<Integer,String> hm = new HashMap<>(); // no order, O(1) avg lookups
        // LinkedHashMap<> -> keeps insertion order if you need that instead
    }

    // ============================================================
    // 12. LINKED LIST -> two common approaches
    // ============================================================
    // A) Built-in java.util.LinkedList (implements BOTH List and Deque)
    static void linkedList_builtin(){
        LinkedList<Integer> ll = new LinkedList<>();
        ll.addFirst(1); ll.addLast(2);
        System.out.println(ll);
    }

    // B) Custom Node class (like your C++ struct Node) - what you'll write in DSA interviews
    static class Node {
        int data;
        Node next;
        Node(int v){ data = v; next = null; }
    }
    static Node buildList(int[] vals){
        Node head = new Node(vals[0]);
        Node temp = head;
        for (int i = 1; i < vals.length; i++){
            temp.next = new Node(vals[i]);
            temp = temp.next;
        }
        return head;
    }
    static void printList(Node head){
        while (head != null){
            System.out.print(head.data + " ");
            head = head.next;
        }
        System.out.println();
    }

    // ============================================================
    // 13. BINARY TREE
    // ============================================================
    static class TreeNode {
        int data;
        TreeNode left, right;
        TreeNode(int v){ data = v; left = right = null; }
    }
    static TreeNode buildTree(){
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        root.left.left = new TreeNode(4);
        root.right.left = new TreeNode(5);
        root.right.right = new TreeNode(6);
        root.right.right.left = new TreeNode(8);
        root.right.right.right = new TreeNode(7);
        return root;
    }
    static void inorder(TreeNode root){
        if (root == null) return;
        inorder(root.left);
        System.out.print(root.data + " ");
        inorder(root.right);
    }

    // ============================================================
    // 14. DYNAMIC PROGRAMMING  -> a pattern, not a data structure, but included since you asked
    // ============================================================

    // (a) Memoization (top-down): use an array or HashMap as a cache
    static int fibMemo(int n, int[] dp){
        if (n <= 1) return n;
        if (dp[n] != -1) return dp[n];        // already computed -> reuse
        return dp[n] = fibMemo(n-1, dp) + fibMemo(n-2, dp);
    }
    static int fib(int n){
        int[] dp = new int[n+1];
        Arrays.fill(dp, -1);
        return fibMemo(n, dp);
    }

    // (b) Tabulation (bottom-up): build the table iteratively, no recursion
    static int fibTab(int n){
        if (n <= 1) return n;
        int[] dp = new int[n+1];
        dp[0] = 0; dp[1] = 1;
        for (int i = 2; i <= n; i++) dp[i] = dp[i-1] + dp[i-2];
        return dp[n];
    }

    // (c) Classic DP example: 0/1 Knapsack (2D tabulation)
    static int knapsack(int[] wt, int[] val, int W){
        int n = wt.length;
        int[][] dp = new int[n+1][W+1];
        for (int i = 1; i <= n; i++){
            for (int w = 0; w <= W; w++){
                dp[i][w] = dp[i-1][w];                       // don't take item i
                if (wt[i-1] <= w){
                    dp[i][w] = Math.max(dp[i][w], dp[i-1][w-wt[i-1]] + val[i-1]); // take item i
                }
            }
        }
        return dp[n][W];
    }

    // (d) Space-optimized DP (rolling variables) -> when dp[i] only depends on the last couple of states
    static int climbStairs(int n){
        if (n <= 2) return n;
        int prev2 = 1, prev1 = 2;
        for (int i = 3; i <= n; i++){
            int cur = prev1 + prev2;
            prev2 = prev1;
            prev1 = cur;
        }
        return prev1;
    }

    // ============================================================
    // MAIN
    // ============================================================
    public static void main(String[] args) {
        // array_ds();
        // arrayList_ds();
        // pair_ds();
        // queue_ds();
        // deque_ds();
        // stack_ds();
        // priorityQueue_ds();
        // set_ds();
        // multiSet_ds();
        // map_ds();
        // linkedList_builtin();

        // Node l = buildList(new int[]{1,2,3,4,5,6,7});
        // printList(l);

        // TreeNode root = buildTree();
        // inorder(root);

        // System.out.println(fib(10));
        // System.out.println(fibTab(10));
        // System.out.println(knapsack(new int[]{1,3,4,5}, new int[]{1,4,5,7}, 7));
        // System.out.println(climbStairs(5));
    }
}