
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

