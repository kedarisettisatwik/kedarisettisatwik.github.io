#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int>vec){
    cout << endl;
    for (auto it : vec) cout << it << " ";
    cout << endl;
}

void printGrid(vector<vector<int>>grid){
    cout << endl;
    for(auto r: grid){
        for (auto c:r) cout << c << " ";
        cout << endl;
    }
    cout << endl;
}

void printStack(stack<int>st){
    cout << endl;
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

struct LLNode{
    int data;
    LLNode* next;
    LLNode(int x){
        data = x;
        next = NULL;
    }
};

LLNode* buildList(vector<int>vec){
    LLNode* head = new LLNode(vec[0]);
    LLNode* temp = head;
    int n = vec.size();
    for (int i = 1;i < n;i++){
        temp->next = new LLNode(vec[i]);
        temp = temp->next;
    }
    return head;
}

void printList(LLNode* head){
    cout << endl;
    while (head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

struct TNode{
    int data;
    TNode* left;
    TNode* right;
    TNode* nextRight; // ! for problem no 2106231146 
    TNode(int x){
        data = x;
        left = NULL;
        right = NULL;
        nextRight = NULL;
    }
};

TNode* buildTree(){
    TNode* root = new TNode(1);
    root->left = new TNode(2);
    root->right = new TNode(3);
    root->left->left = new TNode(4);
    root->right->right = new TNode(5);
    root->left->right = new TNode(6);
    root->right->left = new TNode(7);
    root->right->left->right = new TNode(8);
    return root;
}

void printTreeHelp(TNode* root,int i, int& xLeft){
    if (root == NULL){
        xLeft = min(xLeft,i);
        return ;
    }
    printTreeHelp(root->left,i-1,xLeft);
    printTreeHelp(root->right,i+1,xLeft);
}
void printTree(TNode* root){
    cout << "-------------------------------------------------" << endl;
    cout << "\n" << endl;
    if (root == NULL){
        cout << "NULL" << endl;
    }
    string space = "\t";
    int xLeft = -1;
    printTreeHelp(root,0,xLeft);
    queue<pair<TNode*,int>>q;
    q.push({root,0});
    while(q.empty() == false){
        int s = q.size();
        int x = 0;
        int y = 0;
        unordered_map<int,string>mp;
        int xx = xLeft;
        for(int i = 0;i < s;i++){
            TNode* f = q.front().first;
            int ind = q.front().second;
            q.pop();
            x = min(x,ind);
            y = max(y,ind);
            string str = "[" + to_string(f->data)+"]";
            if (f->left != NULL){
                str = "[_" + to_string(f->data) + "]";
                q.push({f->left,ind-1});
            }
            if (f->right != NULL){
                str = "[" + to_string(f->data) + "_]";
                q.push({f->right,ind+1});
            }
            if (f->left != NULL && f->right != NULL){
                str = "[_" + to_string(f->data) + "_]";
            }
            mp[ind] = mp[ind] + str;
        }
        for (int i = x;i <= y;i++){
            string str = mp[i];
            for(int j = xx;j < (i);j++){
                cout << space;
            }
            cout << str;
            xx = i;
        }
        cout << "\n" << endl;
    }
    cout << endl;
    cout << "-------------------------------------------------" << endl;
}

class CNode {
    public:
        int val;
        vector<CNode*> children;
        CNode() {}
        CNode(int _val) {
            val = _val;
        }
        CNode(int _val, vector<CNode*> _children) {
            val = _val;
            children = _children;
        }
};

// ? 0106231625
void bubbleSort(vector<int>vec){
    printVector(vec);
    int n = vec.size();
    for (int i = 0;i < n-1;i++){
        // for 1st iteration largest element reaches end index
        for (int j = 0;j < n-1;j++){
            // compare j and j + 1, make sure large lies at j + 1 - for ascending order
            // compare j and j + 1, make sure large lies at j - for desending  order
            if (vec[j+1] < vec[j]){
                int temp = vec[j+1];
                vec[j+1] = vec[j];
                vec[j] = temp;
            }
        }
    }
    printVector(vec);
}

// ? 0106231657
void selectionSort(vector<int>vec){
    printVector(vec);
    int n = vec.size();
    for (int i = 0; i < n;i++){
        int minIndex = i;
        for (int j = i+1;j < n;j++){
            if (vec[j] < vec[minIndex]){
                minIndex = j;
            }
        }
        // minIndex = index of minimum element in subarray[i:n]
        // swap minIndex, i
        int temp = vec[i];
        vec[i] = vec[minIndex];
        vec[minIndex] = temp;
    }
    printVector(vec);
}

// ? 0106231926
void insertionSort(vector<int>vec){
    printVector(vec);
    int n = vec.size();
    for (int i = 1;i < n;i++){
        // move j to left until j - 1 is less than i
        // i.e if j - 1 > j stop
        int j = i;
        while (j > 0 && vec[j-1] > vec[j]){
            int temp = vec[j-1];
            vec[j-1] = vec[j];
            vec[j] = temp;
            j--;
        }
    }
    printVector(vec);
}

// ? 0106231948
void mergeTwoSortedVectors(vector<int>A,vector<int>B){
    printVector(A);
    printVector(B);
    vector<int>c; // merged vector
    int n = A.size();
    int m = B.size();
    int i = 0;
    int j = 0;
    while (i < n && j < m){
        // push the minimum element and move the index
        if(A[i] < B[j]){
            c.push_back(A[i]);
            i++;
        }else{
            c.push_back(B[j]);
            j++;
        }
    }
    while (i < n){
        c.push_back(A[i]);
        i++;
    }
    while (j < m){
        c.push_back(B[j]);
        j++;
    }
    printVector(c);
}

// ? 0106232013
void merge(vector<int>&vec,int l,int m,int r){
    // l to m is sorted
    // m+1 to r is sorted
    vector<int>merged;
    int i = l;
    int j = m+1;
    while (i <= m && j <= r){
        if (vec[i] < vec[j]){
            merged.push_back(vec[i]);
            i++;
        }else{
            merged.push_back(vec[j]);
            j++;
        }
    }
    while (i <= m){
        merged.push_back(vec[i]);
        i++;
    }
    while (j <= r){
        merged.push_back(vec[j]);
        j++;  
    }
    for (int k = l;k <= r;k++){
        vec[k] = merged[k-l];
    }
}
void mergeSort(vector<int>&vec,int l,int r){
    if (l >= r) return ; 
    int m = l + (r-l)/2; // divide vec
    mergeSort(vec,l,m);
    mergeSort(vec,m+1,r);
    // after sorting two half's , merge them
    merge(vec,l,m,r);
}

// ? 0206230938
void countSort(vector<int>vec){
    printVector(vec);
    int n = vec.size();
    int maxEle = vec[0];
    for (auto it : vec) maxEle = max(maxEle,it);
    vector<int>count(maxEle+1,0); // count freq array 
    for (auto it : vec){
        count[it]++;
    }
    int i = 0; // across vec
    int j = 0; // across count freq
    while (i < n){
        if (count[j] == 0){
            j++;
            continue;
        }else{
            vec[i] = j;
            count[j]--;
            i++;
        }
    }
    printVector(vec);
}

// ? 0206230954
int partition(vector<int>&vec,int l,int r){
    int pivot = vec[l];
    int i = l; // from start
    int j = r; // from last
    while (i < j){
        // from left move to right until vec[left] is more than pivot
        while (i <= r && vec[i] <= pivot){
            i++;
        }
        // from right move to left until vec[right] is less than pivot
        while (j >= l && vec[j] > pivot){
            j--;
        }
        // elements which are less than pivot should be at start, remaining at last
        // swap i,j
        if (i >= j) break ;
        int temp = vec[i];
        vec[i] = vec[j];
        vec[j] = temp;
    }
    int temp = vec[j];
    vec[j] = vec[l];
    vec[l] = temp;
    // now j is the boundary, below j are less than pivot, after j all are greater than pivot
    return j;
}
void quickSort(vector<int>&vec,int l,int r){
    if (l > r) return ;
    int p = partition(vec,l,r);
    // all elements on the  left of vec[p] are smaller than vec[p]
    // all elements on the right of vec[p] are larget than vec[p]
    quickSort(vec,l,p-1);
    quickSort(vec,p+1,r);
}

// ? 0206231026
void largestEle(vector<int>vec){
    int maxEle = INT_MIN;
    int ind = -1;
    int n = vec.size();
    for (int i = 0; i < n;i++){
        if (vec[i] > maxEle){
            maxEle = vec[i];
            ind = i;
        }
    }
    printVector(vec);
    cout << "Index : " << ind << " MaxElement : " << maxEle << endl; 
}

// ? 0206231037
void secondLargestEle(vector<int>vec){
    int max1 = INT_MIN;
    int max2 = INT_MIN;
    int n = vec.size();
    for (int i = 0;i < n;i++){
        if (vec[i] > max1){
            max2 = max1;
            max1 = vec[i];
        }else if (vec[i] < max1 && vec[i] > max2){
            max2 = vec[i];
        }
    }
    printVector(vec);
    cout << "Second Largest : " << max2 << endl;
}

// ? 0206231043
void checkSorted(vector<int>vec){
    printVector(vec);
    int n = vec.size();
    for (int i = 0;i < n-1;i++){
        if (vec[i] > vec[i+1]){
            cout << "Not Sorted" << endl;
            return ;
        }
    }
    cout << "Sorted" << endl;
    return ;
}

// ? 0206231053
void removeDuplicates(vector<int>vec){
    printVector(vec);
    // if vec is not sorted, sort it first
    int n = vec.size();
    int slowPointer = 0;
    int fastPointer = 1;
    while (fastPointer < n){
        if (vec[slowPointer] != vec[fastPointer]){
            if (slowPointer + 1 < n) vec[slowPointer+1] = vec[fastPointer];
            slowPointer++;
            fastPointer++;
        }else{
            fastPointer++;
        }
    }
    // vec have 0 to slowPointer no duplicates
    slowPointer++; // from here make all zero
    while (slowPointer < n){
        vec[slowPointer] = 0;
        slowPointer++;
    }
    printVector(vec);
}

// ? 0206231107
void leftRotate1(vector<int>vec){
    printVector(vec);
    int n = vec.size();
    int start = vec[0];
    for (int i = 1;i < n;i++){
        vec[i-1] = vec[i];
    }
    vec[n-1] = start;
    printVector(vec);
}

// ? 0206231108
void leftRotateK(vector<int>vec,int k){
    printVector(vec);
    int n = vec.size();
    k = k % n; // if k is greater than n it will be usefull
    reverse(vec.begin(),vec.begin()+k);
    reverse(vec.begin()+k,vec.end());
    reverse(vec.begin(),vec.end());
    printVector(vec);
}

// ? 0206231208
void moveZerosEnd(vector<int>vec){
    printVector(vec);
    int n = vec.size();
    int slowPointer = 0;
    int fastPointer = 0;
    while (fastPointer < n){
        if (vec[fastPointer] != 0){
            vec[slowPointer] = vec[fastPointer];
            fastPointer++;
            slowPointer++;
        }else{
            fastPointer++;
        }
    }
    while (slowPointer < n){
        vec[slowPointer] = 0;
        slowPointer++;
    }
    printVector(vec);
}

// ? 0206231216
void linearSearch(vector<int>vec,int k){
    printVector(vec);
    int n = vec.size();
    for (int i = 0;i < n;i++){
        if (vec[i] == k){
            cout << k << " index : " << i << endl;
            return ;
        }
        if (vec[i] > k){
            // this condition is to be written only if give array is sorted 
            // else we should check from i = 0 to n
            break ;
        }
    }
    cout << k << " index : " << -1 << endl;
}

// ? 0206231224
void unionAB(vector<int>A,vector<int>B){
    printVector(A);
    printVector(B);
    vector<int>c; // c - union vector, if arrays are asked construct a array of size A + B
    int i = 0; // across A
    int j = 0; // across B
    int lastElement = -1;
    while (i < A.size() && j < B.size()){
        if (A[i] <= B[j]){
            if (A[i] != lastElement) c.push_back(A[i]);
            lastElement = A[i];
            i++;
        }else{
            if (B[j] != lastElement) c.push_back(B[j]);
            lastElement = B[j];
            j++;
        }
    }
    while (i < A.size()){
        if (A[i] != lastElement){
            lastElement = A[i];
            c.push_back(A[i]);
            i++;
        }
    }
    while (j < B.size()){
        if (B[j] != lastElement){
            lastElement = B[j];
            c.push_back(B[j]);
            j++;
        }
    }
    printVector(c);
}

// ? 0206231256
void intersectionAB(vector<int>A,vector<int>B){
    printVector(A);
    printVector(B);
    vector<int>c; // intersection vector
    int i = 0;
    int j = 0;
    while (i < A.size() && j < B.size()){
        if (A[i] < B[j]) i++;
        else if (A[i] > B[j]) j++;
        else{ 
            c.push_back(A[i]); 
            i++;
            j++;
        }
    }
    printVector(c);
}

// ? 0206231351
void missingNumber(vector<int>vec,int n){
    int sum1 = (n)*(n+1)*0.5; // sum of first n natural numbers
    int sum2 = 0; // sum of integers
    for (auto it : vec) sum2 += it;
    printVector(vec);
    cout << "missed : " << (sum1 - sum2) << endl;
}

// ? 0206231359
void maxConsecutive1s(vector<int>vec){
    printVector(vec);
    int n = vec.size();
    int maxL = 0; // maxLength
    int l = 0; // temperary length
    for (int i = 0;i < n;i++){
        if (vec[i] != 1){
            l = 0; // vec[i] != 1 means consecutiveness of 1 broken
            continue;
        }
        l++;
        maxL = max(maxL,l);
    }
    cout << "max consecutive ones : " << maxL << endl;
}

// ? 0206231406
void appearonce(vector<int>vec){
    // a xor a = 0
    // b xor 0 = b
    int n = vec.size();
    int xr = 0; // xor of all elements
    for (auto it : vec) xr = xr ^ it;
    printVector(vec);
    cout << "appeard only once : " << xr << endl; 
}

// ? 0206231421
void rowWithMax1s(vector<vector<int>>grid){
    // given each row is sorted itself, all 1's from the left
    printGrid(grid);
    int r = grid.size(); // no of rows
    int c = grid[0].size(); // no of cols
    for (int j = 0;j < c;j++){
        // search column wise
        for (int i = 0; i < r;i++){
            if (grid[i][j] == 1){
                cout << "Max 1s in row : " << i << endl;
                return;
            }
        }
    }
}

// ? 0206231429
void longestSubArraySumPosK(vector<int>vec,int k){
    // for vec is all of non negative integers.
    int n = vec.size();
    int l = 0;
    int r = 0;
    int sum = 0;
    int maxL = 0; // longest length of subArray with sum k
    pair<int,int>p; // start and end index of longest subArray with sum k
    int cnt = 0; // count no of subArrays with sum k
    while (r < n && l < n){
        sum += vec[r];
        while (sum > k){
            sum -= vec[l];
            l++;
        }
        if (sum == k){
            int len = r-l+1;
            cnt++;
            if (len >= maxL){
                p.first = l;
                p.second = r;
                maxL = len;
            }
        }
        r++;
    }
    printVector(vec);
    cout << "No of subArrays possible with sum " << k << " : " << cnt << endl;
    cout << "Max length subArray with sum " << k << " : " << maxL << endl;
    for (int i = p.first; i <= p.second;i++){
        cout << vec[i] << " ";
    } 
    cout << endl;
}

// ? 0206231514
void longestSubArraySumPosNegK(vector<int>vec,int k){
    // vec can have both pos + neg integers
    unordered_map<int,int>preSum;
    int sum = 0;
    int maxLen = 0;
    int n = vec.size();
    for (int i = 0;i < n;i++){
        sum += vec[i];
        if (sum == k) {
            maxLen = max(maxLen, i + 1);
        }
        // calculate the sum of remaining part i.e. x-k:
        int rem = sum - k;

        //Calculate the length and update maxLen:
        if (preSum.find(rem) != preSum.end()) {
            int len = i - preSum[rem];
            maxLen = max(maxLen, len);
        }

        //Finally, update the map checking the conditions:
        if (preSum.find(sum) == preSum.end()) {
            preSum[sum] = i;
        }
    }
    printVector(vec);
    cout << "max Len : " << maxLen << endl;
}

// ? 0206231748
void pairWithSumK(vector<int>vec,int k){
    int l = 0;
    int r = vec.size()-1;
    sort(vec.begin(),vec.end());
    printVector(vec);
    while (l < r){
        if (vec[l]+vec[r] == k){
            cout << vec[l] << " + " << vec[r] << " = " << k << endl;
            return ;
        }else if (vec[l] + vec[r] < k){
            l++;
        }else{
            r--;
        }
    }
    cout << "pair not possible for " << k << endl;
}

// ? 0206231805
void majorityElement(vector<int>vec){
    int n = vec.size();
    int ele = vec[0];
    int cnt = 0;
    for (int i = 0; i < n;i++){
        if (cnt == 0){
            ele = vec[i];
        }
        if (vec[i] == ele){
            cnt++;
        }else{
            cnt--;
        }
    }
    printVector(vec);
    int cnt1 = 0;
    for (int i = 0;i<n;i++){
        if (vec[i] == ele) cnt1++;
    }
    if (cnt1 > n/2) cout << "Majority Element : " << ele << endl;
    else cout << "No Majority Element" << endl;
}

// ? 0206231823
void maxSumSubArray(vector<int>vec){
    int maxSum = vec[0];
    int sum = 0;
    int n = vec.size();
    int i = 0;
    while (i < n){
        sum += vec[i];
        if (sum < 0) sum = 0;
        maxSum = max(maxSum,sum);
        i++;
    }
    printVector(vec);
    cout << "maxSum : " << maxSum << endl;
}

// ? 0206231844
void maxSumPair(vector<int>vec){
    int maxSum = INT_MIN;
    int n = vec.size();
    for (int i = 0;i < n-1;i++){
        maxSum = max(maxSum,vec[i]+vec[i+1]);
    }
    printVector(vec);
    cout << "maxSum : " << maxSum << endl;
}

// ? 0206231858
void alternatePosNeg(vector<int>arr){
    printVector(arr);
    int n = arr.size();
    vector<int>pos;
    vector<int>neg;
    for(int i = 0;i<n;i++){
        if (arr[i] < 0) neg.push_back(arr[i]);
        else pos.push_back(arr[i]);
    }
    vector<int>vec; // output
    int P = pos.size();
    int N = neg.size();
    int i = 0;
    while (i < P && i < N){
        vec.push_back(pos[i]);
        vec.push_back(neg[i]);
        i++;
    }
    while (i < P){
        vec.push_back(pos[i]);
        i++;
    }
    while (i < N){
        vec.push_back(neg[i]);
        i++;
    }
    for (int j = 0;j < vec.size();j++){
        arr[j] = vec[j];
    }
    printVector(arr);
}

// ? 0206231912
void nextPermutation(vector<int>vec){
    printVector(vec);
    int n = vec.size();
    int ind = n-1;
    for (int i = n-1;i > 0;i--){
        if (vec[i] > vec[i-1]){
            ind = i-1;
            break;
        }
    }
    if(ind == n-1){
        reverse(vec.begin(),vec.end());
        printVector(vec);
        return ;
    }
    for (int i = n-1;i > ind;i--){
        if (vec[i] > vec[ind]){
            int temp = vec[ind];
            vec[ind] = vec[i];
            vec[i] = temp;
            break;
        }
    }
    sort(vec.begin()+ind+1,vec.end());
    printVector(vec);
}

// ? 0206231948
void leaders(vector<int>vec){
    int maxFromRight = INT_MIN;
    int n = vec.size();
    vector<int>leaders;
    for (int i = n-1;i >= 0;i--){
        if (vec[i] > maxFromRight){
            leaders.push_back(vec[i]);
            maxFromRight = vec[i];
        }
    }
    printVector(vec);
    cout << "leaders : " << endl;
    printVector(leaders);
}

// ? 0206231958
void longestConsecutiveSeq(vector<int>vec){
    int n = vec.size();
    unordered_set<int>st;
    int maxLen = 0;
    for (int i = 0;i < n;i++){
        st.insert(vec[i]);
    }
    for (int i = 0;i < n;i++){
        if (st.find(vec[i]-1) == st.end()){
            int l = 0;
            int temp = vec[i];
            while (st.find(temp) != st.end()){
                temp++;
                l++;
            }
            maxLen = max(maxLen,l);
        }
    }
    printVector(vec);
    cout << "maxConsecutiveSeq : " << maxLen << endl;
}

// ? 0206232012
void setZerosMatrix(vector<vector<int>>grid){
    printGrid(grid);
    int r = grid.size();
    int c = grid[0].size();
    int col0 = 1;
    int row0 = 1;
    for (int i = 0;i < r;i++){
        if (grid[i][0] == 0){
            col0 = 0;
        }
    }
    for (int j = 0;j < c;j++){
        if (grid[0][j] == 0){
            row0 = 0;
        }
    }
    for (int i = 1;i < r;i++){
        for (int j = 1;j < c;j++){
            if (grid[i][j] == 0){
                grid[i][0] = 0;
                grid[0][j] = 0;
            }
        }
    }
    for (int i = 1;i < r;i++){
        for (int j = 1;j < c;j++){
            if (grid[i][0] == 0 || grid[0][j] == 0){
                grid[i][j] = 0;
            }
        }
    }
    if (col0 == 0){
        for (int i = 0;i < r;i++){
            grid[i][0] = 0;
        }
    }
    if (row0 == 0){
        for (int j = 0;j < c;j++){
            grid[0][j] = 0;
        }
    }
    printGrid(grid);
}

// ? 0206232029
void rotateMatrix(vector<vector<int>>grid){
    printGrid(grid);
    int r = grid.size();
    int c = grid[0].size();
    // transpose
    for (int i = 0;i < r;i++){
        for(int j = 0;j < i;j++){
            int temp = grid[i][j];
            grid[i][j] = grid[j][i];
            grid[j][i] = temp;
        }
    }
    // mirror horizantal
    for (int i = 0;i < r;i++){
        for(int j = 0;j < c/2;j++){
            int temp = grid[i][j];
            grid[i][j] = grid[i][c-j-1];
            grid[i][c-j-1] = temp;
        }
    }
    printGrid(grid);
}

// ? 0206232038
void printSpiral(vector<vector<int>>grid){
    int r = grid.size();
    int c = grid[0].size();
    vector<int>spiral;
    printGrid(grid);
    // four sides boundaries
    int topB = 0;
    int rightB = c-1;
    int downB = r-1;
    int leftB = 0;
    int i = 0;
    int j = 0;
    while (topB <= downB && leftB <= rightB){
        // first move to right Boundary
        while (j <= rightB){
            spiral.push_back(grid[i][j]);
            j++;
        }j--; 
        rightB--; // for next cycle shrink boundary
        i++; // now move one step down
        // now move to bottom Boundary
        while (i <= downB){
            spiral.push_back(grid[i][j]);
            i++;
        }i--;
        downB--; // for next cycle shrink boundary
        j--; // now move one step left
        // now move to left Boundary
        if (leftB <= rightB){
            while (j >= leftB){
                spiral.push_back(grid[i][j]);
                j--;
            }j++;
            leftB++; // for next cycle shrink boundary
        }
        if (topB < downB){
            i--; // now move one step up
            while (i > topB){
                spiral.push_back(grid[i][j]);
                i--;
            }i++;
            topB++;
        }
        j++;
    }
    printVector(spiral);
}

// ? 0306231018
void pascalTriangle(int n){
    // nC0 to nCn
    vector<int>ans={1};
    int temp = 1;
    for (int i = 0;i < n;i++){
        temp = temp * (n-i);
        temp = temp / (i+1);
        ans.push_back(temp);
    }
    printVector(ans);
}

// ? 0306231053
void threeSum(vector<int>vec){
    // i + j + k == 0
    sort(vec.begin(),vec.end());
    vector<vector<int>>triplets;
    int n = vec.size();
    for (int i = 0;i < n;i++){
        if (i > 0 && vec[i] == vec[i-1]) continue;
        int j = i+1;
        int k = n-1;
        while (j < k){
            int sum = vec[i]+vec[j]+vec[k];
            if (sum < 0){
                // increase j
                j++;
            }else if (sum > 0){
                k--;
            }else{
                triplets.push_back({vec[i],vec[j],vec[k]});
                j++;
                k--;
                while (j < k && vec[j-1] == vec[j]) j++; // for unique triplets
                while (j < k && vec[k+1] == vec[k]) k--; // for unique triplets
            }
        }
    }
    printVector(vec);
    printGrid(triplets);
}

// ? 0306231122
void fourSum(vector<int>vec,int target){
    sort(vec.begin(),vec.end());
    vector<vector<int>>quadralets;
    int n = vec.size();
    for (int i = 0;i < n;i++){
        if (i != 0 && vec[i-1] == vec[i]) continue; // already same vec[i] taken
        for (int j = i+1;j < n;j++){
            if (j != i+1 && vec[j-1] == vec[j]) continue;
            int l = j+1; // two sum 
            int k = n-1;
            while (l < k){
                int sum = vec[i]+vec[j]+vec[l]+vec[k];
                if (sum < target){
                    // increase l
                    l++;
                }else if (sum > target){
                    // decrease k
                    k--;
                }else{
                    quadralets.push_back({vec[i],vec[j],vec[l],vec[k]});
                    l++;
                    k--;
                    while (l < k && vec[l] == vec[l-1]) l++;
                    while (l < k && vec[k] == vec[k+1]) k--;
                }
            }
        }
    }
    printVector(vec);
    printGrid(quadralets);
}

// ? 0306231152
void longestSubArraySumZero(vector<int>vec){
    int maxLen = 0; // longest sub array length
    int n = vec.size();
    unordered_map<int,int>prefixSum; // map for prefix sum
    prefixSum.insert({0,-1}); // empty array also sum zero
    int sum = 0; // cummulative sum
    for (int i = 0;i < n;i++){
        sum += vec[i];
        // we may not have sum == 0 as it is cummulative
        // but in prefixSum map we may have some val so that val == sum,
        // means in btw val,sum middle sum is zero
        if (prefixSum.find(sum) != prefixSum.end()){
            maxLen = max(maxLen,(i - prefixSum[sum]));
        }else{
            prefixSum[sum] = i;
        }
    }
    printVector(vec);
    cout << "maxLen : " << maxLen << endl;
}

// ? 0306231410
LLNode* insertNodeEnd(LLNode* head,int x){
    if (head == NULL) return (new LLNode(x));
    LLNode* temp = head;
    while (temp -> next != NULL){
        temp = temp -> next;
    }
    temp->next = new LLNode(x);
    return head;
}
LLNode* insertNodeBegin(LLNode* head,int x){
    if (head == NULL) return (new LLNode(x));
    LLNode* temp = new LLNode(x);
    temp->next = head;
    return temp;
}

// ? 0306231419
LLNode* deleteNodeX(LLNode* head,int x){
    LLNode* temp = head;
    int i = 1;
    while (temp->next != NULL && i < x-1){
        temp = temp -> next;
        i++;
    }
    if(temp->next != NULL) temp->next = temp->next->next;
    return head;
}

// ? 0306231427
void listLength(LLNode* head){
    LLNode* temp = head;
    int l = 0;
    while (temp != NULL){
        temp = temp -> next;
        l++;
    }
    cout << "len : " << l << endl;
}

// ? 0306231433
void getMiddleList(LLNode* head){
    LLNode* slowPointer = head;
    LLNode* fastPointer = head;
    while (fastPointer != NULL && fastPointer->next != NULL){
        slowPointer = slowPointer->next;
        fastPointer = fastPointer->next->next;
    }
    cout << "middle : " << slowPointer->data << endl;
}

// ? 0306231441
LLNode* reverseList(LLNode* head){
    LLNode* prev = NULL;
    LLNode* curr = head;
    while (curr != NULL){
        LLNode* temp = curr->next;
        curr -> next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

// ? 0606230746
void checkCycleList(LLNode* head){
    if (head == NULL || head->next == NULL){
        cout << "No Cycle" << endl;
        return ;
    }
    LLNode* slowPointer = head;
    LLNode* fastPointer = head->next;
    while (fastPointer != NULL && fastPointer->next != NULL){
        if (fastPointer == slowPointer){
            cout << "detected cycle" << endl;
            return ;
        }
        slowPointer = slowPointer->next;
        fastPointer = fastPointer->next->next;
    }
    cout << "No Cycle" << endl;
    return ;
}

// ? 0606230759
void startingLoop(LLNode* head){
    LLNode* slowPointer = head;
    LLNode* fastPointer = head;
    LLNode* t1 = head;
    LLNode* t2 = NULL;
    while (fastPointer != NULL && fastPointer->next != NULL){
        fastPointer = fastPointer->next->next;
        slowPointer = slowPointer->next;
        if (fastPointer == slowPointer){
            t2 = slowPointer;
            break;
        }
    }
    if (t2 == NULL){
        cout << "No loop" << endl;
        return ;
    }
    while (t1 != t2){
        t1 = t1->next;
        t2 = t2->next;
    }
    cout << "loop starts at " << t1->data << endl;
}

// ? 0606230838
void lengthLoop(LLNode* head){
    LLNode* slowPointer = head;
    LLNode* fastPointer = head;
    bool loopFound = false;
    while (fastPointer != NULL && fastPointer->next != NULL){
        slowPointer = slowPointer -> next;
        fastPointer = fastPointer->next->next;
        if (slowPointer == fastPointer){
            loopFound = true;
            break;
        }
    }
    if (!loopFound){
        cout << "No Loop" << endl;
        return ;
    }
    LLNode* temp = slowPointer->next;
    int len = 1;
    while (slowPointer != temp){
        temp = temp->next;
        len++;
    }
    cout << "loop len : " << len << endl;
}

// ? 0606230916
LLNode* reverseList1(LLNode* head){
    LLNode* prev = NULL;
    LLNode* curr = head;
    while (curr != NULL){
        LLNode* temp = curr->next;
        curr -> next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}
void checkPalindromeList(LLNode* head){
    printList(head);
    // fist find out middle Node
    LLNode* slowPointer = head;
    LLNode* fastPointer = head->next;
    while (fastPointer != NULL && fastPointer->next != NULL){
        slowPointer = slowPointer->next;
        fastPointer = fastPointer->next->next;
    }
    LLNode* middleNode = slowPointer;
    middleNode->next = reverseList1(middleNode->next);
    printList(head);
    LLNode* ptr1 = head;
    LLNode* ptr2 = middleNode->next;
    while (ptr2 != NULL){
        if (ptr1->data != ptr2->data){
            cout << "Not palindrome" << endl;
            return ;
        }
        ptr2 = ptr2->next;
        ptr1 = ptr1->next;
    }
    cout << "palindrome" << endl;
}

// ? 0606231002
void delNodeEndX(LLNode* head,int x){
    printList(head);
    // to delete xth node from end,
    // first keep one pointer at xth node from start
    LLNode* fast = head;
    for (int i = 1;i<=x;i++){
        fast = fast->next;
    }
    LLNode* slow = head;
    while (fast->next != NULL){
        fast = fast->next;
        slow = slow->next;
    }
    // now slow = x th node from end;
    slow -> next = slow -> next -> next;
    printList(head);
}

// ? 0606231420
void sort012_linkedlist(LLNode* head){
    printList(head);
    vector<int>count = {0,0,0};
    LLNode* temp = head;
    while (temp != NULL){
        count[temp->data]++;
        temp = temp->next;
    }
    int i = 0;
    temp = head;
    while (temp != NULL && i < 3){
        if (count[i] != 0){
            temp->data = i;
            temp = temp->next;
            count[i]--;
        }else{
            i++;
        }
    }
    printList(head);
}

// ? 0606231429
void intersectionNodeList(LLNode* head1, LLNode* head2){
    printList(head1);
    printList(head2);
    int l1 = 0;
    int l2 = 0;
    LLNode* t1 = head1;
    LLNode* t2 = head2;
    while (t1 != NULL){
        t1 = t1->next;
        l1++;
    }
    while (t2 != NULL){
        t2 = t2->next;
        l2++;
    }
    t1 = head1;
    t2 = head2;
    for (int i = 0;i<abs(l2-l1);i++){
        if (l2 > l1) t2 = t2->next;
        else t1 = t1->next;
    }
    // now t1 or t2 moved such that they both are at same distance from intersection node
    while (t1 != t2 && t1 != NULL && t2 != NULL){
        t1 = t1->next;
        t2 = t2->next;
    }
    if (t1 != NULL && t2 != NULL){
        cout << "intersection point : " << t2->data << endl;
        return ;
    }
    cout << "no intersection" << endl;
    return ;
}

// ?  0606231503
void add1ToList(LLNode* head){
    printList(head);
    LLNode* lastNot9 = NULL;
    LLNode* temp = head;
    while (temp->next != NULL){
        if (temp->data != 9){
            lastNot9 = temp;
        }
        temp = temp->next;
    }
    if (temp->data == 9){
        if (lastNot9 == NULL){
            // means in give number all are 9's
            // ans = 1 + 00000...
            LLNode* head1 = new LLNode(1);
            temp = head;
            while (temp != NULL){
                temp->data = 0;
                temp = temp->next;
            }
            head1->next = head;
            printList(head1);
            return ;
        }else{
            temp = lastNot9;
            temp->data++;
            temp = temp->next;
            while (temp != NULL){
                temp->data = 0;
                temp = temp->next;
            }
            printList(head);
            return ;
        }
    }else{
        // if last node is not 9, ans is simple increase last node data and return same head
        temp->data++;
        printList(head);
    }
}

// ?  0606231804
void addNumsList(LLNode* head1,LLNode* head2){
    // given list are reverse in order
    printList(head1);
    printList(head2);
    LLNode* t1 = head1;
    LLNode* t2 = head2;
    int carry = 0;
    int sum = 0;
    LLNode* dummy = new LLNode(0);
    LLNode* temp = dummy;
    while (t1 != NULL || t2 != NULL || carry != 0){
        sum = 0;
        if (t1 != NULL){
            sum += t1->data;
            t1 = t1->next;
        }
        if (t2 != NULL){
            sum += t2->data;
            t2 = t2->next;
        }
        sum += carry;
        temp->next = new LLNode(sum % 10);
        temp = temp->next;
        carry = sum / 10;
    }
    printList(dummy->next);
}

// ? 0606231842
void rotateListK(LLNode* head,int k){
    printList(head);
    if (head == NULL || head->next == NULL || k == 0){
        printList(head);
        return ;
    }
    int len = 1;
    LLNode* temp = head;
    while (temp->next != NULL){
        len++;
        temp = temp->next;
    }
    k = k % len;
    k = len - k;
    temp->next = head; // tail connected to head
    for (int i = 0;i< k;i++){
        temp = temp->next;
    }
    head = temp->next;
    temp->next = NULL;
    printList(head);
}

// ? 0606231925
struct Node{
    int data;
    Node* next;
    Node* bottom;
    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
Node* flattenList(Node* root){
    if (root == NULL) return NULL;
    if (root->next == NULL) return root;
    root->next = flattenList(root->next);
    Node* t1 = root;
    Node* t2 = root->next;
    Node* dummy = new Node(0);
    Node* temp = dummy;
    while (t1->bottom != NULL && t2->bottom != NULL){
        if (t1->data <= t2->data){
            temp->bottom = t1;
            t1 = t1->bottom;
            temp = temp->bottom;
        }else{
            temp->bottom = t2;
            t2 = t2->bottom;
            temp = temp->bottom;
        }
    }
    if (t1->bottom != NULL){
        temp->bottom = t1->bottom;
    }
    if (t2->bottom != NULL){
        temp->bottom = t2->bottom;
    }
    root->next = NULL;
    return dummy->bottom;
}

// ? 0606232044
void reverseListGrpK(LLNode* head,int k){
    printList(head);
    if (head == NULL || head->next == NULL){
        printList(head);
        return ;
    }
    int len = 0;
    LLNode* temp = head;
    while (temp != NULL){
        temp = temp->next;
        len++;
    }
    LLNode* dummy = new LLNode(0);
    LLNode* t1 = dummy;
    LLNode* t2 = head;
    
    LLNode* curr = head;

    while (len >= k){
        LLNode* prev = NULL;
        LLNode* nex = curr->next;
        // for k steps
        for (int i = 0;i < k;i++){
            // normal reverse list
            curr->next = prev;
            prev = curr;
            curr = nex;
            if (nex != NULL) nex = nex->next;
        }
        t1->next = prev;
        t1 = t2;
        t2 = curr;
        len -= k;
    }
    t1->next = t2;
    printList(dummy->next);
}

// ? 0606232151
LLNode* merge(LLNode* head1,LLNode* head2){
    LLNode* dummy = new LLNode(0);
    LLNode* temp = dummy;
    while (head1 != NULL && head2 != NULL){
        if (head1->data <= head2->data){
            temp->next = head1;
            head1 = head1->next;
        }else{
            temp->next = head2;
            head2 = head2->next;
        }
        temp = temp->next;
    }
    if (head1 != NULL){
        temp->next = head1;
    }
    if (head2 != NULL){
        temp->next = head2;
    }
    return dummy->next;
}
LLNode* sortLinkedList(LLNode* head){
    if (head == NULL || head->next == NULL) return head;
    LLNode* slowPointer = head;
    LLNode* fastPointer = head->next;
    while(fastPointer != NULL && fastPointer->next != NULL){
        slowPointer = slowPointer->next;
        fastPointer = fastPointer->next->next;
    }
    LLNode* secondHalf = slowPointer->next;
    slowPointer->next = NULL;
    LLNode* left = sortLinkedList(head);
    LLNode* right = sortLinkedList(secondHalf);
    // head to slowPointer is one part, slowPointer to end is another part
    return merge(left,right);
}

// ? 0706231112
void segregateOddEven(LLNode* head){
    printList(head);
    LLNode* startOdd = new LLNode(0);
    LLNode* startEven = new LLNode(0);
    LLNode* evenTail = startEven;
    LLNode* oddTail = startOdd;
    // empty odd list, even list
    // we will move tails of list
    LLNode* temp = head;
    while (temp != NULL){
        LLNode* t = temp->next;
        temp->next = NULL; // broke the temp from original list
        if (temp->data % 2 == 0){
            evenTail->next = temp; // added the broken part to evenList
            evenTail = evenTail->next;
        }else{
            oddTail->next = temp;
            oddTail = oddTail->next;
        }
        temp = t;
    }
    // according to question first even nodes -> odd nodes
    // (even tail) -> (odd start)
    evenTail->next = startOdd->next;
    printList(startEven->next);
}

// ? 0706231309
void majorityEle3(vector<int>vec){
    int n = vec.size();
    int minF = (int)(n/3)+1; // the minimum count the ele should be to say it majority element
    int ele1 = INT_MIN;
    int ele2 = INT_MIN;
    int cnt1 = 0;
    int cnt2 = 0;
    for (int i = 0;i<n;i++){
        if (cnt1 == 0 && ele2 != vec[i]){
            cnt1 = 1;
            ele1 = vec[i];
        }else if (cnt2 == 0 && ele1 != vec[i]){
            cnt2 = 1;
            ele2 = vec[i];
        }else if (ele1 == vec[i]) cnt1++;
        else if (ele2 == vec[i]) cnt2++;
        else cnt1--,cnt2--;
    }
    int l1 = 0;
    int l2 = 0;
    for (int i = 0;i < n;i++){
        if (vec[i] == ele1) l1++;
        else if (vec[i] == ele2) l2++;
    }
    printVector(vec);
    cout << "Majority Elements : ";
    if (l1 >= minF) cout << ele1 << " , ";
    if (l2 >= minF) cout << ele2 << endl;
}

// ? 0706231341
void mergeNoSpace(vector<int>v1,vector<int>v2){
    printVector(v1);
    printVector(v2);
    int n = v1.size();
    int m = v2.size();
    int i = n-1;
    int j = 0;
    while (i >= 0 && j < m){
        if (v1[i] > v2[j]){
            int c = v1[i];
            v1[i] = v2[j];
            v2[j] = c;
            i--;
            j++;
        }else{
            break;
        }
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    printVector(v1);
    printVector(v2);
}

// ? 0706231349
void mergeIntervals(vector<vector<int>>intervals){
    printGrid(intervals);
    int n = intervals.size();
    sort(intervals.begin(),intervals.end());
    vector<vector<int>>merged;
    for(int i = 0;i < n;i++){
        if (merged.empty() || intervals[i][0] > merged.back()[1]){
            merged.push_back(intervals[i]);
        }else{
            merged.back()[1] = max(merged.back()[1],intervals[i][1]);
        }
    }
    printGrid(merged);
}

// ? 0706231902
void findMissingRepeat(vector<int>vec){
    // a = repeating , b = missing
    int n = vec.size();
    int s1 = n*(n+1)/2; // s1 = 1 + 2 + 3 + .... a + b + .... + n
    int s2 = 0; // s2 = 1 + 2 + 3 + .... + a + a + ... + n 
    for (int ele : vec) s2 += ele;
    // s2 = (1 + 2 + 3 + ..... + a + b + ... + n) + (a - b)
    // a - b = s2 - s1

    int ss1 = n*(n+1)*(2*n+1)/6; // ss1 = 1^2 + 2^2 + ..... + a^2 + b^2 + ... + n^2
    int ss2 = 0; // ss2 = 1^2 + 2^2 + ... + a^2 + a^2 + ... + n^2
    for (int ele : vec) ss2 += (ele*ele);
    // ss2 = (1^2 + 2^2 + ..... + a^2 + b^2 + ... + n^2) + (a^2 - b^2)
    // (a^2 - b^2) = (ss2 - ss1)
    // (a + b)(a-b) = (ss2 - ss1)
    // a + b = (ss2 - ss1)/(s2 - s1)

    // finally the equations are
    int x = (ss2 - ss1)/(s2-s1); // x = a + b = (ss2 - ss1)/(s2 - s1)
    int y = (s2 - s1); // y = a - b = (s2 - s1)
    
    printVector(vec);
    cout << "repeating a : " << (x+y)/2 << endl;
    cout << "missing b : " << (x-y)/2 << endl;
}

// ? 0706231929
void subArrayWithXOR_K(vector<int>vec,int k){
    // xr = cummulative xor 
    // x = xor in hashMap
    // we can find subArray with xor k in btw xr,x 
    // if (x ^ k) = xr 
    // x = xr ^ k

    // idea is find cummulative xor and store in map
    // for a cummulative xor xr, if we have xr^k in map them diff of index is one of the answer
    int n = vec.size();
    int xr = 0;
    unordered_map<int,int>mp;
    int cnt = 0;
    mp.insert({0,1}); // we got 1 subset with xor = 0
    for (int i = 0;i<n;i++){
        xr = xr ^ vec[i];
        // find xr^k in map
        int t = xr ^ k;
        cnt += mp[t];
        mp[t]++;
    }
    printVector(vec);
    cout << "count : " << cnt << endl;
}

// ? 0706232001
void countInversions(int &ans,vector<int>&vec,int l,int r){
    if (l >= r) return ;
    int m = (l + r)/2;
    countInversions(ans,vec,l,m);
    countInversions(ans,vec,m+1,r);
    
    sort(vec.begin()+l,vec.begin()+m+1); // left part l to m
    sort(vec.begin()+m+1,vec.begin()+r+1); // right part m+1 to r

    int i = l;
    int j = m + 1;
    int cnt = 0;
    for (int i = l;i <= m;i++){
        while (j <= r && vec[i] > vec[j]){
            j++;
        }
        // vec[j] > vec[i]
        // from vec[m+1] to .... vec[j-1] all are less than vec[i]
        cnt += (j - m - 1);
    }

    ans += cnt;
    return ;
}

// ? 0706232149
void countReversePairs(vector<int>&vec,int l,int r,int &ans){
    if (l >= r) return ;
    int m = (l+r)/2;
    countReversePairs(vec,l,m,ans);
    countReversePairs(vec,m+1,r,ans);
    sort(vec.begin()+l,vec.begin()+m+1); // left part is sorted
    sort(vec.begin()+m+1,vec.begin()+r+1); // right part is sorted
    int j = m+1;
    int cnt = 0;
    for (int i = l;i <= m;i++){
        while (j <= r && vec[i] > 2*vec[j]) j++;
        // 2*vec[j] > vec[i]
        // from 2*vec[m+1] to .... 2*vec[j-1] all <  vec[i]
        cnt += (j - m - 1); // from m+1 (start of right arr) to (j-1) 
    }
    ans += cnt;
    return ;
}

// ? 0806230743
void maxProductSubArray(vector<int>vec){
    int n = vec.size();
    // if zero is present in vec, then one of the possible ans is zero, zero is better than -ve product
    bool zeroPresent = false;
    int leftMax = vec[0];
    int prob = 1;
    for (int i = 0;i < n;i++){
        prob *= vec[i];
        if (vec[i] == 0){
            zeroPresent = true;
            prob = 1;
            continue;
        }
        leftMax = max(leftMax,prob);
    }

    int rightMax = vec[0];
    prob = 1;
    for (int i = n-1;i>=0;i--){
        prob *= vec[i];
        if (vec[i] == 0){
            zeroPresent = true;
            prob = 1;
            continue;
        }
        rightMax = max(rightMax,prob);
    }
    printVector(vec);
    if (zeroPresent){
        // most useful for {-2,0,-1}
        cout << "max Product : " << max(max(leftMax,rightMax),0) << endl;
        return ;
    }
    cout << "max Product : " << max(leftMax,rightMax) << endl;
}

// ? 1006231212
void searchK(vector<int>vec,int k){
    printVector(vec);
    int n = vec.size();
    int l = 0;
    int r = n-1;
    while (l <= r){
        int m = l + (r-l)/2;
        if (vec[m] == k){
            cout << "found "<< k << " , at index : " << m << endl;
            return ;
        }else if (vec[m] < k){
            l = m + 1;
        }else{
            r = m - 1;
        }
    }
    cout << k << " - not found" << endl;
}

// ? 1006231242
void floorSearchK(vector<int>vec,int k){
    printVector(vec);
    int n = vec.size();
    int l = 0;
    int r = n-1;
    int ans = -1;
    // if k is present return index of k
    // else return index of ele immediate less of k
    while (l <= r){
        int m = l + (r-l)/2;
        if (vec[m] == k){
            cout << "found floor of  k = " << k << " at index : " << m << endl;
            return ; 
        }else if (vec[m] < k){
            ans = m;
            l = m + 1;
        }else{
            r = m - 1;
        }
    }
    if (ans == -1){
        cout << k << " not found " << endl;
        return ;
    }
    cout << "found floor of  k = " << k << " at index : " << ans << endl;
}

// ? 1006231252
void ceilSearchK(vector<int>vec,int k){
    printVector(vec);
    int n = vec.size();
    int l = 0;
    int r = n-1;
    int ans = n;
    // if k is present return index of k
    // else return index of ele immediate less of k
    while (l <= r){
        int m = l + (r-l)/2;
        if (vec[m] == k){
            cout << "found ceil of  k = " << k << " at index : " << m << endl;
            return ; 
        }else if (vec[m] < k){
            l = m + 1;
        }else{
            ans = m;
            r = m - 1;
        }
    }
    if (ans == -1){
        cout << k << " not found " << endl;
        return ;
    }
    cout << "found ceil of  k = " << k << " at index : " << ans << endl;
}

// ? 1006231845
int lowerBound(vector<int>vec,int x){
    // find the index of ele such that , ele >= x
    int n = vec.size();
    int l = 0;
    int r = n-1;
    int ans = n;
    while (l <= r){
        int m = (l + r)/2;
        if (vec[m] >= x){
            ans = m;
            r = m - 1;
        }else{
            l = m + 1;
        }
    }
    return ans;
}
int upperBound(vector<int>vec,int x){
    // find the index of ele such that , ele > x
    int n = vec.size();
    int l = 0;
    int r = n-1;
    int ans = n;
    while (l <= r){
        int m = (l + r)/2;
        if (vec[m] > x){
            ans = m;
            r = m - 1;
        }else{
            l = m + 1;
        }
    }
    return ans;
}
void firstLastOccurence(vector<int>vec,int x){
    // find the index of first and last occurence of x in vec
    printVector(vec);
    int lb = lowerBound(vec,x);
    int ub = upperBound(vec,x);
    if (lb == vec.size() || vec[lb] != x){
        cout << x << " not found " << endl;
        return ;
    }
    cout << "first occurence : " << lb << endl;
    cout << "Last occurence : " << ub-1 << endl;
}

// ? 1006231903
// same as above code instead return ub - lb

// ? 1106230810
void searchRotatedSortedArray1(vector<int>vec,int k){
    printVector(vec);
    int n = vec.size();
    int l = 0;
    int r = n-1;
    while (l <= r){
        int m = (l + r)/2;
        if (vec[m] == k){
            cout << "found k = " << k << " at index : " << m << endl;
            return ;
        }
        // check if left half is sorted
        if (vec[l] <= vec[m]){
            if (vec[l] <= k && k <= vec[m]){
                // if k is present in left, eliminate right
                r = m - 1;
            }else{
                l = m + 1;
            }
        }else if(vec[r] >= vec[m]){
            // if right part is sorted
            if (vec[m] <= k && k <= vec[r]){
                // if k is present in right, eliminate left
                l = m + 1;
            }else{
                r = m - 1;
            }
        }
    }
    cout << k << " not found" << endl;
}

// ? 1106230835
// same above code

// ? 1106230941
void minEleRotatedArray(vector<int>vec){
    int n = vec.size();
    int l = 0;
    int r = n-1;
    int minEle = INT_MAX;
    while (l <= r){
        int m = (l + r)/2;
        if (vec[l] <= vec[r]){
            minEle = min(minEle,vec[l]);
            break; // fully sorted, no need of more binary steps
        }
        if (vec[l] <= vec[m]){
            // left part sorted, so check with vec[l] which is minimum in left part,
            // now after checking eliminate left part
            minEle = min(vec[l],minEle);
            l = m + 1;
        }else{
            // right part is sorted, so check with vec[m] which is minimum in right part,
            // now after checking eliminate right part
            minEle = min(vec[m],minEle);
            r = m - 1;
        }
    }
    printVector(vec);
    cout << "minimum : " << minEle << endl;
}

// ? 1106231006
void findRotationsCnt(vector<int>vec){
    // find how many times vec is rotated
    int n = vec.size();
    int l = 0;
    int r = n - 1;
    int minEle = INT_MAX;
    int minInd = -1;
    while (l <= r){
        int m = (l + r)/2;
        if (vec[l] <= vec[r]){
            // fully sorted arr from l to r, check with vec[l] and stop
            if (vec[l] < minEle){
                minEle = vec[l];
                minInd = l;
            }
        }
        if (vec[l] <= vec[m]){
            // left part is sorted, vec[l] is min in left part, check and eliminate left
            if (vec[l] < minEle){
                minEle = vec[l];
                minInd = l;
            }
            l = m + 1;
        }else{
            // right part is sorted, vec[m] is min in right part, check and eliminate right
            if (vec[m] < minEle){
                minEle = vec[m];
                minInd = m;
            }
            r = m - 1;
        }
    }
    printVector(vec);
    cout << "vector is rotated : " << minInd << " times " << endl;
}

// ? 1106231133
void searchSortedMatrix(vector<vector<int>>grid,int k){
    printGrid(grid);
    int r = grid.size();
    int c = grid[0].size();
    int i = 0;
    int j = c - 1;
    // start searching from i,j -> top right corner
    while(i >= 0 && j >= 0 && i < r && j < c){
        if (grid[i][j] == k){
            cout << "found k = " << k << " at r = " << i << " ,c = " << j << endl;
            return ;
        }
        if (k > grid[i][j]){
            i++;
        }else{
            j--;
        }
    }
    cout << " k = " << k << " not found " << endl;
}

// ? 1106231343
void peakElement2(vector<vector<int>>grid){
    int r = grid.size();
    int c = grid[0].size();
    printGrid(grid);
    int left = 0;
    int right = c-1; // start from 1st row
    while (left <= right){
        int mid = left + (right - left)/2;

        // search along mid column for maxElement
        int maxEle = INT_MIN;
        int maxRow = -1;
        for (int i = 0;i < r;i++){
            if (grid[i][mid] > maxEle){
                maxEle = grid[i][mid];
                maxRow = i;
            }
        }

        // search for neighbours (left, right) as maxEle is max in its column, 
        int leftNeighbour = INT_MIN;
        if (mid-1 >= 0) leftNeighbour = grid[maxRow][mid-1];

        int rightNeighbour = INT_MIN;
        if (mid + 1 < c) rightNeighbour = grid[maxRow][mid+1];

        if (grid[maxRow][mid] > leftNeighbour && grid[maxRow][mid] > rightNeighbour){
            cout << "peak element at : " << maxRow << " , " << mid << endl;
            return ;
        }else if (leftNeighbour > grid[maxRow][mid]){
            // eliminate right 
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }

    cout << "no peak element" << endl;
}

// ? 1106231759
int countLessthanEqualK(vector<int>grid,int k,int l,int r){
    // cnt elements less than equal to k
    while(l <= r){
        int m = (l + r)>>1;
        if (grid[m] <= k){
            l = m + 1;
        }else{
            r = m - 1;
        }
    }
    // at last l will be the lower bound of k
    return l;
}
void medianGrid(vector<vector<int>>grid){
    printGrid(grid);
    int r = grid.size();
    int c = grid[0].size();
    int low = 0;
    int high = 1e9;
    while (low <= high){
        int mid = (low + high)>>1; // divide by 2
        int cnt = 0;
        for (int i = 0;i<r;i++){
            cnt += countLessthanEqualK(grid[i],mid,0,c-1);
        }
        if (cnt <= (r*c)/2){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    cout << "median : " << low << endl;
}

// ? 1106231858
bool canKokoEat(vector<int>vec,int s,int h){
    int cnt = 0;
    for (int i = 0;i < vec.size();i++){
        if (vec[i] <= s){
            cnt++;
        }else if (vec[i] % s == 0){
            cnt += (vec[i] / s);
        }else{
            cnt += ((vec[i] - vec[i]%s)/s + 1);
        }
    }
    if (cnt <= h) return true;
    return false;
}
void minKokoSpeed(vector<int>vec,int h){
    // set the eating speed of koko such thar it can eat all bananas in h hours.
    int n = vec.size();
    int high = INT_MIN;
    int low = 0;
    for (auto it : vec){
        high = max(high,it);
    }
    int ans = INT_MAX;
    while (low <= high){
        int mid = (low + high)/2;
        if (canKokoEat(vec,mid,h)){
            // if koko can eat all bananas with speed mid, try for less speed
            ans = min(ans,mid);
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    printVector(vec);
    cout << "Min Speed : " << ans << endl;
}

// ? 1106231928
bool canShip(vector<int>&weights,int c,int d){
    int cnt = 1;
    int wt = 0;
    for (int i = 0;i < weights.size();i++){
        if (weights[i] > c || wt > c) return false;
        if (wt + weights[i] <= c){
            wt += weights[i];
        }else{
            wt = weights[i];
            cnt++;
        }
    }
    if (cnt <= d) return true;
    return false;
}
void capacityShip(vector<int>weights,int d){
    int low = 0;
    int high = 1e9;
    int ans = INT_MAX;
    while (low <= high){
        int mid = (low + high) >> 1;
        if (canShip(weights,mid,d)){
            ans = min(ans,mid);
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    printVector(weights);
    cout << "capacity : " << ans << endl;
}

// ? 1206230922
void median2sortedArr(vector<int>v1,vector<int>v2){

    if (v2.size() < v1.size()){
        median2sortedArr(v2,v1);
        return ;
    }

    printVector(v1);
    printVector(v2);

    int n1 = v1.size();
    int n2 = v2.size();

    int low = 0;
    int high = n1;     
    // priority is v1, means select x elements from v1 remaining from v2
    // (n1+n2+1)/2 on each side

    while (low <= high){
        int cut1 = (low + high)>>1;
        int cut2 = (n1+n2+1)/2 - cut1;

        int l1 = (cut1 == 0) ? INT_MIN : v1[cut1-1]; 
        int l2 = (cut2 == 0) ? INT_MIN : v2[cut2-1];
        
        int r1 = (cut1 == n1) ? INT_MAX : v1[cut1]; 
        int r2 = (cut2 == n2) ? INT_MAX : v2[cut2];
        
        if (l1 <= r2 && l2 <= r1){
            if ((n1+n2)%2 == 0){
                cout << "median :" << ((max(l1,l2) + min(r1,r2))/2.0) << endl;
                return ;
            }else{
                cout << "median : " << max(l1,l2) << endl;
                return ;
            }
        }else if (l1 > r2){
            // decrease l1, increase r2
            high = cut1- 1;
        }else{
            low = cut1 + 1;
        }
    }
    cout << "median : 0" << endl;
}

// ? 1206231030
bool isPossibleCows(vector<int>a, int cows, int minDist) {
    int n = a.size();
    int cntCows = 1;
    int lastPlacedCow = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] - lastPlacedCow >= minDist) {
            cntCows++;
            lastPlacedCow = a[i];
        }
    }
    if (cntCows >= cows) return true;
    return false;
}
void aggresiveCows(vector<int>a,int k) {
    sort(a.begin(), a.end());
    int n = a.size();
    int low = 1, high = a[n - 1] - a[0];
    int ans = INT_MIN;
    while (low <= high) {
        int mid = (low + high) >> 1;

        if (isPossibleCows(a, k, mid)) {
            ans = max(ans,mid);
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    printVector(a);
    cout << "you can keep cows at min distance : " << ans << endl;
}

// ? 1206231040
bool isPossibleBooks(vector<int>&pages,int n,int students,int mid){
    // each student show get at most mid count pages
    int cnt = 1;
    int pagesCnt = 0;
    for (int i = 0;i < n;i++){
        if (pages[i] > mid) return false;
        if ((pagesCnt + pages[i]) <= mid){
            pagesCnt += pages[i];
        }else{
            pagesCnt = pages[i];
            cnt++;
        }
    }
    if (cnt <= students) return true;
    return false;
}
void allocateBooks(vector<int>pages,int students){
    int n = pages.size();
    if (n < students){

    }
    int ans = INT_MAX;
    int low = 0;
    int high = 0;
    for (auto it : pages) high += it;
    
    while (low <= high){
        int mid = (low + high) >> 1;
        if (isPossibleBooks(pages,n,students,mid)){
            ans = min(ans,mid);
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    printVector(pages);
    cout << "min pages to student : " << ans << endl;
}

// ? 1206231206
void removeOuterBrackets(string str){
    int len = str.length();
    stack<char>st;
    string ans = ""; // string after removing outer brackets from str
    int size = 0;
    int startIndex = 0;
    int endIndex = 1;
    for (int i = 0;i < len;i++){
        if (str[i] == '('){
            st.push(str[i]);
            size++;
        }else if (str[i] == ')' && st.top() == '('){
            st.pop();
            size--;
        }
        if (size == 0){
            endIndex = i;
            ans += str.substr(startIndex+1,endIndex-startIndex-1);
            startIndex = i + 1;
        }
    }
    cout << str << endl;
    cout << ans << endl;
}

// ? 1206231223
void reverseWords(string S) { 
    string ans = ""; // words reversed
    int startIndex = 0;
    for (int i = 0;i < S.length();i++){
        if (S[i] == '.'){
            ans = '.' + ( S.substr(startIndex,i-startIndex) ) + ans; 
            startIndex = i+1;
        }
        if (i == S.length()-1){
            ans = ( S.substr(startIndex,i-startIndex+1) ) + ans;
        }
    }
    cout << S << endl;
    cout << ans << endl;
} 

// ? 1206231227
void maxOddString(string s) {
    cout << s << endl;
    for (int i = s.length()-1;i >= 0;i--){
        int x = s[i]-'0';
        if (x%2 != 0){
            cout << s.substr(0,i+1) << endl;
            return ;
        }
    }
    cout << " . " << endl;
}

// ? 1206231729
void commonPrefixString(vector<string>vec){
    int n = vec.size();
    
    cout << endl;
    for (auto it:vec) cout << it << " ";
    cout << endl;

    sort(vec.begin(),vec.end()); // dictionary order
    
    // now find the string with short length
    int minL = INT_MAX;
    int ind = 0;
    for (int i = 0;i < n;i++){
        int l = vec[i].length();
        if (l < minL){
            minL = l;
            ind = i;
        }
    }

    // check first string and last string in given vector upto minL length
    string commonPrefix = "";
    for (int i = 0;i<minL;i++){
        if (vec[0][i] == vec[n-1][i]){
            commonPrefix += vec[0][i];
        }else{
            break;
        }
    }
    cout << "common prefix : " << commonPrefix << endl;
}

// ? 1206231740
void checkIsomorphicStrings(string str1,string str2){
    unordered_map<char,char>mp;
    if (str1.length() != str2.length()){
        cout << "isomorphic"<<endl;
        return ;
    }
    if (str1.length() == 0 || str1.length() == 1){
        cout << "isomorphic"<<endl;
        return ;
    }
    cout << str1 << " - " << str2 << " ";
    for (int i = 0;i < str1.length();i++){
        char ch1 = str1[i];
        char ch2 = str2[i];
        
        if (mp.count(ch1) && mp[ch1] != ch2){
            cout << "not isomorphic"<<endl;
            return ;
        }
        
        for (const auto& pair : mp) {
            if (pair.second == ch2 && pair.first != ch1) {
                cout << "not isomorphic"<<endl;
                return ;
            }
        }
        mp[ch1] = ch2;
    }
    cout << "isomorphic"<<endl;
    return ;
}

// ? 1206231749
void areStringsRotations(string s1,string s2){
    cout << s1 << " - " << s2 << " "; 
    if (s1.length() != s2.length()){
        cout << "not rotation to each other" << endl;
        return ;
    }
    int l1 = s1.length();
    for (int i = 0;i<l1;i++){
        string cut = s1.substr(0,i);
        string newstr = s1.substr(i,l1-i) + cut;
        if (newstr == s2){
            cout << "rotation to each other" << endl;
            return ;
        }
    }
    cout << "not rotation to each other" << endl;
}

// ? 1206231801
void KthMissingElement(vector<int>arr, int k){
    printVector(arr);
    int n = arr.size();
    int count = 0;
    for (int i = 0; i < n-1;i++){
        if (arr[i+1]-arr[i] != 1){
            if (arr[i+1] - arr[i] > k-count){
                cout << "missing : " << arr[i] + k - count << endl;
                return ;
            }
            count += (arr[i+1] - arr[i]-1); 
            if (count == k){
                cout << "missing : " << arr[i] + 1 << endl;
                return ;
            }
        }
    }
    cout << "no kth missing number" << endl;
    return ;
}

// ? 1206231801
void maxDepthBrackets(string word) {
    stack<char>st;
    int size = 0;
    int l = word.length();
    int maxD = 0;
    for (int i = 0;i < l;i++){
        if (word[i] == '('){
            st.push(word[i]);
            size++;
        }else if (word[i] == ')' && st.top() == '('){
            st.pop();
            size--;
        }
        maxD = max(maxD,size);
    }
    cout << word << endl;
    cout << "max Depth : " << maxD << endl;
}

// ? 1206231850
void romanToDecimal(string word) {
    unordered_map<char,int>mp;
    mp.insert({'I',1});
    mp.insert({'V',5});
    mp.insert({'X',10});
    mp.insert({'L',50});
    mp.insert({'C',100});
    mp.insert({'D',500});
    mp.insert({'M',1000});
    
    int result = 0;
    int n = word.length();

    for (int i = 0; i < n; i++) {
        int currentValue = mp[word[i]];
        int nextValue = (i + 1 < n) ? mp[word[i + 1]] : 0;

        if (currentValue < nextValue) {
            result -= currentValue;
        } else {
            result += currentValue;
        }
    }
    
    cout << word << " - " << result << endl;
}

// ? 1206231856
void atoiFun(string str){
    int result = 0;
    int startIndex = 0;
    if (str[0] == '-'){
        startIndex = 1;
    }
    for (int i = startIndex;i < str.length();i++){
        int c = str[i] - '0';
        if (c < 0 || c > 9){
            cout << str << " is not number" << endl;
            return ;
        }
        result = result*10 + c;
    }
    if (startIndex == 1) result *= -1;
    cout << str << " - " << result << endl;
}

// ? 1206231939
bool isGoodNumber(int n,int d){
    int cumSum = 0;
    if (n%10 == 0 && d == 0) return false;
    if (n%10 == 0 && d != 0) n /= 10;
    while (n > 0) {
        int lastDigit = n % 10;
        if (lastDigit == d) {
            return false;
        }
        if (lastDigit <= cumSum) {
            return false;
        }
        cumSum += lastDigit;
        n /= 10;
    }
    return true;
}
void goodnumbers(int l,int r,int d){
    vector<int>ans; // all good numbers in btw l-r
    for (int i = l;i<=r;i++){
        if(isGoodNumber(i,d)){
            ans.push_back(i);
        }
    }
    cout << l << " : " << r << endl;
    printVector(ans);
}

// ? 1206231954
void subStringsNO1(string s,int n,int i,char last){
    if (i == n){
        cout << s << " ";
        return ;
    }
    if (last == '1'){
        subStringsNO1(s+'0',n,i+1,'0');
        return ;
    }else{
        subStringsNO1(s+'1',n,i+1,'1');
        subStringsNO1(s+'0',n,i+1,'0');
    }
    return ;
}

// ? 1206232002
void generateBrackets(string s,int n,int openBrackets,int closedBrackets){
    if (openBrackets == closedBrackets && openBrackets == n){
        cout << s << " ";
        return ;
    }
    if (openBrackets < n){
        generateBrackets(s+'(',n,openBrackets+1,closedBrackets);
    }
    if (openBrackets > closedBrackets){
        generateBrackets(s+')',n,openBrackets,closedBrackets+1);
    }
}

// ? 1206232009
void powerSetStr(vector<string>&ans,int n,string str,int i,string s){
    if (i == n){
        ans.push_back(s);
        return ;
    }
    powerSetStr(ans,n,str,i+1,s+str[i]);
    powerSetStr(ans,n,str,i+1,s);
    return ;
}

// ? 1206232030
void subSum(vector<int>&ans,int index,int n,vector<int>arr,int sum){
    if (index == n){
        ans.push_back(sum);
        return ;
    }
    subSum(ans,index+1,n,arr,sum+arr[index]);
    subSum(ans,index+1,n,arr,sum);
}
void subsetSums(vector<int> arr, int N)
{
    vector<int>ans;
    subSum(ans,0,N,arr,0);
    sort(ans.begin(),ans.end());
    printVector(ans);
}

// ? 1306230925
void removeDuplicates1(vector<int>&vec){
    int slowPointer = 0;
    int fastPointer = 1;
    int n = vec.size();
    while (fastPointer < n){
        if (vec[slowPointer] == vec[fastPointer]){
            fastPointer++;
        }else{
            vec[slowPointer+1] = vec[fastPointer];
            slowPointer++;
            fastPointer++;
        }
    }
    while (slowPointer < n-1){
        slowPointer++;
        vec.pop_back();
    }
}
void combination1(vector<vector<int>>&ans,vector<int>vec,int n,int i,int target,vector<int>comb){
    if (i == n){
        if (target == 0){
            ans.push_back(comb);
        }
        return ;
    }
    if (vec[i] <= target){
        comb.push_back(vec[i]);
        combination1(ans,vec,n,i,target-vec[i],comb);
        comb.pop_back();
    }
    combination1(ans,vec,n,i+1,target,comb);
}
void combinationSum1(vector<int>vec,int target){
    vector<vector<int>>ans;
    sort(vec.begin(),vec.end());
    removeDuplicates1(vec);
    combination1(ans,vec,vec.size(),0,target,{});
    for (auto it: ans){
        printVector(it);
    }
}

// ? 1306230946
void combination2(vector<vector<int>>&ans,vector<int>vec,int n,int index,int target,vector<int>comb){
    if (target == 0){
        ans.push_back(comb);
        return ;
    }
    for (int i = index;i < n;i++){
        if (i > index && vec[i] == vec[i-1]) continue;
        if (vec[i] > target) break;
        comb.push_back(vec[i]);
        combination2(ans,vec,n,i+1,target-vec[i],comb);
        comb.pop_back();
    }
}
void combinationSum2(vector<int>vec,int target){
    vector<vector<int>>ans;
    sort(vec.begin(),vec.end());
    combination2(ans,vec,vec.size(),0,target,{});
    for (auto it: ans){
        printVector(it);
    }
}

// ? 1306231034
void uniqueSubSets(vector<vector<int>>&ans,vector<int>&arr,vector<int>vec,int index,int n){
    ans.push_back(arr);
    if (index == n) return ;
    for (int i = index;i<n;i++){
        if (i > index && vec[i-1] == vec[i]) continue ;
        arr.push_back(vec[i]);
        uniqueSubSets(ans,arr,vec,i+1,n);
        arr.pop_back();
    }
    return ;
}
void printUniqueSubsets(vector<int> nums) {
    vector<vector<int>>ans;
    vector<int>arr;
    sort(nums.begin(),nums.end());
    uniqueSubSets(ans,arr,nums,0,nums.size());
    for (auto it: ans){
        printVector(it);
    }
}

// ? 1306231102
void combination3(vector<vector<int>>&ans,vector<int>vec,int n,int index,int k,int target,vector<int>comb){
    if (target < 0) return ;
    if (target == 0 && k == 0){
        ans.push_back(comb);
        return ;
    }
    for (int i = index;i < n;i++){
        comb.push_back(vec[i]);
        combination3(ans,vec,n,i+1,k-1,target-vec[i],comb);
        comb.pop_back();
    }
}
void combinationSum3(int target,int k){
    vector<vector<int>>ans;
    combination3(ans,{1,2,3,4,5,6,7,8,9},9,0,k,target,{});
    for (auto it: ans){
        printVector(it);
    }
}

// ? 1306231237
void allWordsPhone(vector<string>&ans,vector<string>words,int n,string str,int index){
    if (index == n){
        ans.push_back(str);
        return ;
    }
    for (int i = 0;i < words[index].length();i++){
        allWordsPhone(ans,words,n,str+words[index][i],index+1);
    }
}
void phoneWords(vector<int>nums){
    unordered_map<int,string>mp;
    mp.insert({2,"abc"});
    mp.insert({3,"def"});
    mp.insert({4,"ghi"});
    mp.insert({5,"jkl"});
    mp.insert({6,"mno"});
    mp.insert({7,"pqrs"});
    mp.insert({8,"tuv"});
    mp.insert({9,"wxyz"});
    vector<string>words;
    int n = nums.size();
    for (int i = 0;i<n;i++){
        words.push_back(mp[nums[i]]);
    }
    vector<string>ans;
    allWordsPhone(ans,words,n,"",0);
    cout << endl;
    for (auto it : ans) cout << it << " ";
    cout << endl;
}

// ? 1306231706
void sortCharFreq(string str){
    cout << str << endl;
    if (str.length() == 0 || str.length() == 1){
        return ;
    }
    vector<pair<int,char>>hash('z'+1,{0,0}); // {freq ,char}
    for (char c : str){
        hash[c] = {hash[c].first+1,c};
    }
    sort(hash.begin(),hash.end());
    string res = "";
    for (auto pair : hash){
        res = string(pair.first,pair.second)+res;
    }
    cout << res << endl;
}

// ? 1406230842
void longestPalindrome(string str){
    cout << str << endl;
    int n = str.length();
    int maxLen = 0;
    string res = "";
    for (int i = 0;i < n;i++){

        // check how much length palindrome we can get by keep str[i] at center
        int l = i;
        int r = i;
        while (l >= 0 && r < n && str[l] == str[r]){
            l--;
            r++;
        } // we got a palindrom from str[l+1] to str[r-1] of length (r-l-1)
        if ((r-l-1) > maxLen){
            maxLen = (r-l-1);
            res = str.substr((l+1),r-l-1);
        }

        // check how much length palindrome we can get by keep str[i], str[i+1] at center
        l = i;
        r = i+1;
        while (l >= 0 && r < n && str[l] == str[r]){
            l--;
            r++;
        } // we got a palindrom from str[l+1] to str[r-1] of length (r-l-1)
        if ((r-l-1) > maxLen){
            maxLen = (r-l-1);
            res = str.substr((l+1),r-l-1);
        }
    }
    cout << "longest Palindrome : " << res << endl;
}

// ? 1406231054
int subStrAtmostKchars(string str,int k){
    // returns no of substr with atmost k unique chars
    int n = str.length();
    int l = 0;
    int count = 0;
    int distinctChar = 0;
    vector<int>mp(26,0);
    for (int r = 0;r < n;r++){
        if (mp[str[r]-'a'] == 0){
            // new char
            distinctChar++;
        }
        mp[str[r]-'a']++;
        while (distinctChar > k){
            mp[str[l]-'a']--;
            if (mp[str[l]-'a'] == 0){
                distinctChar--;
            }
            l++;
        }
        count += (r-l+1);
    }
    return count;
}
void substrExactK(string str,int k){
    // no of substr with exactly k distinct chars
    cout << str << endl;
    cout << (subStrAtmostKchars(str,k) - subStrAtmostKchars(str,k-1)) << endl;
}

// ? 1406231136
int diffMinMax(vector<int>vec){
    int mini = INT_MAX;
    int maxi = INT_MIN;
    for (auto it : vec){
        if (it >= 1){
            // zero freq elements are not considered
            maxi = max(maxi,it);
            mini = min(mini,it);
        }
    }
    if (maxi - mini <= 0) return 0;
    return (maxi - mini);
}
void sumBeauty(string str){
    int n = str.size();
    int sum = 0;
    for (int i = 0;i < n;i++){
        vector<int>mp(26,0);
        for (int j = i;j < n;j++){
            mp[str[j]-'a']++;
            sum += diffMinMax(mp);
        }
    }
    cout << str << " -> sum of beauty = " << sum << endl;
}

// ? 1406231714
bool WordExist(vector<vector<char>>&board,int &r,int &c,string &word,int &n,int index,pair<int,int>cord){
    if (index == n) return true;
    if (index == 0){
        // search for 1st char
        for (int i = 0;i < r;i++){
            for (int j = 0;j < c;j++){
                if (board[i][j] == word[index]){
                    char x = board[i][j];
                    board[i][j] = '.';
                    if (WordExist(board,r,c,word,n,index+1,{i,j})){
                        return true;
                    }
                    board[i][j] = x;
                }
            }
        }
        return false;
    }
    // search all four directions around parent 
    vector<pair<int,int>>dir = {{1,0},{0,1},{-1,0},{0,-1}};
    for (int i = 0;i < 4;i++){
        if (cord.first + dir[i].first >= 0 && cord.first + dir[i].first < r){
            if (cord.second + dir[i].second >= 0 && cord.second + dir[i].second < c){
                if (board[cord.first + dir[i].first][cord.second + dir[i].second] == word[index]){
                    char x = board[cord.first + dir[i].first][cord.second + dir[i].second];
                    board[cord.first + dir[i].first][cord.second + dir[i].second] = '.';
                    if (WordExist(board,r,c,word,n,index+1,{cord.first + dir[i].first,cord.second + dir[i].second})){
                        return true;
                    }
                    board[cord.first + dir[i].first][cord.second + dir[i].second] = x;
                }
                }
        }
    }
    // if required index char not found then return false;
    return false;
}
void isWordExist(vector<vector<char>>board, string word) {
    int n = word.length();
    int r = board.size();
    int c = board[0].size();
    if (n == 0){
        cout << " , found" << endl;
    }
    for (auto it : board){
        for (auto i : it) cout << i << " ";
        cout << endl;
    }
    bool res = WordExist(board,r,c,word,n,0,{-1,-1});
    string ans = (res == 0) ? "not found" : "found";
    cout << word << " - " << ans << endl;
}

// ? 1406231733
void ratPath(vector<string>&ans,vector<vector<int>>&maze,int r,int c,pair<int,int>cord,string path){
    if (cord.first == r-1 && cord.second == c-1){
        ans.push_back(path);
        return ;
    }
    vector<pair<int,int>>dir = {{1,0},{0,1},{-1,0},{0,-1}};
    vector<char>d = {'D','R','U','L'};
    for (int i = 0;i<4;i++){
        int nx = cord.first + dir[i].first;
        int ny = cord.second + dir[i].second;
        if (nx >= 0 && nx < r){
            if (ny >= 0 && ny < c){
                if (maze[nx][ny] == 1){
                    maze[cord.first][cord.second] = 0; // to avoid cycling in same path, we will mark the travelled path 0
                    ratPath(ans,maze,r,c,{nx,ny},path+d[i]);
                    maze[cord.first][cord.second] = 1;
                }
            }
        }
    }
    return ;
}
void findPathRat(vector<vector<int>>m, int n) {
    if (m[n-1][n-1] == 0 || m[0][0] == 0) return ;
    vector<string>ans;
    ratPath(ans,m,n,n,{0,0},"");
    for (auto it :ans) cout << it << endl;
}

// ? 1406231744
bool isPossible(vector<vector<int>>&board,int row,int col,int x){
    for (int i = 0;i < 9;i++){
        if (board[i][col] == x) return false;
    }
    for (int j = 0;j < 9;j++){
        if (board[row][j] == x) return false;
    }
    int row_l = 3 * (row / 3);
    int col_l = 3* (col / 3);
    for (int i = 0;i < 3;i++){
        for (int j = 0;j< 3;j++){
            if (board[row_l + i][col_l + j] == x) return false;
        }
    }
    return true;
}
bool sudokoSolver(vector<vector<int>>&board){
    for (int r = 0; r < 9;r++){
        for (int c = 0;c < 9;c++){
            if (board[r][c] == 0) {
                for (int i = 1;i<=9;i++){
                    if (isPossible(board,r,c,i)){
                        board[r][c] = i;
                        if (sudokoSolver(board)) return true;
                        else board[r][c] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

// ? 1406231918
bool safeQueen(int N,int r,int c,vector<vector<char>>&board){
    int i = r;
    int j = c;
    while (i >= 0 && j >= 0){
        if (board[i][j] == 'Q') return false;
        i--;
        j--;
    }

    i = r;
    j = c;
    while (j >= 0){
        if (board[i][j] == 'Q') return false;
        j--;
    }

    i = r;
    j = c;
    while (i < N &j >= 0){
        if (board[i][j] == 'Q') return false;
        i++;
        j--;
    }
    return true;
}
void placeQueen(int n,int col,vector<vector<char>>&board){
    if (col == n){
        for(auto r: board){
            for (auto c : r) cout << c << " ";
            cout << endl;
        }
        cout << endl;
        cout << endl;
        return ;
    }
    for (int i = 0;i<n;i++){
        if (safeQueen(n,i,col,board)){
            board[i][col] = 'Q';
            placeQueen(n,col+1,board);
            board[i][col] = '.';
        }
    }
}
void nQueen(int n) {
    vector<vector<char>>board(n,vector<char>(n,'.'));
    placeQueen(n,0,board);
}

// ? 1506231033
void insertAtBottom(stack<int>&st, int x){
    if (st.empty()){
        st.push(x);
        return ;
    }
    int t = st.top();
    st.pop();
    insertAtBottom(st,x);
    st.push(t);
}

// ? 1506231042
void insertAtBottom1(stack<int>&st, int x){
    if (st.empty()){
        st.push(x);
        return ;
    }
    int t = st.top();
    st.pop();
    insertAtBottom1(st,x);
    st.push(t);
}
void reverseStack(stack<int>&st){
    if (st.empty()){
        return ;
    }
    int t = st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom1(st,t);
}

// ? 1506231110
void insertSortStack(stack<int>&st,int x){
    if (st.empty()){
        st.push(x);
        return ;
    }
    if (st.top() <= x){
        st.push(x);
        return ;
    }
    int t = st.top();
    st.pop();
    insertSortStack(st,x);
    st.push(t);
}
void sortStack(stack<int>&st){
    if (st.empty()){
        return ;
    }
    int t = st.top();
    st.pop();
    sortStack(st);
    insertSortStack(st,t);
}

// ? 1506231616
void maxChildrenCookie(vector<int>greed, vector<int>sz) {
    int N = greed.size();
    int M = sz.size();

    sort(greed.begin(),greed.end());
    sort(sz.begin(),sz.end());
    int cnt = 0;
    
    // first we should assign big size cookie to child with more greed

    int child = N-1;
    int cokkie = M-1;
    
    while (child >= 0 && cokkie >= 0){
        if (sz[cokkie] >= greed[child]){
            cnt++;
            child--;
            cokkie--;
        }else{
            child--;
        }
    }
    cout << "max children we can satisfy : " << cnt << endl;
}

// ? 1506231622
void minCoinsN(int N){
    vector<int>coins = {1,2,5,10,20,50,100,200,500,2000};
    int c = coins.size()-1;
    vector<int>vec;
    while (N > 0 && c >= 0){
        if (N >= coins[c]){
            N -= coins[c];
            vec.push_back(coins[c]);
        }else{
            c--;
        }
    }
    printVector(vec);
}

// ? 1506231709
void lemonadeChange(vector<int>bills) {
    printVector(bills);
    int cnt_5 = 0;
    int cnt_10 = 0;
    for (auto bill: bills){
        if (bill == 5){
            cnt_5++;
        }else if (bill == 10){
            if (cnt_5 == 0){ 
                cout << "change not available" << endl;
                return ;
            }
            cnt_5--;
            cnt_10++;
        }else{
            if (cnt_10 >= 1 && cnt_5 >= 1){
                cnt_10--;
                cnt_5--;
                continue;
            }
            if (cnt_5 >= 3){
                cnt_5 -= 3;
                continue;
            }
            cout << "change not available" << endl;
            return ;
        }
    }
    cout << "all bills done" << endl;
    return ;
}

// ? 1506231716
void bracketsCheck(string exp){
    cout << exp << " ";
    stack<char> st;

    for (char c : exp) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        } else if (c == ')' || c == '}' || c == ']') {
            if (st.empty()) {
                cout << "unbalanced" << endl;
                return ;  // Found a closing bracket without a matching opening bracket
            }
            
            char top = st.top();
            st.pop();
            
            if ((c == ')' && top != '(') || (c == '}' && top != '{') || (c == ']' && top != '[')) {
                cout << "unbalanced" << endl;
                return ;  // Found a mismatched opening and closing bracket
            }
        }
    }
    cout << "balanced" << endl;
}

// ? 1506231738
bool sortCompare(pair<int,int>item1,pair<int,int>item2){
    double r1 = (double) item1.first / (double) item1.second;
    double r2 = (double) item2.first / (double) item2.second;
    return r1 > r2;
}
void fractionalKnapsack(int maxW, vector<pair<int,int>>items) {
    // items = {price,weight}
    // maxW = maxWeightAvailable
    sort(items.begin(),items.end());
    for (auto item : items){
        cout << "p : " << item.first << " , w : " << item.second << endl;
    }
    int currV = 0;
    int currW = 0;
    for (auto item : items){
        if (item.second + currW <= maxW){
            currW += item.second;
            currV += item.first;
        }else{
            currV += (item.first/item.second)*(maxW - currW);
            break;
        }
    }
    cout << "max val : " << currV << endl;
}

// ? 1506231841
bool compareMeet(pair<int,int>meet1,pair<int,int>meet2){
    // comparing based on ending time
    return (meet1.second < meet2.second);
}
void nMeetings(vector<int>start,vector<int>end){
    printVector(start);
    printVector(end);
    int n = start.size();
    vector<pair<int,int>>vec;
    for(int i = 0;i < n;i++){
        vec.push_back({start[i],end[i]});
    }
    sort(vec.begin(),vec.end(),compareMeet);
    int cnt = 0;
    int startTime = -1;
    for (int i = 0;i < n;i++){
        if (vec[i].first > startTime){
            startTime = vec[i].second;
            cnt++;
        }
    }
    cout << "max meetings : " << cnt << endl;
}

// ? 1506231934
void minPlatforms(vector<int>start,vector<int>end){
    printVector(start);
    printVector(end);

    int n = start.size();
    sort(start.begin(),start.end());
    sort(end.begin(),end.end());
    int currPlatforms = 1;
    int maxPlatforms = 1;
    
    int i = 1;
    int j = 0;

    while(i<n && j<n){
        if(start[i] <= end[j]){
            currPlatforms++;  //one more platform needed
            i++;
        }
        else{
            currPlatforms--; //one platform can be reduced
            j++;
        }
        maxPlatforms = max(maxPlatforms,currPlatforms); //updating the value with the current maximum
    }

    cout << "min platforms req : " << maxPlatforms << endl;
}

// ? 1506232023
bool sortJobs(vector<int>j1,vector<int>j2){
    return (j1[2] > j2[2]); // sorting based on job profit
}
void jobSchedule(vector<vector<int>>jobs){
    // jobs = {job.id , job.deadline, job.profit}
    printGrid(jobs);
    int n = jobs.size();
    sort(jobs.begin(),jobs.end(),sortJobs);
    
    int maxDeadline = INT_MIN;
    for (auto j : jobs){
        maxDeadline = max(maxDeadline,j[1]);
    }
    int cntJobs = 0;
    int cntProfit = 0;
    vector<int>vec(maxDeadline+1,-1); // job.id are given in 1-based index
    for (int i = 0;i < n;i++){
        vector<int>job = jobs[i];
        int j = job[1]; // deadline
        while (j >= 1){
            if (vec[j] == -1){
                vec[j] = job[0];
                cntJobs++;
                cntProfit += job[2];
                break;
            }
            j--;
        }
    }
    cout << "jobs : " << cntJobs << " , profit : " << cntProfit << endl;
}

// ? 1606231130
void preOrderTraversal(vector<int>&ans,TNode* root){
    if (root == NULL) return ;
    ans.push_back(root->data);
    preOrderTraversal(ans,root->left);
    preOrderTraversal(ans,root->right);
}

// ? 1606231142
void postOrderTraversal(vector<int>&ans,TNode* root){
    if (root == NULL) return ;
    postOrderTraversal(ans,root->left);
    postOrderTraversal(ans,root->right);
    ans.push_back(root->data);
}

// ? 1606231150
void inOrderTraversal(vector<int>&ans,TNode* root){
    if (root == NULL) return ;
    inOrderTraversal(ans,root->left);
    ans.push_back(root->data);
    inOrderTraversal(ans,root->right);
}

// ? 1606231232
void levelOrderTraversal(TNode* root){
    vector<int>ans;
    queue<TNode*>q;
    if (root == NULL) return ;
    q.push(root);
    while (q.empty() == false){
        TNode* f = q.front();
        ans.push_back(f->data);
        q.pop();
        if (f->left != NULL) q.push(f->left);
        if (f->right != NULL) q.push(f->right);
    }
    printVector(ans);
}
void levelOrderTraversal1(TNode* root){
    cout << endl;
    cout << endl;
    vector<vector<int>>ans;
    queue<TNode*>q;
    if (root == NULL) return ;
    q.push(root);
    while (q.empty() == false){
        int s = q.size();
        vector<int>level;
        for (int i = 0;i < s;i++){
            TNode* f = q.front();
            q.pop();
            level.push_back(f->data);
            if (f->left != NULL) q.push(f->left);
            if (f->right != NULL) q.push(f->right);
        }
        ans.push_back(level);
    }
    for (auto level : ans){
        cout << endl;
        for (auto it : level) cout << it << " ";
    }
    cout << endl;
    cout << endl;
}

// ? 1606231857
void iterativePreOrderTraversal(TNode* root){
    vector<int>ans;
    stack<TNode*>st;
    if (root == NULL) return ;
    st.push(root);
    while(st.empty() == false){
        TNode* f = st.top();
        st.pop();
        ans.push_back(f->data);
        if (f->right != NULL) st.push(f->right);
        if (f->left != NULL) st.push(f->left);
    }
    printVector(ans);
}

// ? 1606231955
void iterativeInOrderTraversal(TNode* root){
    vector<int>ans;
    stack<TNode*>st;
    if (root == NULL) return ;
    TNode* temp = root;
    while (true){
        if (temp != NULL){
            st.push(temp);
            temp = temp->left;
        }else{
            if (st.empty() == true) break;
            temp = st.top(); 
            st.pop();
            ans.push_back(temp->data);
            temp = temp->right;
        }
    }
    printVector(ans);
}

// ? 1706230831
void iterativePostOrderTraversal(TNode* root){
    stack<TNode*>st1;
    vector<int>ans;
    if (root == NULL) return ;
    st1.push(root);
    while (st1.empty() == false){
        TNode* f = st1.top();
        st1.pop();
        ans.push_back(f->data);
        if (f->left != NULL) st1.push(f->left);
        if (f->right != NULL) st1.push(f->right);
    }
    reverse(ans.begin(),ans.end());
    printVector(ans);
}

// ? 1706230937
void allTraversals(TNode* root){
    stack<pair<TNode*,int>>st;
    if (root == NULL) return ;
    st.push({root,1});
    // 1 -> preOrder, 2 -> inOrder, 3 -> postOrder
    vector<int>preOrder;
    vector<int>inOrder;
    vector<int>postOrder;
    while (st.empty() == false){
        pair<TNode*, int> p = st.top();
        st.pop();
        if (p.second == 1) {
            preOrder.push_back(p.first->data);
            p.second++;
            st.push(p);
            if (p.first->left != NULL) st.push({p.first->left, 1});
        }
        else if (p.second == 2) {
            inOrder.push_back(p.first->data);
            p.second++;
            st.push(p);
            if (p.first->right != NULL) st.push({p.first->right, 1});
        }
        else{
            postOrder.push_back(p.first->data);
        }
    }
    printVector(preOrder);
    printVector(inOrder);
    printVector(postOrder);
}

// ? 1706231048
int heightTree(TNode* root){
    if (root == NULL) return 0;
    int l = heightTree(root->left);
    int r = heightTree(root->right);
    return (1 + max(l,r));
}

// ? 1706231054
int checkBalanceTree(TNode* root){
    // for balanced tree output will be height of tree,
    // for unbalanced tree output will be -1
    if (root == NULL) return 0;
    int l = checkBalanceTree(root->left);
    int r = checkBalanceTree(root->right);
    if (l == -1 || r == -1) return -1;
    if (abs(l - r) > 1) return -1;
    return (1 + max(l,r)); 
}

// ? 1706231108
int diameterTree(TNode* root, int &ans){
    if (root == NULL) return 0;
    int l = diameterTree(root->left,ans);
    int r = diameterTree(root->right,ans);
    ans = max(ans,1+l+r);
    return (1 + max(l,r));
}

// ? 1706231150
int maxPathSumTree(TNode* root,int &ans){
    if (root == NULL) return 0;
    int leftMaxPath = max(0, maxPathSumTree(root -> left, ans));
    int rightMaxPath = max(0, maxPathSumTree(root -> right, ans));
    int val = root -> data;
    ans = max(ans, (leftMaxPath + rightMaxPath) + val);
    return max(leftMaxPath, rightMaxPath) + val;
}

// ? 1706231242
bool isTreesIdentical(TNode *r1, TNode *r2){
    if (r1 == NULL && r2 == NULL) return true;
    if (r1 == NULL || r2 == NULL) return false;
    if (r1->data != r2->data) return false;
    return isTreesIdentical(r1->left,r2->left) && isTreesIdentical(r1->right,r2->right);
}

// ? 1706231709
void zigZagTraversal(TNode* root){
    // Code here
    vector <int> result;
    queue <TNode*> q;
    q.push(root);
    int lr = 1;
    while (q.empty() == false){
        int s = q.size();
        vector<int>level;
        for (int i = 0;i < s;i++){
            TNode* f = q.front();
            q.pop();
            level.push_back(f->data);
            if (f->left != NULL) q.push(f->left);
            if (f->right != NULL) q.push(f->right);
        }
        for (int i = level.size()-1;i>=0;i--){
            result.push_back(level[i]);
        }
        lr *= -1;
    }
    printVector(result);
}

// ? 1706231736
bool isNodeLeaf(TNode* root){
    if (root->left == NULL && root->right == NULL) return true;
    return false;
}
void addLeftBoundary(TNode* root,vector<int>&ans){
    TNode* curr = root->left;
    while (curr != NULL){
        if (isNodeLeaf(curr) == false) ans.push_back(curr->data);
        if (curr->left != NULL) curr = curr->left;
        else curr = curr->right;
    }
}
void addRightBoundary(TNode* root,vector<int>&ans){
    vector<int>temp;
    TNode* curr = root->right;
    while (curr != NULL){
        if (isNodeLeaf(curr) == false) temp.push_back(curr->data);
        if (curr->right != NULL) curr = curr->right;
        else curr = curr->left;
    }
    for (int i = temp.size()-1;i >= 0;i--){
        ans.push_back(temp[i]);
    }
}
void addLeafNodes(TNode* root,vector<int>&ans){
    if (isNodeLeaf(root)){
        ans.push_back(root->data);
        return ;
    }
    if (root->left != NULL) addLeafNodes(root->left,ans);
    if (root->right != NULL) addLeafNodes(root->right,ans);
}
void boundaryTraversal(TNode *root){
    vector<int>ans;
    if (root == NULL) return ;
    ans.push_back(root->data);
    if (isNodeLeaf(root)){
        cout << root->data << endl;
        return ;   
    }
    addLeftBoundary(root,ans);
    addLeafNodes(root,ans);
    addRightBoundary(root,ans);
    printVector(ans);
}

// ? 1706231849
void verticalOrderTraversal(TNode *root){
    if (root == NULL) return ;
    unordered_map<int,vector<int>>mp;
    int x_min = INT_MAX;
    int x_max = INT_MIN;
    queue<pair<TNode*,int>>q;
    q.push({root,0});
    while (q.empty() == false){
        pair<TNode*,int>p = q.front();
        q.pop();
        x_min = min(x_min,p.second);
        x_max = max(x_max,p.second);
        mp[p.second].push_back(p.first->data);
        if (p.first->left != NULL) q.push({p.first->left,p.second-1});
        if (p.first->right != NULL) q.push({p.first->right,p.second+1});
    }
    vector<int>res;
    for(int i = x_min;i <= x_max;i++){
        for (auto it:mp[i]){
            res.push_back(it);
        }
    }
    printVector(res);
}

// ? 1706231903
void topViewTree(TNode *root){
    if (root == NULL) return ;
    unordered_map<int,int>mp;
    int x_min = INT_MAX;
    int x_max = INT_MIN;
    queue<pair<TNode*,int>>q;
    q.push({root,0});
    while (q.empty() == false){
        pair<TNode*,int>p = q.front();
        q.pop();
        x_min = min(x_min,p.second);
        x_max = max(x_max,p.second);
        if (mp.find(p.second) == mp.end()) mp.insert({p.second,p.first->data});
        if (p.first->left != NULL) q.push({p.first->left,p.second-1});
        if (p.first->right != NULL) q.push({p.first->right,p.second+1});
    }
    vector<int>res;
    for(int i = x_min;i <= x_max;i++){
        res.push_back(mp[i]);
    }
    printVector(res);
}

// ? 1706231910
void bottomViewTree(TNode *root){
    if (root == NULL) return ;
    unordered_map<int,int>mp;
    int x_min = INT_MAX;
    int x_max = INT_MIN;
    queue<pair<TNode*,int>>q;
    q.push({root,0});
    while (q.empty() == false){
        pair<TNode*,int>p = q.front();
        q.pop();
        x_min = min(x_min,p.second);
        x_max = max(x_max,p.second);
        mp[p.second] = p.first->data;
        if (p.first->left != NULL) q.push({p.first->left,p.second-1});
        if (p.first->right != NULL) q.push({p.first->right,p.second+1});
    }
    vector<int>res;
    for(int i = x_min;i <= x_max;i++){
        res.push_back(mp[i]);
    }
    printVector(res);
}

// ? 1706231916
void leftViewTree(TNode *root){
    vector<int>ans;
    queue<TNode*>q;
    if (root == NULL) return ;
    q.push(root);
    while (q.empty() == false){
        int s = q.size();
        for (int i = 0;i < s;i++){
            TNode* f = q.front();
            q.pop();
            if (i == 0) ans.push_back(f->data);
            if (f->left != NULL) q.push(f->left);
            if (f->right != NULL) q.push(f->right);
        }
    }
    printVector(ans);
}

// ? 1706231924
void rightViewTree(TNode *root){
    vector<int>ans;
    queue<TNode*>q;
    if (root == NULL) return ;
    q.push(root);
    while (q.empty() == false){
        int s = q.size();
        for (int i = 0;i < s;i++){
            TNode* f = q.front();
            q.pop();
            if (i == s-1) ans.push_back(f->data);
            if (f->left != NULL) q.push(f->left);
            if (f->right != NULL) q.push(f->right);
        }
    }
    printVector(ans);
}

// ? 1706231939
bool symmentricTree(TNode* r1,TNode* r2){
    if (r1 == NULL && r2 == NULL) return true;
    if (r1 == NULL && r2 != NULL) return false;
    if (r1 != NULL && r2 == NULL) return false;
    if (r1->data != r2->data) return false;
    
    bool l = symmentricTree(r1->left,r2->right);
    bool r = symmentricTree(r1->right,r2->left);
    
    if (l == false || r == false) return false;
    
    return true;
}

// ? 1806230804
void rootToLeaf(vector<vector<int>>&ans,TNode* root,vector<int>vec){
    if (root->left == NULL && root->right == NULL){
        vec.push_back(root->data);
        ans.push_back(vec);
        return ;
    }
    vec.push_back(root->data);
    if (root->left != NULL) rootToLeaf(ans,root->left,vec);
    if (root->right != NULL) rootToLeaf(ans,root->right,vec);
}

// ? 1806230817
bool getRootToNodePath(TNode* root, vector <int> &ans, int x) {
    // if root is NULL
    // there is no path
    if (!root)
        return false;

    // push the node's value in 'arr'
    ans.push_back(root->data);

    // if it is the required node
    // return true
    if (root->data == x)
        return true;

    // else check whether the required node lies
    // in the left subtree or right subtree of
    // the current node
    if (getRootToNodePath(root -> left, ans, x) || getRootToNodePath(root -> right, ans, x))
        return true;

    // required node does not lie either in the
    // left or right subtree of the current node
    // Thus, remove current node's value from
    // 'arr'and then return false   
    ans.pop_back();
    return false;
}

// ? 1806230931
TNode* lcaTree(TNode* root ,int n1 ,int n2 ){
    if (root == NULL) return NULL;
    if (root->data == n1) return root;
    if (root->data == n2) return root;
    TNode* l = lcaTree(root->left,n1,n2);
    TNode* r = lcaTree(root->right,n1,n2);
    if (l == NULL && r == NULL) return NULL;
    if (l != NULL && r != NULL) return root;
    if (l != NULL) return l;
    if (r != NULL) return r;
    return NULL;
}

// ? 1806230941
void widthOfBinaryTree(TNode* root) {
    int ans = 0;
    queue<pair<TNode*,int>>q;
    if (root == NULL) return ;
    q.push({root,0});
    while (!q.empty()) {
        int size = q.size();
        int curMin = q.front().second;
        int leftMost, rightMost;
        for (int i = 0; i < size; i++) {
            int cur_id = q.front().second - curMin; // subtracted to prevent integer overflow
            TNode* temp = q.front().first;
            q.pop();
            if (i == 0) leftMost = cur_id;
            if (i == size - 1) rightMost = cur_id;
            if (temp -> left) q.push({temp -> left,cur_id * 2 + 1});
            if (temp -> right) q.push({temp -> right,cur_id * 2 + 2});
        }
        ans = max(ans, rightMost - leftMost + 1);
    }
    cout << ans << endl;
}

// ? 1806231045
void childSumTree(TNode* root) {
    if (root == NULL) return;
    int child = 0;
    if (root -> left) {
        child += root->left->data;
    }
    if (root -> right) {
        child += root->right->data;
    }

    if (child < root->data) {
        if (root->left) root->left-> data = root -> data;
        else if (root->right) root->right-> data = root -> data;
    }

    childSumTree(root -> left);
    childSumTree(root -> right);

    int tot = 0;
    if (root -> left) tot += root->left->data;
    if (root -> right) tot += root->right->data;
    if (root -> left || root -> right) root -> data = tot;
}

// ? 1806231112
void markParentPointers(TNode* root,unordered_map<TNode*,TNode*>&parent){
    if(root == NULL) return ;
    queue<TNode*>q;
    q.push(root);
    while (q.empty() == false){
        TNode* f = q.front();
        q.pop();
        if (f->left != NULL){
            q.push(f->left);
            parent[f->left] = f;
        }
        if (f->right != NULL){
            q.push(f->right);
            parent[f->right] = f;
        }
    }
}
TNode* findTargetNode(TNode* root,int target){
    if (root == NULL) return NULL;
    if (root->data == target) return root;
    TNode* l = findTargetNode(root->left,target);
    TNode* r = findTargetNode(root->right,target);
    if (l != NULL) return l;
    if (r != NULL) return r;
    return NULL;
}
void KDistanceNodes(TNode* root, int target , int k){
    if (root == NULL) return ;
    TNode* tar = findTargetNode(root,target);
    vector<int>ans;
    unordered_map<TNode*,TNode*>parent;
    parent[root] = NULL;
    markParentPointers(root,parent);
    queue<pair<pair<TNode*,int>,TNode*>>q; // node, dis, parent
    q.push({{tar,0},NULL});
    while (q.empty() == false){
        TNode* par = q.front().second;
        TNode* f = q.front().first.first;
        int dis = q.front().first.second;
        q.pop();
        if (dis == k){
            ans.push_back(f->data);
        }
        if (f->left != NULL){
            if (f->left != par){
                q.push({{f->left,dis+1},f});
            }
        }
        if (f->right != NULL){
            if (f->right != par){
                q.push({{f->right,dis+1},f});
            }
        }
        if (parent[f] != NULL && parent[f] != par){
            q.push({{parent[f],dis+1},f});
        }
    }
    sort(ans.begin(),ans.end());
    cout << "nodes at " << k << " dis from : " << target << endl;
    printVector(ans);
}

// ? 1806231142
void markParentPointers1(TNode* root,unordered_map<TNode*,TNode*>&parent){
    if(root == NULL) return ;
    queue<TNode*>q;
    q.push(root);
    while (q.empty() == false){
        TNode* f = q.front();
        q.pop();
        if (f->left != NULL){
            q.push(f->left);
            parent[f->left] = f;
        }
        if (f->right != NULL){
            q.push(f->right);
            parent[f->right] = f;
        }
    }
}
TNode* findTargetNode1(TNode* root,int target){
    if (root == NULL) return NULL;
    if (root->data == target) return root;
    TNode* l = findTargetNode1(root->left,target);
    TNode* r = findTargetNode1(root->right,target);
    if (l != NULL) return l;
    if (r != NULL) return r;
    return NULL;
}
void burnTreeTime(TNode* root, int target) {
    if (root == NULL) return ;
    TNode* tar = findTargetNode1(root,target);
    int max_time = 0;
    unordered_map<TNode*,TNode*>parent;
    parent[root] = NULL;
    markParentPointers1(root,parent);
    queue<pair<pair<TNode*,int>,TNode*>>q; // node, time, parent
    q.push({{tar,0},NULL});
    while (q.empty() == false){
        TNode* par = q.front().second;
        TNode* f = q.front().first.first;
        int time = q.front().first.second;
        q.pop();
        max_time = max(max_time,time);
        if (f->left != NULL){
            if (f->left != par){
                q.push({{f->left,time+1},f});
            }
        }
        if (f->right != NULL){
            if (f->right != par){
                q.push({{f->right,time+1},f});
            }
        }
        if (parent[f] != NULL && parent[f] != par){
            q.push({{parent[f],time+1},f});
        }
    }
    cout << "burn time : " << max_time << endl;
}

// ? 1806231644
int leftHeight(TNode* root){
    int len = 0;
    while (root != NULL){
        root = root->left;
        len++;
    }
    return len;
}
int rightHeight(TNode* root){
    int len = 0;
    while (root != NULL){
        root = root->right;
        len++;
    }
    return len;
}
int countNodes(TNode* root) {
    if (root == NULL) return 0;
    int l = leftHeight(root);
    int r = rightHeight(root);
    if (l == r) return ((1 << l ) - 1);
    int ll = countNodes(root->left);
    int rr = countNodes(root->right);
    return (1 + ll + rr);
}

// ? 1806231905
TNode* createTreeInPre(vector<int>&preOrder,int preStart,int preEnd,vector<int>&inOrder,int inStart,int inEnd,unordered_map<int,int>&inMap){
    if (preStart > preEnd || inStart > inEnd) return NULL;
    
    TNode* root = new TNode(preOrder[preStart]); // root = preOrder[preStart] , 
    int i = inMap[preOrder[preStart]]; // let preOrder[preStart] is at index i in inOrder 
    int n = i - inStart; // n - 1 elements will be in left subTree, reaminig in right
    
    // for leftSubTree , preOrder = preOrder(preStart + 1 ..... preStart + n) , inOrder = inOrder(inStart .... i - 1);
    root->left = createTreeInPre(preOrder,preStart+1,preStart+n,inOrder,inStart,i-1,inMap);

    // for rightSubTree , preOrder = preOrder(preStart + n + 1 ..... preEnd) , inOrder = inOrder(i + 1 ..... inEnd);
    root->right = createTreeInPre(preOrder,preStart+n+1,preEnd,inOrder,i+1,inEnd,inMap);

    return root;
}
TNode* createTree1(vector<int>&preOrder,vector<int>inOrder){
    // convert inOrder vector to map so that we can easly find index of element
    unordered_map<int,int>inMap;
    for (int i = 0;i < inOrder.size();i++){
        inMap[inOrder[i]] = i;
    }
    TNode* root = createTreeInPre(preOrder,0,preOrder.size()-1,inOrder,0,inOrder.size()-1,inMap);
    return root;
}

// ? 1806232004
TNode* createTreeInPost(vector<int>&postOrder,int postStart,int postEnd,vector<int>&inOrder,int inStart,int inEnd,unordered_map<int,int>&inMap){
    if (postStart > postEnd || inStart > inEnd) return NULL;
    
    TNode* root = new TNode(postOrder[postEnd]); // root = postOrder[end]
    int i = inMap[postOrder[postEnd]]; // let postOrder[start] is at index i in inOrder[]
    int n = i - inStart; // n elements will be in left subTree, remaining in right subTree

    // for left subTree, postOrder = postOrder[postStart ..  postStart+n-1] , inOrder = inOrder[inStart .. i-1];
    root->left = createTreeInPost(postOrder,postStart,postStart+n-1,inOrder,inStart,i-1,inMap);

    // for right subTree, postOrder = postOrder[postStart ..  postEnd-n-1] , inOrder = inOrder[i+1 .. inEnd];
    root->right = createTreeInPost(postOrder,postStart+n,postEnd-1,inOrder,i+1,inEnd,inMap);

    return root;
}
TNode* createTree2(vector<int>&postOrder,vector<int>&inOrder){
    unordered_map<int,int>inMap;
    for (int i = 0; i < inOrder.size();i++){
        inMap[inOrder[i]] = i;
    }
    TNode* root = createTreeInPost(postOrder,0,postOrder.size()-1,inOrder,0,inOrder.size()-1,inMap);
    return root;
}

// ? 1906230815
string serialize(TNode* root) {
    if(!root) return "";
    string s ="";
    queue<TNode*> q;
    q.push(root);
    while(!q.empty()) {
        TNode* curNode = q.front();
        q.pop();
        if(curNode==NULL) s.append("#,");
        else s.append(to_string(curNode->data)+',');
        if(curNode != NULL){
            q.push(curNode->left);
            q.push(curNode->right);            
        }
    }
    return s;
}
TNode* deserialize(string data) {
    if(data.size() == 0) return NULL; 
    stringstream s(data);
    string str; 
    getline(s, str, ',');
    TNode *root = new TNode(stoi(str));
    queue<TNode*> q; 
    q.push(root); 
    while(!q.empty()) {
        TNode* node = q.front(); 
        q.pop(); 
        getline(s, str, ',');
        if(str == "#") {
            node->left = NULL; 
        }
        else {
            TNode* leftNode = new TNode(stoi(str)); 
            node->left = leftNode; 
            q.push(leftNode); 
        }
        
        getline(s, str, ',');
        if(str == "#") {
            node->right = NULL; 
        }
        else {
            TNode* rightNode = new TNode(stoi(str)); 
            node->right = rightNode;
            q.push(rightNode); 
        }
    }
    return root; 
}

// ? 1906230956
void printFlattenTree(TNode* root){
    cout << endl;
    while (root != NULL){
        cout << root->data << " ";
        root = root->right;
    }
    cout << endl;
}
void flattenTree1(TNode* root,TNode* &prev){
    if (root == NULL) return ;
    flattenTree1(root->right,prev);
    flattenTree1(root->left,prev);
    root->left = NULL;
    root->right = prev;
    prev = root;
}
void flattenTree2(TNode* root){
    if (root == NULL) return ;
    stack<TNode*>st;
    st.push(root);
    while (st.empty() == false){
        TNode* t = st.top();
        st.pop();
        if (t->right != NULL) st.push(t->right);
        if (t->left != NULL) st.push(t->left);
        if (st.empty() == false){
            t->right = st.top();
        }
        t->left = NULL;
    }
    printFlattenTree(root);
}

// ? 1906231019
bool searchBST(TNode* root, int x) {
    while (root != NULL){
        if (root->data == x) return true;
        if (root->data < x) root = root->right;
        else root = root->left;
    }
    return false;
}

// ? 1906231031
void minMaxBST(TNode* root){
    if (root == NULL) return ;
    int mini = INT_MAX;
    int maxi = INT_MIN;
    TNode* temp = root;
    while (temp != NULL){
        mini = temp->data;
        temp = temp->left;
    }
    temp = root;
    while (temp != NULL){
        maxi = temp->data;
        temp = temp->right;
    }
    cout << "min : " << mini << " , max : " << maxi << endl;
}

// ? 1906231038
int findCeilBST(TNode* root, int x) {
    if (root == NULL) return -1;
    int ans = -1;
    while (root != NULL){
        if (root->data == x) return x;
        if (root->data < x){
            root = root->right;
        }else{
            ans = root->data;
            root = root->left;
        }
    }
    return ans;
}

// ? 1906231048
int findFloorBST(TNode* root, int x) {
    int ans = -1;
    if (root == NULL) return ans;
    while (root != NULL){
        if (root->data == x) return x;
        if (root->data > x){
            root = root->left;
        }else{
            ans = root->data;
            root = root->right;
        }
    }
    return ans;
}

// ? 1906231058
TNode* insertNodeBST(TNode* root, int k) {
    TNode* n = new TNode(k);
    if (root == NULL) return n;
    TNode* temp = root;
    while (true){
        if (temp->data == k) return root;
        if (temp->data < k){
            // k should be in right
            if (temp->right == NULL){
                temp->right = n;
                break;
            }
            temp = temp->right;
        }else{
            if (temp->left == NULL){
                temp->left = n;
                break;
            }
            temp = temp->left;
        }
    }
    return n;
}

// ? 1906231350
TNode* delMergeBST(TNode* root){
    // root is to be removed, so we will merge all leftSubTree to right subTree and return a node
    // returned node will act like subsitute for del Node
    
    if (root->left == NULL){
        return root->right;
    }
    if (root->right == NULL){
        return root->left;
    }
    
    // if both right, left not null
    // all left subtree nodes are lesser than all right subtree nodes
    
    TNode* leftSubTree = root->left;
    TNode* rightSubTree = root->right;
    TNode* temp = rightSubTree;
    // now move temp so that temp->left is null , so we can attach leftSubTree to it
    while (temp->left != NULL){
        temp = temp->left;
    }
    temp->left = leftSubTree;
    
    return rightSubTree;
}
TNode* del_prevNodeBST(TNode* root,int x){
    if (root == NULL) return NULL;
    TNode* temp = root;
    while (temp->left != NULL || temp->right != NULL){
        if (temp->left != NULL){
            if (temp->left->data == x){
                return temp;
            }
        }
        if (temp->right != NULL){
            if (temp->right->data == x){
                return temp;
            }
        }
        if (temp->data < x){
            temp = temp->right;
        }else if (temp->data > x){
            temp = temp->left;
        }
        if (temp == NULL){
            return NULL;
        }
    }
    return NULL;
}
TNode* deleteNodeBST(TNode* root, int x) {
    if (root == NULL) return NULL;
    
    if (root->data == x){
        return delMergeBST(root);
    }
    
    TNode* prevNode = del_prevNodeBST(root,x);
    if (prevNode == NULL) return root;
    
    if (prevNode->left != NULL && prevNode->left->data == x){
        prevNode->left = delMergeBST(prevNode->left);
        return root;
    }
    if (prevNode->right != NULL && prevNode->right->data == x){
        prevNode->right = delMergeBST(prevNode->right);
        return root;
    }
    
    return root;
}

TNode* kthsmallest(TNode* root,int &k){
    if(root == NULL) return NULL;
    
    TNode* left = kthsmallest(root->left,k);
    if(left != NULL) return left;
    k--;
    if (k == 0) return root;
    
    return kthsmallest(root->right,k);
}

// ? 1906231806
bool checkBST(TNode* root,int leftMax,int rightMax){
    if (root == NULL) return true;
    if (root->data >= rightMax || root->data <= leftMax) return false;
    
    return checkBST(root->left,leftMax,root->data) && checkBST(root->right,root->data,rightMax);
}

// ? 1906231832
TNode* LCA_BST(TNode *root, int n1, int n2){
    if (root == NULL) return NULL;
    if (root->data > n1 && root->data > n2){
        return LCA_BST(root->left,n1,n2);
    }
    if (root->data < n1 && root->data < n2){
        return LCA_BST(root->right,n1,n2);
    }
    return root;
}

// ? 1906231907
TNode* createBST_preOrder(vector<int>&preOrder,int start,int end){
    if (start > end) return NULL;
    
    TNode* root = new TNode(preOrder[start]);

    int n = start;
    for (int i = start+1;i<=end;i++){
        if (preOrder[i] < preOrder[start]) n++;
        else break;
    }
    // (start+1 .... n ) are less than start so these will be in left SubTree
    root->left = createBST_preOrder(preOrder,start+1,n);
    root->right = createBST_preOrder(preOrder,n+1,end);
    return root;
}

// ? 2006231147
TNode* ceil1(TNode* root, int x) {
    if (root == NULL) return NULL;
    TNode* ans = NULL;
    while (root != NULL){
        if (root->data <= x){
            root = root->right;
        }else if (root->data > x) {
            ans = root;
            root = root->left;
        }
    }
    return ans;
}
TNode* floor1(TNode* root, int x) {
    TNode* ans = NULL;
    if (root == NULL) return ans;
    while (root != NULL){
        if (root->data >= x){
            root = root->left;
        }else if (root->data < x) {
            ans = root;
            root = root->right;
        }
    }
    return ans;
}
void findPreSucTree(TNode* root,int key)
{
    TNode* pre = floor1(root,key);
    TNode* suc = ceil1(root,key);
    cout << "pre : " << pre->data << endl;
    cout << "suc : " << suc->data << endl;
}

// ? 2006231217
void inOrderTree1(vector<int>&ans,TNode* root){
    if (root == NULL) return ;
    inOrderTree1(ans,root->left);
    ans.push_back(root->data);
    inOrderTree1(ans,root->right);
}
void mergeVecTree(vector<int>&ans1,vector<int>&ans2,vector<int>&ans){
    int i = 0;
    int j = 0;
    int ii = ans1.size();
    int jj = ans2.size();
    while (i < ii && j < jj){
        if (ans1[i] <= ans2[j]){
            ans.push_back(ans1[i]);
            i++;
        }else{
            ans.push_back(ans2[j]);
            j++;
        }
    }
    while (i < ii){
        ans.push_back(ans1[i]);
        i++;
    }
    while (j < jj){
        ans.push_back(ans2[j]);
        j++;
    }
}
void mergeBSTSort(TNode *root1, TNode *root2){
    vector<int>ans1;
    vector<int>ans2;
    inOrderTree1(ans1,root1);
    inOrderTree1(ans2,root2);
    vector<int>ans;
    mergeVecTree(ans1,ans2,ans);
    printVector(ans);
}

// ? 2006231356
class BSTIterator {
    public:
        stack<TNode*>st;
        TNode* node;
        BSTIterator(TNode* root) {
            node = root;
            TNode* temp = root;
            while (temp != NULL){
                st.push(temp);
                temp=temp->left;
            }
        }
        int next() {
            if (st.empty() == false){
                TNode* ans = st.top();
                st.pop();
                if (ans->right != NULL){
                    TNode* temp = ans->right;
                    while(temp != NULL){
                        st.push(temp);
                        temp = temp->left;
                    }
                }
                return ans->data;
            }
            return -1;
        }
        bool hasNext() {
            return (!st.empty());
        }
};

// ? 2006231821
void inOrder2(vector<int>&ans,TNode* root){
    if (root == NULL) return ;
    inOrder2(ans,root->left);
    ans.push_back(root->data);
    inOrder2(ans,root->right);
}
bool isPairPresentBST(TNode* root, int target){
    vector<int>nums;
    inOrder2(nums,root);
    int l = 0;
    int r = nums.size()-1;
    while (l < r){
        if (nums[l]+nums[r] == target) return true;
        else if (nums[l]+nums[r] < target) l++;
        else r--;
    }
    return false;
}
// ! another method for # 2006231821 using bst iterator
class BSTiterator{
    public:
        stack<TNode*>st1; // top = min ele -> ascending order
        stack<TNode*>st2; // top = max ele -> descending order
        TNode* node;
        BSTiterator(TNode* root){
            node = root;
            TNode* temp = root;
            while (temp != NULL){
                st1.push(temp);
                temp = temp->left;
            }
            temp = root;
            while (temp != NULL){
                st2.push(temp);
                temp = temp->right;
            }
        };
        TNode* left(){
            if (st1.empty()) return NULL;
            TNode* t = st1.top();
            st1.pop();
            if (t->right != NULL){
                TNode* r = t->right;
                while (r != NULL){
                    st1.push(r);
                    r = r->left;
                }
            }
            return t;
        }
        TNode* right(){
            if (st2.empty()) return NULL;
            TNode* t = st2.top();
            st2.pop();
            if (t->left != NULL){
                TNode* r = t->left;
                while (r != NULL){
                    st2.push(r);
                    r = r->right;
                }
            }
            return t;
        }
};
void twoSumPairBST(TNode* root,int target){
    BSTiterator* obj =  new BSTiterator(root);
    TNode* l = obj->left();
    TNode* r = obj->right();
    while (l != NULL && r != NULL && l != r && l->data <= r->data){
        if (l->data + r->data == target){
            cout << "found a pair with sum : " << target << " , " << l->data << " + " << r->data << endl;
            return ;
        }else if (l->data + r->data < target){
            l = obj->left();
        }else{
            r = obj->right();
        }
    }
    cout << "no pair with sum " << target << endl;
}

// ? 2106230815
void inOrder3(TNode* root,TNode*& first, TNode*& last, TNode*& middle, TNode*& prev){
    if (root == NULL) return ;
    inOrder3(root->left,first,last,middle,prev);
    
    if ( prev != NULL && root->data < prev->data){
        if (first == NULL){
            // first node which is violating bst rule
            first = prev;
            middle = root;
        }else{
            last = root;
        }
    }
    prev = root;
    inOrder3(root->right,first,last,middle,prev);
}
void correctBST(TNode* root ){
    printTree(root);
    TNode* first = NULL;
    TNode* last = NULL;
    TNode* middle = NULL;
    TNode* prev = new TNode(INT_MIN);
    inOrder3(root,first,last,middle,prev);
    if (first != NULL && last != NULL){
        int t = first->data;
        first->data = last->data;
        last->data = t;
    }else if (first != NULL && middle != NULL){
        int t = first->data;
        first->data = middle->data;
        middle->data = t;
    }
    printTree(root);
}

// ? 2106230943
vector<int> maxSizeBST(TNode* root){
    if (root == NULL){
        return {0,INT_MIN,INT_MAX}; // {size, subTree_Min, subTree_Max}
    }
    vector<int>l = maxSizeBST(root->left);
    vector<int>r = maxSizeBST(root->right);
    // left_SubTree_Max < root < right_SubTree_Min
    if (l[1] < root->data && root->data < r[2]){
        return { (1+l[0]+r[0]), max(root->data,r[1]), min(root->data,l[2])};
    }
    return {max(l[0],r[0]),INT_MAX,INT_MIN}; 
}
void largestBst(TNode *root){
    vector<int>maxi = maxSizeBST(root);
    cout << "largest bst have : " << maxi[0] << " nodes " << endl;
}

// ? 2106231136
TNode* invertTree(TNode* root) {
    if (root == NULL) return NULL;
    TNode* l = root->left;
    TNode* r = root->right;
    root->right = l;
    root->left = r;
    invertTree(l);
    invertTree(r);
    return root;
}

// ? 2106231146
void connectRightPointer(TNode *root){
    if (root == NULL) return ;
    queue<TNode*>q;
    q.push(root);
    while (q.empty() == false){
        int s = q.size();
        TNode* prev = NULL;
        for (int i = 0; i < s;i++){
            TNode* f = q.front();
            q.pop();
            if (prev != NULL){
                prev->nextRight = f;
            }
            prev = f;
            if (f->left != NULL) q.push(f->left);
            if (f->right != NULL) q.push(f->right);
        }
        if (prev != NULL) prev->nextRight = NULL;
    }
}    

// ? 2106231157
void traversalTree(CNode* root, int ans,int& maxi){
    if (root->children.size() == 0){
        maxi = max(ans+1,maxi);
    }
    for (auto it : root->children){
        traversalTree(it,ans+1,maxi);
    }
}
int maxDepthCTree(CNode* root) {
    if (root == NULL) return 0;
    int maxi = 0;
    traversalTree(root,0,maxi);
    return maxi;
}

// ? 2106231405
TNode* replaceCousinsInTree(TNode* root) {
    if (root == NULL) return NULL;
    root->data = 0;
    queue<TNode*>q;
    q.push(root);
    while (q.empty() == false){
        vector<pair<TNode*,int>>v;
        int total_level_sum = 0;
        int s = q.size();
        for (int i = 0;i<s;i++){
            TNode* f = q.front();
            int sum = 0;
            q.pop();
            if (f->left != NULL){
                q.push(f->left);
                sum += (f->left->data);
            }
            if (f->right != NULL){
                q.push(f->right);
                sum += (f->right->data);
            }
            v.push_back({f,sum});
            total_level_sum += sum;
        }
        for (auto it : v){
            TNode* f = it.first;
            if (f->left != NULL){
                f->left->data = total_level_sum - it.second;
            }
            if (f->right != NULL){
                f->right->data = total_level_sum - it.second;
            }
        }
    }
    return root;
}

// ? 2106231843
int minDepthTreeHelp(TNode* root){
    if (root == NULL) return INT_MAX;
    if (root->left == NULL && root->right == NULL) return 1;
    int l = minDepthTreeHelp(root->left);
    int r = minDepthTreeHelp(root->right);
    return (1 + min(l,r));
}
int minDepthTree(TNode* root) {
    if (root == NULL) return 0;
    return minDepthTreeHelp(root);
}

// ? 2106231854
bool hasPathSumTree(TNode* root, int targetSum) {
    if (root == NULL) return false;
    if (root->left == NULL && root->right == NULL){
        if (targetSum == root->data) return true;
        return false;
    }
    return ( hasPathSumTree(root->left,targetSum - root->data) || hasPathSumTree(root->right,targetSum - root->data) );
}

// ? 2106231927
void pathSum2Tree(TNode* root,int targetSum,vector<vector<int>>&ans,vector<int>&path){
    if (root == NULL) return;
    if (root->left == NULL && root->right == NULL){
        if (targetSum == root->data){
            path.push_back(root->data);
            ans.push_back(path);
            path.pop_back();
        }
        return ;
    }
    path.push_back(root->data);
    pathSum2Tree(root->left,targetSum - root->data,ans,path);
    pathSum2Tree(root->right,targetSum - root->data,ans,path);
    path.pop_back();
}

// ? 2206231007
bool increasingTriplet(vector<int>nums) {
    int n = nums.size();
    if (n < 3) {
        return false;
    }
    int firstSmallest = INT_MAX;
    int secondSmallest = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (nums[i] <= firstSmallest) {
            firstSmallest = nums[i];
        } else if (nums[i] <= secondSmallest) {
            secondSmallest = nums[i];
        } else {
            return true;
        }
    }
    return false;
}

// ? 2206231039
int nUniqueBSTHelp(int n, vector<int>&dp){
    if (dp[n] != -1) return dp[n];
    int ans = 0;
    for(int i = 1;i <= n;i++){
        int l = nUniqueBSTHelp(i-1,dp);
        int r = nUniqueBSTHelp(n-i,dp);
        ans += (l*r);
    }
    dp[n] = ans;
    return dp[n];
}
void nUniqueBST(int n) {
    vector<int>dp(n+1,-1);
    dp[0] = 1;
    dp[1] = 1;
    nUniqueBSTHelp(n,dp);
    cout << " we can create " << dp[n] << " unique BST's using " << n << " nodes" << endl;
}

// ? 2206231056
TNode* createBSTsortedArr(vector<int>&nums,int l,int r){
    if (l > r) return NULL;
    int m = (l + r) >> 1;
    TNode* t = new TNode(nums[m]);
    t->left = createBSTsortedArr(nums,l,m-1);
    t->right = createBSTsortedArr(nums,m+1,r);
    return t;
}
TNode* sortedArrayToBST(vector<int>nums) {
    int l = 0;
    int r = nums.size()-1;
    TNode* t = createBSTsortedArr(nums,l,r);
    return t;
}

// ? 2206231427
vector<TNode*>createUniqueBST(int l,int r){
    if (l > r) return {NULL};
    if (l == r){
        TNode* t = new TNode(l);
        return {t};
    }
    vector<TNode*>subTree;
    for (int i = l; i <= r;i++){
        vector<TNode*>leftSubTree = createUniqueBST(l,i-1);
        vector<TNode*>rightSubTree = createUniqueBST(i+1,r);
        for (int j = 0;j < leftSubTree.size();j++){
            for (int k = 0;k < rightSubTree.size();k++){
                TNode* t = new TNode(i);
                t->left = leftSubTree[j];
                t->right = rightSubTree[k];
                subTree.push_back(t);
            }
        }
    }
    return subTree;
}

// ? 2206231431
void rootToLeafSum(int& ans,TNode* root,int path){
    if (root == NULL) return ;
    if (root->left == NULL && root->right == NULL){
        path = path*10 + root->data;
        ans += path;
        return ;
    }
    rootToLeafSum(ans,root->left,(path*10 + root->data));
    rootToLeafSum(ans,root->right,(path*10 + root->data));
}

// ? 2206231454
void sumOfLeftLeaves(int& sum,TNode* root,bool fromLeft){
    if (root == NULL) return ;
    if (root->left == NULL && root->right == NULL){
        if (fromLeft) sum += root->data;
        return ;
    }
    sumOfLeftLeaves(sum,root->left,true);
    sumOfLeftLeaves(sum,root->right,false);
}

// ? 2206231504
void levelOrderNTree(CNode* root) {
    vector<vector<int>>ans;
    if (root == NULL) return ;
    queue<CNode*>q;
    q.push(root);
    while(q.empty() == false){
        vector<int>level;
        int s = q.size();
        for (int i = 0;i < s;i++){
            CNode* f = q.front();
            q.pop();
            level.push_back(f->val);
            for(auto it : f->children){
                q.push(it);
            }
        }
        ans.push_back(level);
    }
    for (auto it : ans){
        printVector(it);
    }
}

// ? 2206231527
void treePaths(vector<string>&allPaths,string path,TNode* root){
    if (root == NULL) return ;
    if (root->left == NULL && root->right == NULL){
        if (path.length() == 0){
            path = to_string(root->data);
        }else{
            path = path + "->" + to_string(root->data);
        }
        allPaths.push_back(path);
        return ;
    }
    if (path.length() == 0){
        path = to_string(root->data);
    }else{
        path = path + "->" + to_string(root->data);
    }
    treePaths(allPaths,path,root->left);
    treePaths(allPaths,path,root->right);
}

// ? 2206231546
int findBottomLeftTreeValue(TNode* root) {
    int lastLevelLeft = 0;
    queue<TNode*>q;
    if (root == NULL) return 0;
    q.push(root);
    while (q.empty() == false){
        int s = q.size();
        for (int i = 0;i < s;i++){
            TNode* f = q.front();
            q.pop();
            if (i == 0) lastLevelLeft = f->data;
            if (f->left != NULL) q.push(f->left);
            if (f->right != NULL) q.push(f->right);
        }
    }
    return lastLevelLeft;
}

// ? 2206231750
void largestValuesRowTree(TNode* root) {
    vector<int>rowMaxs;
    queue<TNode*>q;
    if (root == NULL) return ;
    q.push(root);
    while (q.empty() == false){
        int s = q.size();
        int rowMax = INT_MIN;
        for (int i = 0;i < s;i++){
            TNode* f = q.front();
            q.pop();
            rowMax = max(rowMax,f->data);
            if (f->left != NULL) q.push(f->left);
            if (f->right != NULL) q.push(f->right);
        }
        rowMaxs.push_back(rowMax);
    }
    printVector(rowMaxs);
}

// ? 2206231858
string tree2str(TNode* root){
    if (root == NULL) return "";
    if (root->left == NULL && root->right == NULL){
        return to_string(root->data);
    }
    string str = to_string(root->data);
    string l = tree2str(root->left);
    string r = tree2str(root->right);
    str = str + '(' + l + ')';
    if (r.size() != 0) str = str + '(' + r + ')';
    return str;
}

// ? 2206231919
void convertBST_GreaterTree(TNode* root,int& prevSum){
    if (root == NULL) return ;
    convertBST_GreaterTree(root->right,prevSum);
    prevSum += root->data;
    root->data = prevSum;
    convertBST_GreaterTree(root->left,prevSum);
}

// ? 2306231142
int findTreeTilt(TNode* root,int &ans) {
    if (root == NULL) return 0;
    
    int t = root->data;

    int l = findTreeTilt(root->left,ans);
    int r = findTreeTilt(root->right,ans);
    root->data = abs(l-r);
    ans = ans + (abs(l-r));

    return (l + r + t); 
}


// ? 2306231200
void inOrder(TNode* root,vector<int>&nodes){
    if (root == NULL) return ;
    inOrder(root->left,nodes);
    nodes.push_back(root->data);
    inOrder(root->right,nodes);
}
void findModeBST(TNode* root) {
    vector<int>nums;
    if (root == NULL) return ;
    inOrder(root,nums);
    int n = nums.size();
    
    vector<int> mode;
    int currentElement = nums[0];
    int currentCount = 1;
    int maxCount = 1;

    for (int i = 1; i < n; i++) {
        if (nums[i] == currentElement) {
            currentCount++;
        } else {
            // nums[i] is a new number
            // first check whether prev number is mode or not
            if (currentCount > maxCount) {
                maxCount = currentCount;
                mode = {currentElement};
            } else if (currentCount == maxCount) {
                mode.push_back(currentElement);
            }
            currentElement = nums[i];
            currentCount = 1;
        }
    }
    // Check the count of the last element
    if (currentCount > maxCount) {
        mode = {currentElement};
    } else if (currentCount == maxCount) {
        mode.push_back(currentElement);
    }
    cout << "mode : " << endl;
    printVector(mode);
}

// ? 2306231215
void preOrderNTree(CNode* root,vector<int>&ans){
    if (root == NULL) return ;
    ans.push_back(root->val);
    for(auto it : root->children){
        preOrderNTree(it,ans);
    }
}

// ? 2306231220
void postOrderNTree(CNode* root,vector<int>&ans){
    if (root == NULL) return ; 
    for(auto it : root->children){
        postOrderNTree(it,ans);
    }
    ans.push_back(root->val);
}

// ? 2306231359
void averageOfLevels(TNode* root) {
    vector<double>ans;
    if (root == NULL) return ;
    queue<TNode*>q;
    q.push(root);
    while (q.empty() == false){
        int s = q.size();
        double sum = 0;
        for (int i = 0; i < s;i++){
            TNode* f = q.front();
            q.pop();
            sum = sum + (double)(f->data);
            if (f->left != NULL) q.push(f->left);
            if (f->right != NULL) q.push(f->right);
        }
        ans.push_back( sum/(double)(s));
    }
    for (auto it : ans) cout << it << " ";
    cout << endl;
}

// ? 2306231500
int maxArr(vector<int>&nums,int l,int r){
    int maxi = nums[l];
    int ind = l;
    for (int i = l+1;i <= r;i++){
        if (nums[i] > maxi){
            maxi = nums[i];
            ind = i;
        }
    }
    return ind;
}
TNode* constructMaxTree(vector<int>&nums,int l,int r){
    if (l > r) return NULL;
    int maxInd = maxArr(nums,l,r);
    TNode* t = new TNode(nums[maxInd]);
    t->left = constructMaxTree(nums,l,maxInd-1);
    t->right = constructMaxTree(nums,maxInd+1,r);
    return t;
}
// ? 2306231513
void inOrder4(TNode* root,vector<int>&ans){
    if (root == NULL) return ;
    inOrder4(root->left,ans);
    ans.push_back(root->data);
    inOrder4(root->right,ans);
}
void getMinDiffeTree(TNode* root) {
    if (root == NULL) return ;
    vector<int>nums; // sorted
    inOrder4(root,nums);
    int minDiff = INT_MAX;
    for (int i = 1;i < nums.size();i++){
        minDiff = min(minDiff, (nums[i]-nums[i-1]) );
    }
    cout << minDiff << endl;
}

// ? 2306231703
void traversal(TNode* root,vector<int>& ans,int& n){
    if (root == NULL) return ;
    ans.push_back(root->data);
    n++;
    traversal(root->left,ans,n);
    traversal(root->right,ans,n);
}
int secondMiniTree(TNode* root) {
    if (root == NULL) return -1;
    vector<int>vec;
    int n = 0;
    traversal(root,vec,n);
    if (n < 2) return -1;
    int min1 = vec[0];
    int min2 = -1;
    for (int i = 0; i < n;i++){
        if (vec[i] < min1){
            min2 = min1;
            min1 = vec[i];
        }else if(vec[i] > min1){
            if (min2 == -1) min2 = vec[i];
            else if (vec[i] < min2) min2 = vec[i];
        }
    }
    return min2;
}

// ? 2306231746
bool pruneTreeHelp(TNode* root){
    if (root == NULL) return false;
    bool l = pruneTreeHelp(root->left);
    bool r = pruneTreeHelp(root->right);
    if (l == false){ // Left subTree have no ones
        root->left = NULL;
    }
    if (r == false){ // Right subTree have no ones
        root->right = NULL;
    }
    if (root->data == 1){
        return true;
    }
    if (l == true || r == true) return true; // if any subTree have 1 i.e whole Tree uptoNow also have one
    return false;
}
TNode* pruneTree(TNode* root) {
    bool z = pruneTreeHelp(root);
    if (z){
        return root;
    }
    return NULL;
}

// ? 2306231808
void addLeafs(TNode* root,vector<int>&l){
    if (root == NULL) return ;
    if (root->left == NULL && root->right == NULL){
        l.push_back(root->data);
        return ;
    }
    if (root->left != NULL) addLeafs(root->left,l);
    if (root->right != NULL) addLeafs(root->right,l);
}
bool leafSimilar(TNode* root1, TNode* root2) {
    vector<int>l1;
    addLeafs(root1,l1);
    vector<int>l2;
    addLeafs(root2,l2);
    int n1 = l1.size();
    int n2 = l2.size();
    if (n1 != n2) return false;
    for (int i = 0;i < n1;i++){
        if (l1[i] != l2[i]) return false;
    }
    return true;
}

// ? 2306231944
bool isIdenticalTrees(TNode* p, TNode* q) {
    if (p == nullptr && q == nullptr) {
        return true;
    }
    if (p == nullptr || q == nullptr) {
        return false;
    }
    if (p->data != q->data) {
        return false;
    }
    return isIdenticalTrees(p->left, q->left) && isIdenticalTrees(p->right, q->right);
}
bool isSubtree(TNode* root, TNode* subRoot) {
    if (root == nullptr) {
        return false;
    }
    if (isIdenticalTrees(root, subRoot)) {
        return true;
    }
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}

// ? 2306232157
int longestUnivaluePath(TNode* root,int& maxCount){
    if (root == NULL) return 0;
    int l = longestUnivaluePath(root->left,maxCount);
    int r = longestUnivaluePath(root->right,maxCount);
    int ans = 1;
    int ll = 0;
    int rr = 0;
    if (root->left != NULL && root->left->data == root->data){
        ans += l;
        ll = l;
    }
    if (root->right != NULL && root->right->data == root->data){
        ans += r;
        rr = r;
    }
    maxCount = max(maxCount,ans);
    return 1 + max(ll,rr);
}

// ? 2406230816
void inOrderCreate(TNode* root,TNode*& prev){
    if (root == NULL) return ;
    inOrderCreate(root->left,prev);
    prev->right = root;
    prev->left = NULL;
    prev = root;
    inOrderCreate(root->right,prev);
}
TNode* increasingBST(TNode* root) {
    TNode* newRoot = new TNode(0);
    TNode* prev = newRoot;
    inOrderCreate(root,prev);
    prev->left = NULL;
    return newRoot->right;
}

// ? 2406230847
vector<TNode*>possibleFullTrees(int l,int r){
    if (l > r) return {NULL};
    if (l == r) return {new TNode(0)};
    vector<TNode*>trees;
    for(int i = l;i <= r;i++){
        if ((i - l)%2 != 0 && (r - i)%2 != 0){
            vector<TNode*>leftTrees = possibleFullTrees(l,i-1);
            vector<TNode*>rightTrees = possibleFullTrees(i+1,r);
            for (auto l : leftTrees){
                for(auto r : rightTrees){
                    TNode* t = new TNode(0);
                    t->left = l;
                    t->right = r;
                    trees.push_back(t);
                }
            }
        }
    }
    return trees;
}

// ? 2406231041
bool isUnivalTree(TNode* root) {
    if (root == NULL) return true;
    
    int l_val = (root->left == NULL) ? (root->data) : (root->left->data);
    int r_val = (root->right == NULL) ? (root->data) : (root->right->data);

    if (root->data == l_val && root->data == r_val){
        bool l = isUnivalTree(root->left);
        bool r = isUnivalTree(root->right);
        return (l && r);
    }
    return false;
}

// ? 2406231215
bool isCousins(TNode* root, int x, int y) {
    if (root->data == x || root->data == y) return false;
    int xRow = 0;
    int yRow = 0;
    int xParent = 0;
    int yParent = 0;
    queue<pair<TNode*,int>>q;
    q.push({root,0});
    while (q.empty() == false){
        int s = q.size();
        for (int i = 0; i < s;i++){
            TNode* f = q.front().first;
            int yy = q.front().second;
            q.pop();
            if (f->left != NULL){
                if (f->left->data == x){
                    xRow = yy+1;
                    xParent = f->data;
                }else if (f->left->data == y){
                    yRow = yy+1;
                    yParent = f->data;
                }
                q.push({f->left,yy+1});
            }
            if (f->right != NULL){
                if (f->right->data == x){
                    xRow = yy+1;
                    xParent = f->data;
                }else if (f->right->data == y){
                    yRow = yy+1;
                    yParent = f->data;
                }
                q.push({f->right,yy+1});
            }
        }
    }
    if (xRow != yRow) return false;
    if (xParent == yParent) return false;
    return true;
}

// ? 2406231252
TNode* createTreePrePost(vector<int>&preOrder,vector<int>&postOrder,unordered_map<int,int>&postMap,unordered_map<int,int>&preMap,int l,int r){
    if (l > r) return NULL;
    if (l == r) return (new TNode(preOrder[l]));
    TNode* t = new TNode(preOrder[l]);
    int i = postMap[preOrder[l]];
    int ii = preMap[postOrder[i-1]];      
    t->left = createTreePrePost(preOrder,postOrder,postMap,preMap,l+1,ii-1);
    t->right = createTreePrePost(preOrder,postOrder,postMap,preMap,ii,r);
    return t;
}
TNode* constructFromPrePost(vector<int>preOrder,vector<int>postOrder) {
    int n = preOrder.size();
    unordered_map<int,int>postMap;
    unordered_map<int,int>preMap;
    for (int i = 0;i < n;i++){
        postMap[postOrder[i]] = i;
        preMap[preOrder[i]] = i;
    }
    TNode* t = createTreePrePost(preOrder,postOrder,postMap,preMap,0,n-1);
    return t;
}

// ? 2406231526
pair<int,TNode*>subtreeWithAllDeepest(TNode* root){
    if (root == NULL) return {0,NULL};
    pair<int,TNode*>l = subtreeWithAllDeepest(root->left);
    pair<int,TNode*>r = subtreeWithAllDeepest(root->right);
    if (l.first == r.first){
        return {(1 + l.first),root};
    }
    if (l.first > r.first){
        return {(1 + l.first),l.second};
    }
    return {(1 + r.first),r.second};
}

// ? 2406231552
void allLeafRootStrings(vector<string>&words,string s,TNode* root){
    if (root == NULL) return ;

    char r = (char)(root->data + 97); // ascii value of a = 97
    s = r + s;
    if (root->left == NULL && root->right == NULL){
        words.push_back(s);
        return ;
    }
    if (root->left != NULL) allLeafRootStrings(words,s,root->left);
    if (root->right != NULL) allLeafRootStrings(words,s,root->right);
}
string smallestStringFromLeaf(TNode* root) {
    vector<string>words;
    allLeafRootStrings(words,"",root);
    sort(words.begin(),words.end());
    return words[0];
}

// ? 2406231913
TNode* addOneRowTree(TNode* root, int val, int depth) {
    if (depth == 0) return root;
    if (depth == 1){
        TNode* t = new TNode(val);
        t->left = root;
        t->right = NULL;
        return t;
    }
    queue<TNode*>q;
    q.push({root});
    vector<TNode*>level;
    while (q.empty() == false && depth > 1){
        level = {};
        int s = q.size();
        for (int i = 0;i < s;i++){
            TNode* f = q.front();
            q.pop();
            if (f->left != NULL) q.push(f->left);
            if (f->right != NULL) q.push(f->right);
            level.push_back(f);
        }
        depth--;
    }
    // insert below level
    for (auto n : level){
        TNode* l = n->left;
        TNode* r = n->right;
        n->left = new TNode(val);
        n->right = new TNode(val);
        n->left->left = l;
        n->right->right = r;
    }
    return root;
}

// ? 2406232111
TNode* mergeTrees(TNode* t1, TNode* t2){
    // merging tree2 into tree1
    if (t1 == NULL){
        return t2;
    }
    if (t2 == NULL){
        return t1;
    }
    t1->data += t2->data;
    t1->left = mergeTrees(t1->left,t2->left);
    t1->right = mergeTrees(t1->right,t2->right);
    return t1;
}

// ? 2406232141
TNode* trimBST(TNode* root, int low, int high) {
    if (root == NULL) return NULL;
    if (root->data < low){
        // all left of root < low = deleted
        return trimBST(root->right,low,high);
    }
    if (root->data > high){
        // all right of root > high = deleted
        return trimBST(root->left,low,high);
    }
    root->left = trimBST(root->left,low,high);
    root->right = trimBST(root->right,low,high);
    return root;
}

// ? 2506230627
void maxConsectutive1(vector<int>arr,int k){
    int max1 = 0;
    int l = 0;
    int cnt0 = 0;
    int n = arr.size();
    for (int r = 0; r < n; r++) {
        if (arr[r] == 0) {
            cnt0++;
        }
        while (cnt0 > k) {
            if (arr[l] == 0) {
                cnt0--;
            }
            l++;
        }
        max1 = max(max1, r - l + 1);
    }
    printVector(arr);
    cout << max1 << endl;
}

// ? 2506230632
void rotateMatrixElement(vector<vector<int>>mat){
    printGrid(mat);
    int n = mat.size();
    int m = mat[0].size();
    // Write your code here
    int left = 0 , right = m-1 , top  = 0 ,bottom = n-1;

    while(left < right && top < bottom ){
        int temp = mat[top][left];
        for(int col = left+1; col <= right; col++){
            int k = mat[top][col];
            mat[top][col] = temp;
            temp = k;
        }
        top++;

        for(int row = top; row <= bottom; row++){
            int k = mat[row][right];
            mat[row][right] = temp;
            temp = k;
        }
        right--;

        for(int col = right; col >= left; col--){
            int k = mat[bottom][col];
            mat[bottom][col] = temp;
            temp = k;
        }
        bottom--;

        for(int row = bottom; row >= top; row--){
            int k = mat[row][left];
            mat[row][left] = temp;
            temp = k;
        }
        left++;

        mat[top-1][left-1] = temp;
    }
    printGrid(mat);
}

// ? 2506231217
void bfsOfGraph(int v, vector<vector<int>>adj) {
    // v = no of nodes, if (v = 4 -> {0,1,2,3,4} of size v + 1)
    vector<int>bfs;
    vector<int>vis(v+1,0);
    queue<int>q;
    q.push(0);
    vis[0] = 1;
    while (q.empty() == false){
        int s = q.size();
        for (int i = 0;i < s;i++){
            int f = q.front();
            q.pop();
            bfs.push_back(f);
            for (auto it : adj[f]){
                if (vis[it] == 0){
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
    }
    printVector(bfs);
}

// ? 2506231234
void dfs_Help(int n,vector<int>&vis,vector<int>&dfs,vector<vector<int>>adj){
    vis[n] = 1;
    dfs.push_back(n);
    for (auto it : adj[n]){
        if (vis[it] == 0){
            dfs_Help(it,vis,dfs,adj);
        }
    }
}
void dfsOfGraph(int v, vector<vector<int>> adj) {
    vector<int>dfs;
    vector<int>vis(v+1,0);
    dfs_Help(0,vis,dfs,adj);
    printVector(dfs);
}

// ? 2506231237
void dfsProvinces(int n,vector<int>adjLs[],int vis[]){
    vis[n] = 1;
    for(auto it : adjLs[n]){
        if (vis[it] == 0){
            dfsProvinces(it,adjLs,vis);
        }
    }
}
int numProvinces(vector<vector<int>> adj, int v) {
    vector<int>adjLs[v];
    for(int i = 0;i < v;i++){
        for(int j = 0;j < v;j++){
            if (adj[i][j] == 1 && i != j){
                adjLs[i].push_back(j);
                adjLs[j].push_back(i);
            }
        }
    }
    int vis[v] = {0};
    int cnt = 0;
    for (int i = 0;i < v;i++){
        if (vis[i] == 0){
            cnt++;
            dfsProvinces(i,adjLs,vis);        
        }
    }
    return cnt;
}

// ? 2506231521
void numIslands(vector<vector<int>>grid) {
    printGrid(grid);
    int r = grid.size();
    int c = grid[0].size();
    int cnt = 0;
    for (int i = 0;i < r;i++){
        for (int j = 0;j < c;j++){
            if (grid[i][j] == 1){
                cnt++;
                // bfs
                queue<pair<int,int>>q;
                q.push({i,j});
                grid[i][j] = '0'; // mark visited 
                while (q.empty() == false){
                    pair<int,int>f = q.front();
                    int x1 = f.first;
                    int y1 = f.second;
                    q.pop();
                    // all 8 directions
                    vector<pair<int,int>>dir = {{0,1},{1,0},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}}; 
                    for(auto it: dir){
                        int x2 = it.first;
                        int y2 = it.second;
                        if (x1 + x2 >= 0 && x1 + x2 < r && y1 + y2 >= 0 && y1 + y2 < c){
                            if (grid[x1+x2][y1+y2] == 1){
                                grid[x1+x2][y1+y2] = 0;
                                q.push({x1+x2,y1+y2});
                            }
                        }
                    }
                }
                // bfs
            }
        }
    }
    cout << "islands : " << cnt << endl;
}

// ? 2506231534
void orangesRotting(vector<vector<int>>grid){
    printGrid(grid);
    int r = grid.size();
    int c = grid[0].size();
    int time = 0;
    queue<vector<int>>q; // x y time
    for (int i = 0;i < r;i++){
        for (int j = 0;j < c;j++){
            if (grid[i][j] == 2){
                q.push({i,j,0});
            }
        }
    }
    //bfs
    while (q.empty() == false){
        int s = q.size();
        for (int i = 0;i < s;i++){
            vector<int>f = q.front();
            q.pop();
            int x1 = f[0];
            int y1 = f[1];
            int t = f[2];
            time = max(time,t);
            // all 4 directions
            vector<pair<int,int>>dir = {{0,1},{1,0},{-1,0},{0,-1}}; 
            for(auto it: dir){
                int x2 = it.first;
                int y2 = it.second;
                if (x1 + x2 >= 0 && x1 + x2 < r && y1 + y2 >= 0 && y1 + y2 < c){
                    if (grid[x1+x2][y1+y2] == 1){
                        grid[x1+x2][y1+y2] = 2;
                        q.push({x1+x2,y1+y2,t+1});
                    }
                }
            }
        }
    }
    // bfs
    // lastly check if all oranges are rotted or not
    for (int i = 0;i < r;i++){
        for (int j = 0;j < c;j++){
            if (grid[i][j] == 1){
                cout << "-1" << endl;
            }
        }
    }
    cout << "time : " << time << endl;
}

// ? 2506231552
void floodFill(vector<vector<int>>image, int sr, int sc, int newColor){
    printGrid(image);
    int r = image.size();
    int c = image[0].size();
    
    int initialColor = image[sr][sc]; // only initalColor nodes attatched with sr,sc will get effected
    queue<pair<int,int>>q;
    image[sr][sc] = -1; // mark
    q.push({sr,sc});
    // bfs
    while (q.empty() == false){
        int s = q.size();
        for (int i = 0;i < s;i++){
            int x1 = q.front().first;
            int y1 = q.front().second;
            q.pop();
            vector<pair<int,int>>dir = {{0,1},{1,0},{-1,0},{0,-1}}; 
            for(auto it: dir){
                int x2 = it.first;
                int y2 = it.second;
                if (x1 + x2 >= 0 && x1 + x2 < r && y1 + y2 >= 0 && y1 + y2 < c){
                    if (image[x1+x2][y1+y2] == initialColor){
                        image[x1+x2][y1+y2] = -1;
                        q.push({x1+x2,y1+y2});
                    }
                }
            }
        }
    }
    // bfs
    for (int i = 0;i < r;i++){
        for (int j = 0;j < c;j++){
            if (image[i][j] == -1) image[i][j] = newColor;
        }
    }
    printGrid(image);
}

// ? 2506231745
void nearest10(vector<vector<int>>grid){
    printGrid(grid);
    int n = grid.size(); 
    int m = grid[0].size(); 
    vector<vector<int>> vis(n, vector<int>(m, 0)); 
    vector<vector<int>> dist(n, vector<int>(m, 0)); 
    // <coordinates, steps>
    queue<pair<pair<int,int>, int>> q; 
    for(int i = 0;i<n;i++) {
        for(int j = 0;j<m;j++) {
            // start BFS if cell contains 1
            if(grid[i][j] == 1) {
                q.push({{i,j}, 0}); 
                vis[i][j] = 1; 
            }
        }
    }
    
    int delrow[] = {-1, 0, +1, 0}; 
    int delcol[] = {0, +1, 0, -1}; 
    
    while(!q.empty()) {
        int row = q.front().first.first; 
        int col = q.front().first.second; 
        int steps = q.front().second; 
        q.pop(); 
        dist[row][col] = steps; 
        // for all 4 neighbours
        for(int i = 0;i<4;i++) {
            int nrow = row + delrow[i]; 
            int ncol = col + delcol[i]; 
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0) {
                vis[nrow][ncol] = 1; 
                q.push({{nrow, ncol}, steps+1});  
            }
        }
    }
    printGrid(dist);
}

// ? 2606230825
void replace01(vector<vector<int>> mat){
    printGrid(mat);
    int n = mat.size();
    int m = mat[0].size();
    queue<pair<int,int>>q;
    
    for (int j = 0;j < m;j++){
        if (mat[0][j] == 0){ // top row
            mat[0][j] = -1;
            q.push({0,j});
        }
        if (mat[n-1][j] == 0){ // bottom row
            mat[n-1][j] = -1;
            q.push({n-1,j});
        }
    }
    for (int i = 1;i < n-1;i++){
        if (mat[i][0] == 0){
            mat[i][0] = -1;
            q.push({i,0});
        }
        if (mat[i][m-1] == 0){
            mat[i][m-1] = -1;
            q.push({i,m-1});
        }
    }
    
    // bfs from boundary 'O'
    while (q.empty() == false){
        int x1 = q.front().first;
        int y1 = q.front().second;
        q.pop();
        vector<pair<int,int>>dir = {{0,1},{1,0},{-1,0},{0,-1}}; 
        for(auto it: dir){
            int x2 = it.first;
            int y2 = it.second;
            if (x1 + x2 >= 0 && x1 + x2 < n && y1 + y2 >= 0 && y1 + y2 < m){
                if (mat[x1+x2][y1+y2] == 0){
                    mat[x1+x2][y1+y2] = -1;
                    q.push({x1+x2,y1+y2});
                }
            }
        }
    }
    for (int i = 0;i < n;i++){
        for (int j = 0;j < m;j++){
            if (mat[i][j] == 0) mat[i][j] = 1;
            if (mat[i][j] == -1) mat[i][j] = 0;
        }
    }
    printGrid(mat);
}

// ? 2606231029
int numberOfEnclaves(vector<vector<int>>grid) {
    int r = grid.size();
    int c = grid[0].size();
    int cnt = 0;
    
    queue<pair<int,int>>q;
    
    /// bfs from boundary 1's
    for(int i = 0;i < r;i++){
        if (grid[i][0] == 1){
            grid[i][0] = 0;
            q.push({i,0});
        }
        if (grid[i][c-1] == 1){
            grid[i][c-1] = 0;
            q.push({i,c-1});
        }
    }
    for (int j = 1;j < c-1;j++){
        if (grid[0][j] == 1){
            grid[0][j] = 0;
            q.push({0,j});
        }
        if (grid[r-1][j] == 1){
            grid[r-1][j] = 0;
            q.push({r-1,j});
        }
    }
    
    while (q.empty() == false){
        int x1 = q.front().first;
        int y1 = q.front().second;
        q.pop();
        vector<pair<int,int>>dir = {{0,1},{1,0},{-1,0},{0,-1}}; 
        for(auto it: dir){
            int x2 = it.first;
            int y2 = it.second;
            if (x1 + x2 >= 0 && x1 + x2 < r && y1 + y2 >= 0 && y1 + y2 < c){
                if (grid[x1+x2][y1+y2] == 1){
                    grid[x1+x2][y1+y2] = 0;
                    q.push({x1+x2,y1+y2});
                }
            }
        }
    }
    
    for (int i = 0;i < r;i++){
        for (int j = 0;j < c;j++){
            if (grid[i][j] == 1) cnt++;
        }
    }
    
    return cnt;
}

// ? 2606231716
void countDistinctIslands(vector<vector<int>>grid) {
    int r = grid.size();
    int c = grid[0].size();
    
    set<vector<pair<int,int>>>st;
    
    for (int i = 0;i < r;i++){
        for (int j = 0;j < c;j++){
            if (grid[i][j] == 1){
                
                vector<pair<int,int>>isLand;       
                grid[i][j] = 0;
                queue<pair<pair<int,int>,pair<int,int>>>q; // {global cordinates, isLand cordinates}     
                q.push({{i,j},{0,0}});
                while (q.empty() == false){
                    int x1 = q.front().first.first;
                    int y1 = q.front().first.second;
                    int x = q.front().second.first;
                    int y = q.front().second.second;
                    isLand.push_back({x,y});
                    q.pop();
                    vector<pair<int,int>>dir = {{0,1},{1,0},{-1,0},{0,-1}}; 
                    for(auto it: dir){
                        int x2 = it.first;
                        int y2 = it.second;
                        if (x1 + x2 >= 0 && x1 + x2 < r && y1 + y2 >= 0 && y1 + y2 < c){
                            if (grid[x1+x2][y1+y2] == 1){
                                grid[x1+x2][y1+y2] = 0;
                                q.push({{x1+x2,y1+y2},{x+x2,y+y2}});
                            }
                        }
                    }
                }
                st.insert(isLand);
            }
        }
    }
    
    cout << "Distinct isLands : " << st.size() << endl;
}

// ? 2606231753
void isCycleGraphBFS(int v, vector<int> adj[]) {
    int vis[v] = {0};
    queue<int>q;
    for (int i = 0;i < v;i++){
        if (vis[i] == 0){
            vis[i] = 1; 
            queue<pair<int,int>> q; // store <source node, parent node>
            q.push({i, -1}); 
            while(!q.empty()) {
                int node = q.front().first; 
                int parent = q.front().second; 
                q.pop(); 
                for(auto adjacentNode: adj[node]) {
                    if(!vis[adjacentNode]) {
                        vis[adjacentNode] = 1; 
                        q.push({adjacentNode, node}); 
                    }
                    else if(parent != adjacentNode) {
                        cout << "cycle" << endl;
                        return ; 
                    }
                }
            }
        }
    }
    cout << "No cycle" << endl;
}

// ? 2606231758
bool cycleDFS(int n,int parent,vector<int>adj[],int vis[]){
    vis[n] = 1;
    for (auto adjNode : adj[n]){
        if (vis[adjNode] == 0){
            if (cycleDFS(adjNode,n,adj,vis)) return true;
        }else{
            if(adjNode != parent) return true;
        }
    }
    return false;
}
void isCycleGraphDFS(int v, vector<int> adj[]) {
    int vis[v] = {0};
    for (int i = 0;i < v;i++){
        if (vis[i] == 0){
            if (cycleDFS(i,-1,adj,vis)){ 
                cout << "Cycle" << endl;
                return ;
            }
        }
    }
}

// ? 2606231812
void isGraphBipartiteBFS(int v, vector<int>adj[]){
    int vis[v] = {0};
    int color[v] = {0}; // 0 = noColor, [1,2]
    queue<int>q; // node, color
    for (int i = 0;i < v;i++){
        if (vis[i] == 0){
            q.push(i);
            vis[i] = 1;
            color[i] = 1;
            while (q.empty() == false){
                int f = q.front();
                int c = color[f];
                q.pop();
                for(auto adjNode : adj[f]){
                    if (vis[adjNode] == 0){
                        vis[adjNode] = 1;
                        color[adjNode] = (c == 1) ? 2 : 1;
                        q.push(adjNode);
                    }else if (color[adjNode] == c){ 
                        cout << "Not Bipartite" << endl;
                        return ;
                    }
                }
            }
        }
    }
    cout << "Biparite" << endl;
}

// ? 2606231838
bool bipartiteDFS(int n,int c,vector<int>adj[],int color[]){
    color[n] = c;
    for (auto adjNode : adj[n]){
        if (color[adjNode] == 0){
            int x = (c == 1) ? 2 : 1;
            if (bipartiteDFS(adjNode,x,adj,color) == false) return false;
        }else{
            if (color[adjNode] == c) return false;
        }
    }
    return true;
}
void isGraphBipartiteDFS(int v, vector<int>adj[]){
    int color[v] = {0}; // 0 = noColor, [1,2]
    for (int i = 0;i < v;i++){
        if (color[i] == 0){
            if (bipartiteDFS(i,1,adj,color) == false){
                cout << "Not Bipartite" << endl;
                return ;
            }
        }
    }
    cout << "Bipartite" << endl;
}

// ? 2606231917
bool directedCycleDFS(int n,int vis[],vector<int>adj[]){
    vis[n] = 1;
    vis[n] = 2; // marking the path
    for (auto adjNode : adj[n]){
        if (vis[adjNode] == 0){
            if (directedCycleDFS(adjNode,vis,adj)) return true; 
        }else if (vis[adjNode] == 2) return true;
    }
    vis[n] = 1; // as it is undirected graph, removing path after traversal
    return false;
}
void isDirectedGraphCyclicDFS(int v, vector<int> adj[]) {
    int vis[v] = {0}; // 0 non visited, 1 visited, 2 path visited
    for(int i = 0;i < v;i++){
        if (vis[i] == 0){
            if (directedCycleDFS(i,vis,adj)){
                cout << "cycle" << endl;
                return ;
            }
        }
    }
    cout << "no cycle" << endl;
}

// ? 2606232028
bool safeNodescycleDFS(int n,int vis[],vector<int>adj[],int check[]){
    vis[n] = 1;
    vis[n] = 2;
    check[n] = 0;
    for(auto adjNode : adj[n]){
        if (vis[adjNode] == 0){
            if (safeNodescycleDFS(adjNode,vis,adj,check)){
                check[n] = 0;
                return true;
            }
        }else if (vis[adjNode] == 2){
            check[n] = 0;
            return true;
        }
    }
    vis[n] = 1;
    check[n] = 1;
    return false;
}
void eventualSafeNodes(int v, vector<int> adj[]) {
    vector<int>safeNodes;
    int vis[v] = {0}; // 0 not visited, 1 visited, 2 pathVisited
    int check[v] = {0};
    for (int i = 0;i < v;i++){
        if (vis[i] == 0){
            safeNodescycleDFS(i,vis,adj,check);           
        }
    }
    for (int i = 0;i < v;i++){
        if (check[i] == 1){
            safeNodes.push_back(i);
        }
    }
    printVector(safeNodes);
}

// ? 2706231113
void topoDFS(int n,int vis[],vector<int>adj[],vector<int>&ans){
    vis[n] = 1;
    for (auto adjNode : adj[n]){
        if (vis[adjNode] == 0){
            topoDFS(adjNode,vis,adj,ans);
        }
    }
    ans.push_back(n);
}
void topoSortDFS(int v, vector<int> adj[]) {
    vector<int>ans;
    int vis[v] = {0};
    for (int i = 0; i < v;i++){
        if (vis[i] == 0){
            topoDFS(i,vis,adj,ans);
        }
    }
    reverse(ans.begin(),ans.end());
    printVector(ans);
}

// ? 2706231133
void topoSortKhans(int v, vector<int> adj[]) {
    vector<int>ans;
    int degree[v] = {0};
    
    for (int i = 0;i < v;i++){
        for(auto it : adj[i]){
            degree[it]++;
        }
    }
    
    queue<int>q;
    // bfs from degree = 0
    for (int i = 0;i < v;i++){
        if (degree[i] == 0){
            q.push(i);
        }
    }
    
    while (q.empty() == false){
        int f = q.front();
        q.pop();
        ans.push_back(f);
        for (auto adjNode : adj[f]){
            degree[adjNode]--;
            if (degree[adjNode] == 0){
                q.push(adjNode);
            }
        }
    }
    
    printVector(ans);
}

// ? 2706231151
void isDirectedGraphCyclicKhans(int v, vector<int> adj[]) {
    int cnt = 0;
    int degree[v] = {0};
    for (int i = 0; i < v;i++){
        for (auto it : adj[i]){
            degree[it]++;
        }
    }
    queue<int>q;
    for (int i = 0;i<v;i++){
        if (degree[i] == 0) q.push(i);    
    }
    while (q.empty() == false){
        int f = q.front();
        q.pop();
        cnt++;
        for (auto adjNode : adj[f]){
            degree[adjNode]--;
            if (degree[adjNode] == 0) q.push(adjNode);
        }
    }
    if (cnt == v){
        cout << "no cycle" << endl;
        return ;
    }
    cout << "cycle" << endl;
}

// ? 2706231356
void courseSchedule1(int v,vector<vector<int>> preRequisites) {
    // converting preRequisites to graph
    // pre = {{1,0},{2,0}} => 0 have edges directed to 1,2
    // topoSort , -> degree[0] = 0, degree[1] = 1, degree[2] = 1;
    
    int degree[v] = {0};
    vector<int>ans;
    vector<int>adj[v] = {};
    
    for (auto edge : preRequisites){
        // edge from edge[1] to edge[0]
        degree[edge[0]]++;
        adj[edge[1]].push_back(edge[0]);
    }
    
    queue<int>q;
    for (int i = 0; i < v;i++){
        if (degree[i] == 0) q.push(i);
    }
    while (q.empty() == false){
        int f = q.front();
        q.pop();
        ans.push_back(f);
        for (auto adjNode : adj[f]){
            degree[adjNode]--;
            if (degree[adjNode] == 0) q.push(adjNode);
        }
    }
    
    if (ans.size() == v){
        printVector(ans); 
        return ; // no cycle
    }
    cout << "tasks cant be finished" << endl;
}

// ? 2706231411
void reverseEdgesSafeNodes(int v,vector<int>adj[],vector<int>adjReverse[]){
    for (int i = 0;i < v;i++){
        for (auto it : adj[i]){
            // actually edge from i to it
            adjReverse[it].push_back(i);
        }
    }
}
void eventualSafeNodesTopoSort(int v, vector<int> adj[]) {
    
    vector<int>adjReverse[v];
    reverseEdgesSafeNodes(v,adj,adjReverse);    // reverse edges
    
    vector<int>ans; // topo sort
    int degree[v] = {0};
    for (int i = 0;i < v;i++){
        for(auto it : adjReverse[i]){
            degree[it]++;
        }
    }
    
    queue<int>q;
    for (int i = 0;i < v;i++){
        if (degree[i] == 0){
            q.push(i);
        }
    }
    while (q.empty() == false){
        int f = q.front();
        q.pop();
        ans.push_back(f);
        for (auto adjNode : adjReverse[f]){
            degree[adjNode]--;
            if (degree[adjNode] == 0){
                q.push(adjNode);
            }
        }
    }
    sort(ans.begin(),ans.end());
    printVector(ans);
}

// ? 2706231500
void alienOrder(string dict[], int n, int k) {
    
    string order = "";
    
    vector<int>adj[k] = {}; // constructing a graph of size k
    int degree[k] = {0};
    
    for (int i = 0;i < n-1;i++){
        int x = min(dict[i].length(),dict[i+1].length());
        for(int j = 0; j < x;j++){
            if (dict[i][j] != dict[i+1][j]){
                // dict[i][j] appears before dict[i+1][j]
                adj[dict[i][j] - 'a'].push_back(dict[i+1][j] - 'a');
                degree[dict[i+1][j]-'a']++;
                break;
            }
        }
    }
    
    queue<int>q;
    for(int i = 0;i < k;i++){
        if (degree[i] == 0) q.push(i);
    }
    while (q.empty() == false){
        int f = q.front();
        q.pop();
        order = order + char(f + 'a');
        for (auto adjNode : adj[f]){
            degree[adjNode]--;
            if (degree[adjNode] == 0) q.push(adjNode);
        }
    }
    cout << "alien order : " << order << endl;
}

// ? 2706231621
void topoDAG(int n,stack<int>&topo,int vis[],vector<pair<int,int>>adj[]){
    vis[n] = 1;
    for (auto adjNode : adj[n]){
        if (vis[adjNode.first] == 0){
            topoDAG(adjNode.first,topo,vis,adj);
        }
    }
    topo.push(n);
}
void shortestPathDAG(int v,int src, vector<vector<int>>edges){
    vector<int>shortPath(v,1e9);
    shortPath[src] = 0;
    
    int vis[v] = {0};
    vector<pair<int,int>>adj[v]; // adj[i] = edges from i to adj[i].first with weight adj[i].second;
    for (auto edge : edges){
        adj[edge[0]].push_back({edge[1],edge[2]});
    }
    stack<int>topo;
    for (int i = 0;i < v;i++){
        if (vis[i] == 0){
            topoDAG(i,topo,vis,adj);
        }
    }
    while (topo.empty() == false){
        int f = topo.top();
        cout << f << " ";
        topo.pop();
        for (auto adjNode : adj[f]){
            if (shortPath[adjNode.first] > (shortPath[f] + adjNode.second)){
                shortPath[adjNode.first] = (shortPath[f] + adjNode.second);
            }
        }
    }
    for (int i = 0;i < v;i++){
        if (shortPath[i] == 1e9) shortPath[i] = -1;
    } 
    printVector(shortPath);
}

// ? 2706231712
void shortestPathUnitWeightGraph(vector<vector<int>>edges, int v, int src){
    vector<int>shortPath(v,-1);
    int vis[v] = {0};
    vector<int>adj[v];
    for (auto edge : edges){
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }
    queue<pair<int,int>>q; // node , dis
    vis[src] = 1;
    q.push({src,0});
    while (q.empty() == false){
        int f = q.front().first;
        int dis = q.front().second;
        q.pop();
        shortPath[f] = dis;
        for (auto adjNode : adj[f]){
            if (vis[adjNode] == 0){
                vis[adjNode] = 1;
                q.push({adjNode,dis+1});
            }
        }
    }
    printVector(shortPath);
}

// ? 2806230812
int wordLadderLength1(string startWord, string targetWord, vector<string>wordList) {
    int n = startWord.length();
    unordered_set<string>dict(wordList.begin(),wordList.end());
    if (dict.find(targetWord) == dict.end()) return 0;
    
    queue<pair<string,int>>q;
    q.push({startWord,1});
    dict.erase(startWord);
    
    while (q.empty() == false){
        string str = q.front().first;
        int cnt = q.front().second;
        q.pop();
        
        if (str == targetWord) return cnt;
        
        for (int i = 0;i < n;i++){
            char original = str[i];
            for (char j = 'a';j <= 'z';j++){
                str[i] = j;
                if (dict.find(str) != dict.end()){
                    q.push({str,cnt+1});
                    dict.erase(str);
                }
            }
            str[i] = original;
        }
        
    }
    
    return 0;
}

// ? 2806231026
void wordLadderLength2(string beginWord, string endWord, vector<string>wordList) {
    vector<vector<string>>ans;
    unordered_set<string>dict(wordList.begin(),wordList.end());
    if (dict.find(endWord) == dict.end()) return ;
    
    queue<vector<string>>q;
    q.push({beginWord});
    
    // A vector defined to store the words being currently used
    // on a level during BFS.
    vector<string> usedOnLevel;
    usedOnLevel.push_back(beginWord);
    
    int level = 0;

    while (q.empty() == false){
        vector<string>vec = q.front();
        q.pop();
        
        // Now, erase all words that have been
        // used in the previous levels to transform
        if (vec.size() > level){
            level++;
            for (auto it : usedOnLevel){
                dict.erase(it);
            }
        }
        
        string word = vec.back();

        // store the answers if the end word matches with targetWord.
        if (word == endWord){
            // the first sequence where we reached end
            if (ans.size() == 0){
                ans.push_back(vec);
            }
            else if (ans[0].size() == vec.size()){ // to find minTransformations
                ans.push_back(vec);
            }
        }

        for (int i = 0; i < word.size(); i++){   
            // Now, replace each character of ‘word’ with char
            // from a-z then check if ‘word’ exists in wordList.
            char original = word[i];
            for (char c = 'a'; c <= 'z'; c++)
            {
                word[i] = c;
                if (dict.count(word) > 0){ 
                    // Check if the word is present in the wordList and
                    // push the word along with the new sequence in the queue.
                    vec.push_back(word);
                    q.push(vec);
                    // mark as visited on the level
                    usedOnLevel.push_back(word);
                    vec.pop_back();
                }
            }
            word[i] = original;
        }
    }
    
    for (auto path : ans){
        for (auto w : path) cout << w << " -> ";
        cout << endl;
    }
}

// ? 2806231115
void dijkstra(int v, vector<vector<int>> adj[], int src){
    vector<int>dist(v,1e9);
    dist[src] = 0;
    
    priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int, int>>>pq;
    pq.push({0,src}); // dis, node  to reach src from src = 0; 
    
    while (pq.empty() == false){
        int d = pq.top().first;
        int f = pq.top().second;
        pq.pop();
        for (auto adjNode : adj[f]){
            if ((d + adjNode[1]) < dist[adjNode[0]]){
                dist[adjNode[0]] = d + adjNode[1];
                pq.push({dist[adjNode[0]],adjNode[0]});
            }
        }
    }
    for (int i = 0; i < v;i++){
        if (dist[i] == 1e9) dist[i] = -1;
    }
    printVector(dist);
}

// ? 2806231428
void shortestPathDijkstra(int src, int dest, int n, vector<vector<int>>edges) {
    
    int parent[n+1] = {-1};
    parent[src] = src;
    
    vector<int>dist(n+1,1e9);
    dist[src] = 0;
    
    vector<vector<int>>adj[n+1];
    for(auto edge : edges){
        adj[edge[0]].push_back({edge[1],edge[2]});
        adj[edge[1]].push_back({edge[0],edge[2]});
    }
    
    priority_queue<pair<int,int>, vector<pair<int,int>> ,greater<pair<int,int>> >pq;
    pq.push({0,src}); // dis, node to reach src from src = 0;
    
    while(pq.empty() == false){
        int d = pq.top().first;
        int f = pq.top().second;
        pq.pop();
        for (auto edge : adj[f]){
            if ( (d + edge[1]) < dist[edge[0]] ){
                dist[edge[0]] = d + edge[1];
                parent[edge[0]] = f;
                pq.push({dist[edge[0]],edge[0]});
            }
        }
    }
    if (dist[dest] == 1e9){
        cout << "no path found" << endl;
        return ;
    }
    
    vector<int>path = {}; // from dest -> src
    int temp = dest;
    while (true){
        path.push_back(temp);
        temp = parent[temp];
        if (temp == parent[temp]){
            path.push_back(temp); // reached src
            break;
        }
    }
    reverse(path.begin(),path.end());
    printVector(path);
}

// ? 2806231458
void shortestPathMaze(vector<vector<int>>grid, pair<int,int>src, pair<int,int>dest){
    int r = grid.size();
    int c = grid[0].size();
    
    if (grid[dest.first][dest.second] == 0 || grid[src.first][src.second] == 0){ 
        cout << "no path" << endl;
        return ;
    }
    
    queue<pair<int,pair<int,int>>>q;
    q.push({0,src});
    grid[src.first][src.second] = 0; // mark visited
    
    while (q.empty() == false){
        int d = q.front().first;
        int x1 = q.front().second.first;
        int y1 = q.front().second.second;
        q.pop();
        if (x1 == dest.first && y1 == dest.second){
            cout << d << endl;
            return ;
        }
        vector<pair<int,int>>dir = {{0,1},{1,0},{-1,0},{0,-1}}; 
        for(auto it: dir){
            int x2 = it.first;
            int y2 = it.second;
            if (x1 + x2 >= 0 && x1 + x2 < r && y1 + y2 >= 0 && y1 + y2 < c){
                if (grid[x1+x2][y1+y2] == 1){
                    grid[x1+x2][y1+y2] = 0;
                    q.push({d+1,{x1+x2,y1+y2}});
                }
            }
        }
    }
    cout << "no path" << endl;
}

// ? 2806231518
void maxProbabilityGraph(int v, vector<vector<int>>edges, vector<double>succProb, int src, int dest) {
    
    vector<double>prob(v,0.0);
    prob[src] = 1.0;

    vector<pair<int,double>>adj[v];
    for (int i = 0;i < edges.size();i++){
        adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
        adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
    }
    
    priority_queue<pair<double,int>>pq;
    pq.push({1.0,src});

    while (pq.empty() == false){
        double pro = pq.top().first;
        int f = pq.top().second;
        pq.pop();
        if (f == dest){
            cout << "max Probablity for " << src << " -> " << dest << " : " << pro << endl;
            return ; 
        }
        for (auto edge : adj[f]){
            if (pro * edge.second > prob[edge.first]){
                prob[edge.first] = pro*edge.second;
                pq.push({prob[edge.first],edge.first});
            }
        }
    }
    
    cout << "no path : probabilty : 0 " << endl;
}

// ? 2806231923
void MinimumEffortGrid(vector<vector<int>>heights){
    int r = heights.size();
    int c = heights[0].size();
    
    vector<vector<int>>dist(r,vector<int>(c,1e9));
    dist[0][0] = 0;
    
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
    pq.push({0,{0,0}}); // dis, {coords}        
    
    while (pq.empty() == false){
        int d = pq.top().first;
        int x1 = pq.top().second.first;
        int y1 = pq.top().second.second;
        pq.pop();
        
        if (x1 == r-1 && y1 == c-1){
            cout << "min effort : " << d << endl;
            return ;
        }
        
        vector<pair<int,int>>dir = {{0,1},{1,0},{-1,0},{0,-1}}; 
        for(auto it: dir){
            int x2 = it.first;
            int y2 = it.second;
            if (x1 + x2 >= 0 && x1 + x2 < r && y1 + y2 >= 0 && y1 + y2 < c){

                int newDistance = max(abs(heights[x1][y1] - heights[x1+x2][y1+y2]), d);
                
                if (newDistance < dist[x1+x2][y1+y2]){
                    dist[x1+x2][y1+y2] = newDistance;
                    pq.push({newDistance,{x1+x2,y1+y2}});
                }
                
            }
        }
    }
    cout << "un reachable" << endl;
}

// ? 2806232002
void CheapestFlight(int v, vector<vector<int>>flights, int src, int dst, int k)  {
    int dist[v];
    for (int i = 0;i < v;i++) dist[i] = 1e9;
    dist[src] = 0;
    
    vector<pair<int,int>>adj[v];
    for(auto edge : flights){
        adj[edge[0]].push_back({edge[1],edge[2]});
    }
    
    queue<pair<int,pair<int,int>>>q;
    q.push({0,{src,0}}); // q = {stops,{node, price}}
    
    while (q.empty() == false){
        int stops = q.front().first;
        int node = q.front().second.first;
        int price = q.front().second.second;
        q.pop();
        
        if (stops <= k){
            for(auto it : adj[node]){
                int adjNode = it.first;
                int cost = it.second;
                if (price + cost < dist[adjNode]){
                    dist[adjNode] = price + cost;
                    q.push({stops+1,{adjNode,dist[adjNode]}});
                }
            }    
        }
    }
    
    if (dist[dst] == 1e9){
        cout << "no path" << endl;
        return ; // no path withIn K stops
    }
    cout << dist[dst] << endl;
}

// ? 2906230747
int minimumMultiplications(vector<int>arr, int start, int end) {
    vector<int>cnt(100000,1e9);
    cnt[start] = 0;
    
    queue<pair<int,int>>q; // {no of multiplications, num}
    q.push({0,start});
    
    while (q.empty() == false){
        int steps = q.front().first;
        int n = q.front().second;
        q.pop();
        if (n == end) return steps;
        for (auto it : arr){
            int n1 = (n * it) % 100000;
            if (steps + 1  < cnt[n1]){
                cnt[n1] = steps+1;
                q.push({steps+1,n1});
            } 
        }
    }
    return -1;
}

// ? 2906231036
void bellman_ford(int v, vector<vector<int>>edges, int src) {
    vector<int>dist(v,1e8);
    dist[src] = 0;
    for (int i = 0; i < v;i++){
        for (auto it : edges){
            int a = it[0];
            int b = it[1];
            int d = it[2];
            if (dist[a] != 1e9 && dist[a] + d < dist[b]){
                dist[b] = dist[a] + d;
            }
        }
    } // if the graph is normal the dist[] won't update anymore, we found the shortPath from src to all nodes
    // now even after v-1 iterations if again we got shortPath i.e the path is negative
    for (auto it : edges) {
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
            // if any dist decreases even after n iterations then we have negative cycle
            cout << "negative cycle" << endl;
            return ;
        }
    }
    printVector(dist);
}

// ? 2906231052
void floydWarshall(vector<vector<int>>matrix){
    
    int v = matrix.size();
    printGrid(matrix);

    for (int a = 0; a < v;a++){
        for (int b = 0; b < v;b++){
            if (matrix[a][b] == -1) matrix[a][b] = 1e9;                    
        }
    }
    for (int i = 0; i < v;i++){
        for (int a = 0; a < v;a++){
            for (int b = 0; b < v;b++){
                if (matrix[a][i] + matrix[i][b] < matrix[a][b]){
                    matrix[a][b] = (matrix[a][i] + matrix[i][b]); 
                }
            }
        }
    }
    for (int a = 0; a < v;a++){
        for (int b = 0; b < v;b++){
            if (matrix[a][b] == 1e9) matrix[a][b] = -1;                    
        }
    }
    printGrid(matrix);
}

// ? 2906231141
void cityWithLessNeighbours(int v, vector<vector<int>> edges,int distanceThreshold){
    vector<vector<int>>matrix(v,vector<int>(v,1e9));
    for (int i = 0;i < v;i++){
        matrix[i][i] = 0;
    }
    for (auto it : edges){
        matrix[it[0]][it[1]] = it[2];
        matrix[it[1]][it[0]] = it[2];
    }
    
    for (int i = 0; i < v;i++){
        for (int a = 0; a < v;a++){
            for (int b = 0; b < v;b++){
                if (matrix[a][i] + matrix[i][b] < matrix[a][b]){
                    matrix[a][b] = (matrix[a][i] + matrix[i][b]); 
                }
            }
        }
    }
    
    int ans = -1;
    int neighboursCnt = INT_MAX;
    
    for (int a = 0; a < v;a++){
        int cnt_a = 0;
        for (int b = 0; b < v;b++){
            if (matrix[a][b] <= distanceThreshold){
                cnt_a++;
            }
        }
        if (cnt_a <= neighboursCnt){
            neighboursCnt = cnt_a;
            ans = a;
        }
    }
    cout << ans  << " : "  << neighboursCnt << " neighbours " << endl;
}

// ? 2906231234
void minTimeTravel(vector<vector<int>>grid){
    int r = grid.size();
    int c = grid[0].size();
    vector<vector<int>>dist(r,vector<int>(c,1e9));
    dist[0][0] = 0;
    
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
    pq.push({0,{0,0}});
    
    while (pq.empty() == false){
        int t1 = pq.top().first;
        int x1 = pq.top().second.first;
        int y1 = pq.top().second.second;
        pq.pop();
        vector<pair<int,int>>dir = {{0,1},{1,0},{-1,0},{0,-1}}; 
        for(auto it: dir){
            int x2 = it.first;
            int y2 = it.second;
            if (x1 + x2 >= 0 && x1 + x2 < r && y1 + y2 >= 0 && y1 + y2 < c){
                int newDist = max(t1,grid[x1+x2][y1+y2]);
                newDist = max(newDist,grid[x1][y1]);
                if (newDist < dist[x1+x2][y1+y2]){
                    dist[x1+x2][y1+y2] = newDist;
                    pq.push({newDist,{x1+x2,y1+y2}});
                }
            }
        }
    }
    cout << "time : " << dist[r-1][c-1] << endl;
}

int main(){
    cout << endl;

    // ? 0106231625
    // bubbleSort({10,5,2,1,3,8,6});

    // ? 0106231657
    // selectionSort({6,7,3,1,5,8,2});

    // ? 0106231926
    // insertionSort({10,5,2,1,3,8,6});

    // ? 0106231948
    // mergeTwoSortedVectors({1,4,6,8,10},{2,3,7,9});

    // ? 0106232013
    // vector<int>v = {5,2,3,1,6,4,8,7};
    // printVector(v);
    // mergeSort(v,0,v.size()-1);
    // printVector(v);

    // ? 0206230938
    // countSort({1,0,2,2,1,3,4,3});

    // ? 0206230954
    // vector<int>v = {4,6,2,5,7,9,1,3};
    // printVector(v);
    // quickSort(v,0,v.size()-1);
    // printVector(v);

    // ? 0206231026
    // largestEle({4,2,6,1,3,5,7,2});

    // ? 0206231037
    // secondLargestEle({1,4,2,6,3,7});

    // ? 0206231043
    // checkSorted({1,2,3,4,4,5,5,8});

    // ? 0206231053
    // removeDuplicates({1,2,2,3,4,4,4,5});

    // ? 0206231107
    // leftRotate1({3,1,2,4,5});

    // ? 0206231108
    // leftRotateK({4,5,2,1,6,7,3,8},3);

    // ? 0206231208
    // moveZerosEnd({4,2,0,1,0,3,1,2,0});

    // ? 0206231216
    // linearSearch({12,15,17,20,25},15);

    // ? 0206231224
    // unionAB({2,2,3,4,5},{1,1,2,3,4});

    // ? 0206231256
    // intersectionAB({1,2,2,2,3,4},{2,2,3,3});

    // ? 0206231351
    // missingNumber({1,4,3},4);

    // ? 0206231359
    // maxConsecutive1s({0,1,1,1,1,0,0,1,1,1});

    // ? 0206231406
    // appearonce({1,3,1,2,3,4,4});

    // ? 0206231421
    // rowWithMax1s({{0,1,1,1},{1,1,1,1},{0,0,1,1},{0,0,0,1}});

    // ? 0206231429
    // longestSubArraySumPosK({1,2,3,1,1,1,1,3,3},6);

    // ? 0206231514
    // longestSubArraySumPosNegK({-13,0,6,15,16,2,15,-12,17,-16,0,-3,19,-3,2,-9,-6},15);

    // ? 0206231748
    // pairWithSumK({4,1,2,3,1},5);

    // ? 0206231805
    // majorityElement({2,2,3,3,1,3,3});

    // ? 0206231823
    // maxSumSubArray({1,2,3,-2,5});

    // ? 0206231844
    // maxSumPair({4,3,1,5,6});

    // ? 0206231858
    // alternatePosNeg({-5, -2, 5, 2, 4, 7, 1, 8, 0, -8});

    // ? 0206231912
    // nextPermutation({2,1,5,4,3,0});

    // ? 0206231948
    // leaders({16,17,4,3,5,2});

    // ? 0206231958
    // longestConsecutiveSeq({102,4,100,1,101,3,2,1});

    // ? 0206232012
    // setZerosMatrix({{1,1,1,1},{0,1,0,1},{1,1,0,1},{1,1,1,1}});

    // ? 0206232029
    // rotateMatrix({{1, 2, 3},{4, 5, 6},{7, 8, 9}});

    // ? 0206232038
    // printSpiral({{505,614},{962,755},{327,266},{945,203},{203,507},{785,22}});

    // ? 0306231018
    // pascalTriangle(74);

    // ? 0306231053
    // threeSum({-1,-1,2,0,1});

    // ? 0306231122
    // fourSum({1,0,-1,0,-2,2},0);

    // ? 0306231152
    // longestSubArraySumZero({15,-2,2,-8,1,7,10,23});

    // ? 0306231410
    // LLNode* l = buildList({1,3,2,4});
    // printList(l);
    // l = insertNodeEnd(l,5);
    // l = insertNodeBegin(l,7);
    // printList(l);

    // ? 0306231419
    // LLNode* l = buildList({1,3,2,4});
    // printList(l);
    // l = deleteNodeX(l,3);
    // printList(l);

    // ? 0306231427
    // LLNode* l = buildList({1,3,4,2,5,6});
    // printList(l);
    // listLength(l);
    
    // ? 0306231433
    // LLNode* l = buildList({1,3,4,2,5,6});
    // printList(l);
    // getMiddleList(l);

    // ? 0306231441
    // LLNode* l = buildList({1,3,4,2,5,6});
    // printList(l);
    // l = reverseList(l);
    // printList(l);

    // ? 0606230746
    // LLNode* l = new LLNode(1);
    // l->next = new LLNode(2);
    // l->next->next = new LLNode(3);
    // l->next->next->next = new LLNode(4);
    // l->next->next->next->next = new LLNode(5);
    // l->next->next->next->next->next = l->next->next;
    // checkCycleList(l);

    // ? 0606230759
    // LLNode* l = new LLNode(1);
    // l->next = new LLNode(2);
    // l->next->next = new LLNode(3);
    // l->next->next->next = new LLNode(4);
    // l->next->next->next->next = new LLNode(5);
    // l->next->next->next->next->next = l->next->next;
    // startingLoop(l);

    // ? 0606230838
    // LLNode* l = new LLNode(1);
    // l->next = new LLNode(2);
    // l->next->next = new LLNode(3);
    // l->next->next->next = new LLNode(4);
    // l->next->next->next->next = new LLNode(5);
    // l->next->next->next->next->next = l->next->next;
    // lengthLoop(l);

    // ? 0606230916
    // LLNode* l = buildList({1,2,3,3,2,1});
    // checkPalindromeList(l);

    // ? 0606231002
    // LLNode* l = buildList({1,2,5,3,6,7,8,4});
    // delNodeEndX(l,2);

    // ? 0606231420
    // LLNode* l = buildList({0,1,0,1,0,2,2,1,0});
    // sort012_linkedlist(l);

    // ? 0606231429
    // LLNode* l1 = new LLNode(1);
    // l1->next = new LLNode(2);
    // l1->next->next = new LLNode(3);
    // l1->next->next->next = new LLNode(4);
    // LLNode* l2 = new LLNode(5);
    // l2->next = new LLNode(6);
    // l2->next->next = l1->next;
    // intersectionNodeList(l1,l2);

    // ? 0606231503
    // LLNode* l = buildList({1,2,3,4,5,9});
    // add1ToList(l);

    // ? 0606231804
    // LLNode* l1 = buildList({3,4,5});
    // LLNode* l2 = buildList({1,2,6,7});
    // addNumsList(l1,l2);

    // ? 0606231842
    // LLNode* l = buildList({1,2,3,4,5});
    // rotateListK(l,2);

    // ? 0606232044
    // LLNode* l = buildList({1,2,3,4,5,6,7,8});
    // reverseListGrpK(l,5);

    // ? 0606232151
    // LLNode* l = buildList({1,4,2,3,7,6,9,5});
    // l = sortLinkedList(l);
    // printList(l);

    // ? 0706231112
    // LLNode* l = buildList({1,3,2,5,4,7,6});
    // segregateOddEven(l);

    // ? 0706231309
    // majorityEle3({2,3,3,2,2,3,3,2});

    // ? 0706231341
    // mergeNoSpace({1,3,4,6},{2,5,7});

    // ? 0706231349
    // mergeIntervals({{1,3},{2,4},{6,8},{9,10}});

    // ? 0706231902
    // findMissingRepeat({1,3,3});

    // ? 0706231929
    // subArrayWithXOR_K({4,2,2,6,4},6);

    // ? 0706232001
    // vector<int>vec = {5,3,2,1,4};
    // int ans = 0;
    // countInversions(ans,vec,0,vec.size()-1);
    // cout << "cnt inversions : " << ans << endl;

    // ? 0706232149
    // vector<int>vec = {2,4,3,5,1};
    // int ans = 0;
    // countReversePairs(vec,0,vec.size()-1,ans);
    // cout << "cnt reverse pairs : " << ans << endl;

    // ? 0806230743
    // maxProductSubArray({1,2,-3,0,-4,-5});

    // ? 1006231212
    // searchK({1,2,3,4,5},2);

    // ? 1006231242
    // floorSearchK({1,2,8,10,11,12,19},4);

    // ? 1006231252
    // ceilSearchK({1,2,8,10,11,12,19},5);

    // ? 1006231845
    // firstLastOccurence({ 1, 3, 5, 5, 5, 5, 67, 123, 125 },5);

    // ? 1006231903
    // same as above code instead return ub - lb    

    // ? 1106230810
    // searchRotatedSortedArray1({4,5,1,2,3},4);

    // ? 1106230835
    // same as above

    // ? 1106230941
    // minEleRotatedArray({4,5,1,2,3});

    // ? 1106231006
    // findRotationsCnt({4,5,1,2,3});

    // ? 1106231133
    // searchSortedMatrix({{3,30,38},{44,52,54},{57,60,69}},60);

    // ? 1106231343
    // peakElement2({{10,20,15},{21,30,14},{7,16,32}});

    // ? 1106231759
    // medianGrid({{1, 3, 5},{2, 6, 9}, {3, 6, 9}});

    // ? 1106231858
    // minKokoSpeed({30, 11, 23, 4, 20},5);

    // ? 1106231928
    // capacityShip({9, 8, 10},3);

    // ? 1206230922
    // median2sortedArr({1,3},{2,4});

    // ? 1206231030
    // aggresiveCows({1,2,4,8,9},3);

    // ? 1206231206
    // removeOuterBrackets("(()(()))()");

    // ? 1206231223
    // reverseWords("just.do.coding");

    // ? 1206231227
    // maxOddString("1231231234");

    // ? 1206231729
    // commonPrefixString({"geeks","gee","geesdaf","geesadf"});

    // ? 1206231740
    // checkIsomorphicStrings("aab","xxy");

    // ? 1206231749
    // areStringsRotations("geeks","ksgee");

    // ? 1206231801
    // KthMissingElement({1,3,4,5,7,9},3);

    // ? 1206231801
    // maxDepthBrackets("((((()))(()))(()))");

    // ? 1206231850
    // romanToDecimal("IVDX");

    // ? 1206231856
    // atoiFun("123");

    // ? 1206231939
    // goodnumbers(200,700,4);

    // ? 1206231954
    // subStringsNO1("",4,0,0);
    // cout << endl;

    // ? 1206232002
    // generateBrackets("",3,0,0);
    // cout << endl;

    // ? 1206232009
    // vector<string>ans = {};
    // powerSetStr(ans,3,"abc",0,"");
    // sort(ans.begin(),ans.end());
    // for(auto it : ans) cout << it << " ";
    // cout << endl;

    // ? 1206232030
    // subsetSums({0,2,3,4,5},5);

    // ? 1306230925
    // combinationSum1({2,7,2,6,5},16);

    // ? 1306230946
    // combinationSum2({10,1,2,7,6,1,5},8);

    // ? 1306231034
    // printUniqueSubsets({1,2,2});

    // ? 1306231102
    // combinationSum3(7,3);

    // ? 1306231237
    // phoneWords({2,3});

    // ? 1306231706
    // sortCharFreq("tree");

    // ? 1406230842
    // longestPalindrome("aaabbaa");

    // ? 1406231054
    // substrExactK("aba",2);

    // ? 1406231136
    // sumBeauty("aba");

    // ? 1406231714
    // isWordExist({{'a','g','b','c'},{'q','e','e','l'},{'g','b','k','s'}},"geek");

    // ? 1406231733
    // findPathRat({{1, 0, 0, 0},{1, 1, 0, 1}, {1, 1, 0, 0},{0, 1, 1, 1}},4);

    // ? 1406231744
    // vector<vector<int>>vec = {{3, 0, 6, 5, 0, 8, 4, 0, 0}, {5, 2, 0, 0, 0, 0, 0, 0, 0}, {0, 8, 7, 0, 0, 0, 0, 3, 1}, {0, 0, 3, 0, 1, 0, 0, 8, 0}, {9, 0, 0, 8, 6, 3, 0, 0, 5}, {0, 5, 0, 0, 9, 0, 6, 0, 0}, {1, 3, 0, 0, 0, 0, 2, 5, 0}, {0, 0, 0, 0, 0, 0, 0, 7, 4}, {0, 0, 5, 2, 0, 6, 3, 0, 0}};
    // printGrid(vec);
    // sudokoSolver(vec);
    // printGrid(vec);

    // ? 1406231918
    // nQueen(6);

    // ? 1506231033
    // stack<int>st;
    // st.push(3);
    // st.push(2);
    // st.push(1);
    // printStack(st);
    // insertAtBottom(st,4);
    // printStack(st);

    // ? 1506231042
    // stack<int>st;
    // st.push(4);
    // st.push(3);
    // st.push(2);
    // st.push(1);
    // printStack(st);
    // reverseStack(st);
    // printStack(st);

    // ? 1506231110
    // stack<int>st;
    // st.push(4);
    // st.push(2);
    // st.push(1);
    // st.push(3);
    // printStack(st);
    // sortStack(st);
    // printStack(st);

    // ? 1506231616
    // maxChildrenCookie({3,2,1},{6,4,2});

    // ? 1506231622
    // minCoinsN(67);

    // ? 1506231709
    // lemonadeChange({5,5,5,5,5,10,20,20});

    // ? 1506231716
    // bracketsCheck("[({[()]}{()})[]]");

    // ? 1506231738
    // fractionalKnapsack(50,{{100,20},{120,30},{60,10}});

    // ? 1506231841
    // nMeetings({1,3,0,5,8,5},{2,4,6,7,9,9});

    // ? 1506231934
    // minPlatforms({900, 940, 950, 1100, 1500, 1800},{910, 1200, 1120, 1130, 1900, 2000});

    // ? 1506232023
    // jobSchedule({{1,4,20},{2,1,10},{3,1,40},{4,1,30}});

    // ? 1606231130
    // TNode* t = buildTree();
    // vector<int>ans;
    // preOrderTraversal(ans,t);
    // printVector(ans);

    // ? 1606231142
    // TNode* t = buildTree();
    // vector<int>ans;
    // postOrderTraversal(ans,t);
    // printVector(ans);

    // ? 1606231150
    // TNode* t = buildTree();
    // vector<int>ans;
    // inOrderTraversal(ans,t);
    // printVector(ans);

    // ? 1606231232
    // TNode* t = buildTree();
    // levelOrderTraversal(t);
    // levelOrderTraversal1(t);

    // ? 1606231857
    // TNode* t = buildTree();
    // iterativePreOrderTraversal(t);

    // ? 1606231955
    // TNode* t = buildTree();
    // iterativeInOrderTraversal(t);

    // ? 1706230831
    // TNode* t = buildTree();
    // iterativePostOrderTraversal(t);

    // ? 1706230937
    // TNode* t = buildTree();
    // allTraversals(t);

    // ? 1706231048
    // TNode* t = buildTree();
    // cout << "height of tree : " << heightTree(t) << endl;

    // ? 1706231054
    // TNode* t = buildTree();
    // cout << "tree balanced : " << checkBalanceTree(t) << endl;

    // ? 1706231108
    // TNode* t = buildTree();
    // int ans = 0;
    // diameterTree(t,ans);
    // cout << "diameter of tree : " << ans << endl;

    // ? 1706231150
    // TNode* t = buildTree();
    // int ans = INT_MIN;
    // maxPathSumTree(t,ans);
    // cout << "max Path Sum : " << ans << endl;

    // ? 1706231242
    // TNode* t1 = buildTree();
    // TNode* t2 = buildTree();
    // t2->left->right = NULL;
    // cout << "identical : " << isTreesIdentical(t1,t2) << endl;

    // ? 1706231709
    // TNode* t = buildTree();
    // zigZagTraversal(t);

    // ? 1706231736
    // TNode* t = buildTree();
    // boundaryTraversal(t);

    // ? 1706231736
    // TNode* t = buildTree();
    // verticalOrderTraversal(t);

    // ? 1706231903
    // TNode* t = buildTree();
    // topViewTree(t);

    // ? 1706231910
    // TNode* t = buildTree();
    // bottomViewTree(t);

    // ? 1706231916
    // TNode* t = buildTree();
    // leftViewTree(t);

    // ? 1706231924
    // TNode* t = buildTree();
    // rightViewTree(t);

    // ? 1706231939
    // TNode* t = new TNode(1);
    // t->left = new TNode(2);
    // t->right = new TNode(2);
    // t->left->left = new TNode(3);
    // t->right->right = new TNode(3);
    // cout << "symmentric tree : " << symmentricTree(t->left,t->right) << endl;   

    // ? 1806230804
    // vector<vector<int>>ans;
    // TNode* t = buildTree();
    // rootToLeaf(ans,t,{});
    // for (auto it : ans) printVector(it);

    // ? 1806230817
    // vector<int>ans;
    // TNode* t = buildTree();
    // getRootToNodePath(t,ans,6);
    // printVector(ans);

    // ? 1806230931
    // TNode* t = buildTree();
    // TNode* lca = lcaTree(t,8,5);
    // cout << "lca : " << lca->data << endl; 

    // ? 1806230941
    // TNode* t = buildTree();
    // widthOfBinaryTree(t);

    // ? 1806231045
    // TNode* t = buildTree();
    // childSumTree(t);
    
    // ? 1806231112
    // TNode* t = buildTree();
    // KDistanceNodes(t,6,2);

    // ? 1806231142
    // TNode* t = buildTree();
    // burnTreeTime(t,8);

    // ? 1806231644
    // TNode* t = buildTree();
    // cout << countNodes(t) << endl;

    // ? 1806231905
    // vector<int>preOrder = {3,9,20,15,7};
    // vector<int>inOrder = {9,3,15,20,7};
    // TNode* t = createTree1(preOrder,inOrder);
    // printTree(t);

    // ? 1806232004
    // vector<int>postOrder = {9,15,7,20,3};
    // vector<int>inOrder = {9,3,15,20,7};
    // TNode* t = createTree2(postOrder,inOrder);
    // printTree(t);

    // ? 1906230815
    // TNode* t = buildTree();
    // printTree(t);
    // cout << serialize(t) << endl;
    // TNode* t1 = deserialize("1,3,2,4,#,5,6,#,#,#,#,#,#");
    // printTree(t1);

    // ? 1906230956
    // TNode* t = buildTree();
    // printTree(t);
    // TNode* prev = NULL;
    // flattenTree1(t,prev);
    // printFlattenTree(t);
    // flattenTree2(t);

    // ? 1906231019
    // TNode* bst = deserialize("2,#,81,42,87,#,66,#,90,45,#,#,#,#,#");
    // cout << searchBST(bst,87) << endl;

    // ? 1906231031
    // TNode* bst = deserialize("5,4,6,3,7,1,#,#,#,#,#");
    // minMaxBST(bst);

    // ? 1906231038
    // TNode* bst = deserialize("2,#,81,42,87,#,66,#,90,45,#,#,#,#,#");
    // cout << findCeilBST(bst,43) << endl;

    // ? 1906231048
    // TNode* bst = deserialize("2,#,81,42,87,#,66,#,90,45,#,#,#,#,#");
    // cout << findFloorBST(bst,43) << endl;

    // ? 1906231058
    // TNode* bst = deserialize("2,#,81,42,87,#,66,#,90,45,#,#,#,#,#");
    // printTree(t);
    // TNode* t = insertNodeBST(bst,43);
    // printTree(t);

    // ? 1906231350
    // TNode* bst = deserialize("9,5,12,2,7,10,13,1,3,6,8,#,#,#,#,#,#,#,4,#,#,#,#,#,#");
    // printTree(bst);
    // bst = deleteNodeBST(bst,5);
    // printTree(bst);

    // ? 1906231751
    // TNode* bst = deserialize("9,5,12,2,7,10,13,1,3,6,8,#,#,#,#,#,#,#,4,#,#,#,#,#,#");
    // int k = 3;
    // cout << kthsmallest(bst,k)->data << endl;

    // ? 1906231806
    // TNode* bst = deserialize("9,5,12,2,7,10,13,1,3,6,8,#,#,#,#,#,#,#,4,#,#,#,#,#,#");
    // cout << checkBST(bst,INT_MIN,INT_MAX) << endl;

    // ? 1906231832
    // TNode* bst = deserialize("9,5,12,2,7,10,13,1,3,6,8,#,#,#,#,#,#,#,4,#,#,#,#,#,#");
    // cout << LCA_BST(bst,1,6)->data << endl;

    // ? 1906231907
    // vector<int>pre = {40,30,35,80,100};
    // TNode* t = createBST_preOrder(pre,0,pre.size()-1);
    // printTree(t);

    // ? 2006231147
    // TNode* bst = deserialize("9,5,12,2,7,10,13,1,3,6,8,#,#,#,#,#,#,#,4,#,#,#,#,#,#");
    // findPreSucTree(bst,12);

    // ? 2006231217
    // TNode* bst1 = deserialize("9,5,12,2,7,10,13,1,3,6,8,#,#,#,#,#,#,#,4,#,#,#,#,#,#");
    // TNode* bst2 = deserialize("2,#,81,42,87,#,66,#,90,45,#,#,#,#,#");
    // mergeBSTSort(bst1,bst2);

    // ? 2006231356
    // TNode* bst = deserialize("9,5,12,2,7,10,13,1,3,6,8,#,#,#,#,#,#,#,4,#,#,#,#,#,#");
    // BSTIterator* obj = new BSTIterator(bst);
    // cout << obj->next() << endl;
    // cout << obj->hasNext() << endl;
    // cout << obj->next() << endl;
    // cout << obj->next() << endl;
    // cout << obj->next() << endl;
    // cout << obj->next() << endl;

    // ? 2006231821
    // TNode* bst = deserialize("9,5,12,2,7,10,13,1,3,6,8,#,#,#,#,#,#,#,4,#,#,#,#,#,#");
    // cout << isPairPresentBST(bst,20) << endl;
    // twoSumPairBST(bst,16);

    // ? 2106230815
    // TNode* bst = deserialize("9,5,12,6,7,10,13,1,3,2,8,#,#,#,#,#,#,#,4,#,#,#,#,#,#");
    // correctBST(bst);

    // ? 2106230943
    // TNode* bst = deserialize("10,7,10,#,#,1,11,#,#,#,#");
    // TNode* bst = deserialize("9,5,12,2,7,10,13,1,3,6,8,#,#,#,#,#,#,#,4,#,#,#,#,#,#");
    // largestBst(bst);

    // ? 2106231136
    // TNode* t = deserialize("10,7,10,#,#,1,11,#,#,#,#");
    // printTree(t);
    // t = invertTree(t);
    // cout << endl;
    // printTree(t);

    // ? 2106231146
    // TNode* t = deserialize("9,5,12,2,7,10,13,1,3,6,8,#,#,#,#,#,#,#,4,#,#,#,#,#,#");
    // printTree(t);

    // ? 2106231157
    // CNode* t = new CNode(1);               //  1
    // CNode* t1 = new CNode(2);             // 2 3 4
    // CNode* t2 = new CNode(3);            // 5
    // CNode* t3 = new CNode(4);           // 6
    // CNode* t4 = new CNode(5);
    // CNode* t5 = new CNode(6);
    // t->children = {t1,t2,t3};
    // t1->children = {t4};
    // t4->children = {t5};
    // cout << maxDepthCTree(t) << endl;

    // ? 2106231405
    // TNode* t = deserialize("9,5,12,2,7,10,13,1,3,6,8,#,#,#,#,#,#,#,4,#,#,#,#,#,#");
    // printTree(t);
    // replaceCousinsInTree(t);
    // printTree(t);

    // ? 2106231843
    // TNode* t = deserialize("9,5,12,2,7,10,13,1,3,6,8,#,#,#,#,#,#,#,4,#,#,#,#,#,#");
    // cout << minDepthTree(t) << endl;

    // ? 2106231843
    // TNode* t = deserialize("5,4,8,11,#,13,4,7,2,#,#,#,1,#,#,#,#,#,#");
    // cout << hasPathSumTree(t,22) << endl;

    // ? 2106231927
    // TNode* t = deserialize("5,4,8,11,#,13,4,7,2,#,#,5,1,#,#,#,#,#,#,#,#");
    // vector<int>path;
    // vector<vector<int>>ans;
    // pathSum2Tree(t,22,ans,path);
    // for(auto it : ans){
    //     printVector(it);
    // }

    // ? 2206231039
    // nUniqueBST(3);

    // ? 2206231056
    // TNode* bst = sortedArrayToBST({-10,-3,0,4,5,12});
    // printTree(bst);

    // ? 2206231427
    // vector<TNode*>vecTree = createUniqueBST(1,3);  // all possible BST having 3 nodes
    // for(auto it : vecTree){
    //     printTree(it);
    //     cout << endl;
    // }

    // ? 2206231431
    // TNode* t = deserialize("1,2,3,#,#,#,#");
    // int ans = 0;
    // rootToLeafSum(ans,t,0);
    // printTree(t);
    // cout << ans << endl;

    // ? 2206231454
    // TNode* t = deserialize("3,9,20,#,#,15,7,#,#,#,#");
    // int ans = 0;
    // sumOfLeftLeaves(ans,t,false);
    // printTree(t);
    // cout << ans << endl;

    // ? 2206231504
    // CNode* t = new CNode(1);               //  1
    // CNode* t1 = new CNode(2);             // 2 3 4
    // CNode* t2 = new CNode(3);            // 5
    // CNode* t3 = new CNode(4);           // 6
    // CNode* t4 = new CNode(5);
    // CNode* t5 = new CNode(6);
    // t->children = {t1,t2,t3};
    // t1->children = {t4};
    // t4->children = {t5};
    // levelOrderNTree(t);
    
    // ? 2206231527
    // vector<string>paths;
    // TNode* t = deserialize("9,5,12,2,7,10,13,1,3,6,8,#,#,#,#,#,#,#,4,#,#,#,#,#,#");
    // treePaths(paths,"",t);
    // for(auto it : paths) cout << it << endl;

    // ? 2206231546
    // TNode* t = deserialize("9,5,12,2,7,10,13,1,3,6,8,#,#,#,#,#,#,#,4,#,#,#,#,#,#");
    // printTree(t);
    // cout << findBottomLeftTreeValue(t) << endl;

    // ? 2206231750
    // TNode* t = deserialize("9,5,12,2,7,10,13,1,3,6,8,#,#,#,#,#,#,#,4,#,#,#,#,#,#");
    // printTree(t);
    // largestValuesRowTree(t);

    // ? 2206231858
    // TNode* t = deserialize("3,9,20,#,#,15,7,#,#,#,#");
    // printTree(t);
    // cout << tree2str(t) << endl;

    // ? 2206231919
    // TNode* bst = deserialize("2,#,81,42,87,#,66,#,90,45,#,#,#,#,#");
    // printTree(bst);
    // int prevSum = 0;
    // convertBST_GreaterTree(bst,prevSum);
    // printTree(bst);

    // ? 2306231142
    // TNode* t = deserialize("4,2,9,3,5,#,7,#,#,#,#,#,#");
    // printTree(t);
    // int totalTilt = 0;
    // findTreeTilt(t,totalTilt);
    // printTree(t);
    // cout << "total tilt : " << totalTilt << endl;

    // ? 2306231200
    // TNode* bst = deserialize("1,#,2,2,#,#,#");
    // printTree(bst);
    // findModeBST(bst);

    // ? 2306231215
    // CNode* t = new CNode(1);               //  1
    // CNode* t1 = new CNode(2);             // 2 3 4
    // CNode* t2 = new CNode(3);            // 5
    // CNode* t3 = new CNode(4);           // 6
    // CNode* t4 = new CNode(5);
    // CNode* t5 = new CNode(6);
    // t->children = {t1,t2,t3};
    // t1->children = {t4};
    // t4->children = {t5};
    // vector<int>pre;
    // preOrderNTree(t,pre);
    // printVector(pre);

    // ? 2306231220
    // CNode* t = new CNode(1);               //  1
    // CNode* t1 = new CNode(2);             // 2 3 4
    // CNode* t2 = new CNode(3);            // 5
    // CNode* t3 = new CNode(4);           // 6
    // CNode* t4 = new CNode(5);
    // CNode* t5 = new CNode(6);
    // t->children = {t1,t2,t3};
    // t1->children = {t4};
    // t4->children = {t5};
    // vector<int>post;
    // postOrderNTree(t,post);
    // printVector(post);

    // ? 2306231359
    // TNode* t = deserialize("3,9,20,#,#,15,7,#,#,#,#");
    // printTree(t);
    // averageOfLevels(t);

    // ? 2306231500
    // vector<int>nums = {3,2,1,6,0,5};
    // TNode* t = constructMaxTree(nums,0,nums.size()-1);
    // printTree(t);

    // ? 2306231513
    // TNode* bst = deserialize("4,2,6,1,3,#,#,#,#,#,#");
    // printTree(bst);
    // getMinDiffeTree(bst);

    // ? 2306231703
    // TNode* t = deserialize("2,2,5,#,#,5,7,#,#,#,#");
    // printTree(t);
    // cout << secondMiniTree(t) << endl;

    // ? 2306231746
    // TNode* t = deserialize("1,0,1,0,0,0,1,#,#,#,#,#,#,#,#");
    // printTree(t);
    // t = pruneTree(t);
    // printTree(t);

    // ? 2306231808
    // TNode* t1 = deserialize("3,5,1,6,2,9,8,#,#,7,4,#,#,#,#,#,#,#,#");
    // TNode* t2 = deserialize("3,5,1,6,7,4,2,#,#,#,#,#,#,9,8,#,#,#,#");
    // printTree(t1);
    // printTree(t2);
    // cout << leafSimilar(t1,t2) << endl;

    // ? 2306231944
    // TNode* t1 = deserialize("3,4,5,1,2,#,#,#,#,#,#");
    // TNode* t2 = deserialize("4,1,2,#,#,#,#");
    // printTree(t1);
    // printTree(t2);
    // cout << isSubtree(t1,t2) << endl;

    // ? 2306232157
    // int maxPath = -1; // -1  beacuse The length of the path between two nodes is represented by the number of edges between them. 
    // TNode* t = deserialize("1,4,5,4,4,#,5,#,#,#,#,#,#");
    // printTree(t);
    // longestUnivaluePath(t,maxPath); 
    // cout << maxPath<< endl; 

    // ? 2406230816
    // TNode* bst = deserialize("5,3,6,2,4,#,8,1,#,#,#,7,9,#,#,#,#,#,#");
    // printTree(bst);
    // TNode* bst1 = increasingBST(bst);
    // printTree(bst1);

    // ? 2406230847
    // vector<TNode*> trees = possibleFullTrees(1,7); // containing 5 nodes
    // for(auto t : trees){
    //     printTree(t);
    // }

    // ? 2406231041
    // TNode* t = deserialize("1,1,1,1,1,#,1,#,#,#,#,#,#");
    // printTree(t);
    // cout << isUnivalTree(t) << endl;

    // ? 2406231215
    // TNode* t = deserialize("1,2,3,#,4,#,5,#,#,#,#");
    // printTree(t);
    // cout << isCousins(t,4,5) << endl;

    // ? 2406231215
    // TNode* t = constructFromPrePost({1,2,4,5,3,6,7},{4,5,2,6,7,3,1});
    // printTree(t);

    // ? 2406231526
    // TNode* t = deserialize("3,5,1,6,2,0,8,#,#,7,4,#,#,#,#,#,#,#,#");
    // printTree(t);
    // pair<int,TNode*>deepNodes = subtreeWithAllDeepest(t);
    // printTree(deepNodes.second);

    // ? 2406231552
    // TNode* t = deserialize("0,1,2,3,4,3,4,#,#,#,#,#,#,#,#");
    // printTree(t);
    // cout << smallestStringFromLeaf(t) << endl;

    // ? 2406231913
    // TNode* t = deserialize("5,3,6,2,4,#,8,1,#,#,#,7,9,#,#,#,#,#,#");
    // printTree(t);
    // addOneRowTree(t,10,3);
    // printTree(t);

    // ? 2406232111
    // TNode* t1 = deserialize("1,3,2,5,#,#,#,#,#");
    // TNode* t2 = deserialize("2,1,3,#,4,#,7,#,#,#,#");
    // printTree(t1);
    // printTree(t2);
    // mergeTrees(t1,t2);
    // printTree(t1);

    // ? 2406232141
    // TNode* bst = deserialize("3,0,4,#,2,#,#,1,#,#,#");
    // printTree(bst);
    // trimBST(bst,1,3);
    // printTree(bst);

    // ? 2506230627
    // maxConsectutive1({1,0,0,1,1,0,1},1);

    // ? 2506230632
    // rotateMatrixElement({{ 1, 2, 3 },{ 4, 5, 6 },{ 7, 8, 9 }});

    // ? 2506231217
    // vector<vector<int>>adj = {{1,2,3},{},{4},{},{}};
    // bfsOfGraph(4,adj);

    // ? 2506231234
    // vector<vector<int>>adj = {{1,2,3},{},{4},{},{}};
    // dfsOfGraph(4,adj);

    // ? 2506231237
    // vector<vector<int>>adj = { {1, 0, 1}, {0, 1, 0}, {1, 0, 1}};
    // cout << numProvinces(adj,3) << endl;

    // ? 2506231521
    // numIslands({{0,1,1,1,0,0,0},{0,0,1,1,0,1,0}});

    // ? 2506231534
    // orangesRotting({{0,1,2},{0,1,2},{2,1,1}});

    // ? 2506231552
    // floodFill({{1,1,1},{1,1,0},{1,0,1}},0,0,2);

    // ? 2506231745
    // nearest10({{0,1,1,0},{1,1,0,0},{0,0,1,1}});

    // ? 2606230825
    // replace01({{1, 1, 1, 1},{1, 0, 1, 1},{1, 0, 0, 1},{1, 0, 1, 1},{1, 1, 0, 0}});

    // ? 2606231029
    // cout << numberOfEnclaves({{0, 0, 0, 0},{1, 0, 1, 0},{0, 1, 1, 0},{0, 0, 0, 0}}) << endl;

    // ? 2606231716
    // countDistinctIslands({{1, 1, 0, 0, 0},{1, 1, 0, 0, 0},{0, 0, 0, 1, 1},{0, 0, 0, 1, 1}});

    // ? 2606231753
    // vector<int>adj[5] = {{1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}};
    // isCycleGraphBFS(5,adj);

    // ? 2606231758
    // vector<int>adj[5] = {{1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}};
    // isCycleGraphDFS(5,adj);

    // ? 2606231812
    // vector<int>adj[5] = {{1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}};
    // isGraphBipartiteBFS(5,adj);

    // ? 2606231838
    // vector<int>adj[5] = {{1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}};
    // isGraphBipartiteDFS(5,adj);

    // ? 2606231917
    // vector<int>adj[10] = {{1},{2},{3,6},{4},{5},{},{4},{1,9},{7},{8}};
    // isDirectedGraphCyclicDFS(10,adj);

    // ? 2606232028
    // vector<int>adj[10] = {{1},{2},{3,6},{4},{5},{},{4},{1,9},{7},{8}};
    // eventualSafeNodes(10,adj);

    // ? 2706231113
    // vector<int>adj[6] = {{},{},{3},{1},{0,1},{0,2}};
    // topoSortDFS(6,adj);

    // ? 2706231133
    // vector<int>adj[6] = {{},{},{3},{1},{0,1},{0,2}};
    // topoSortKhans(6,adj);

    // ? 2706231151
    // vector<int>adj[10] = {{1},{2},{3,6},{4},{5},{},{4},{1,9},{7},{8}};
    // isDirectedGraphCyclicKhans(10,adj);

    // ? 2706231356
    // courseSchedule1(4,{{1,0},{2,0},{3,1},{3,2}});

    // ? 2706231411
    // vector<int>adj[10] = {{1},{2},{3,6},{4},{5},{},{4},{1,9},{7},{8}};
    // eventualSafeNodesTopoSort(10,adj);

    // ? 2706231500
    // string dic[5] = {"baa","abcd","abca","cab","cad"}; 
    // alienOrder(dic,5,4);

    // ? 2706231621
    // shortestPathDAG(5,0,{{0,1,2},{2,1,2},{1,3,6},{1,4,8},{2,4,3}});
    // shortestPathDAG(5,1,{{0,1,2},{1,2,2},{1,3,6},{1,4,8},{4,2,3}});
    // shortestPathDAG(5,4,{{0,1,2},{2,1,2},{1,3,6},{4,1,8},{4,2,3}});

    // ? 2706231712
    // shortestPathUnitWeightGraph({{0,1},{0,3},{1,3},{1,2},{2,6},{3,4},{4,5},{5,6},{6,7},{7,8},{6,8}},9,4);

    // ? 2806230812
    // cout << wordLadderLength1("toon","plea",{"poon", "plee", "same", "poie","plea","plie","poin"}) << endl;

    // ? 2806231026
    // wordLadderLength2("bat","coz",{"pat","bat","bot","pot","poz","coz"});

    // ? 2806231115
    // vector<vector<int>>adj[6] = {{{1,4},{2,1}},{{0,4},{2,2}},{{0,1},{1,2},{3,2},{4,1},{5,6}},{{2,3},{5,2}},{{2,1},{5,3}},{{3,2},{2,6},{4,3}}};
    // dijkstra(6,adj,0);

    // ? 2806231428
    // shortestPathDijkstra(1,5,5,{{1,2,2},{2,5,5}, {2,3,4}, {1,4,1},{4,3,3},{3,5,1}});
    // shortestPathDijkstra(3,1,5,{{1,2,2},{2,5,5}, {2,3,4}, {1,4,1},{4,3,3},{3,5,1}});

    // ? 2806231458
    // shortestPathMaze({{1, 1, 1, 1},{1, 1, 0, 1},{1, 1, 1, 1},{1, 1, 0, 0},{1, 0, 0, 1}},{0,1},{2,2});

    // ? 2806231518
    // maxProbabilityGraph(3,{{0,1},{1,2},{0,2}},{0.5,0.5,0.2},0,2);

    // ? 2806231923
    // MinimumEffortGrid({{1,2,1,1,1},{1,2,1,2,1},{1,2,1,2,1},{1,1,1,2,1}});

    // ? 2806232002
    // CheapestFlight(4,{{0,1,100},{1,2,100},{2,1,100},{2,3,200},{1,3,600}},0,3,1);

    // ? 2906230747
    // cout << minimumMultiplications({2,5,7},3,30) << endl;

    // ? 2906231036
    // bellman_ford(6,{{3,2,6},{5,3,1},{0,1,5},{1,5,-3},{1,2,-2},{3,4,-2},{2,4,3}},0);

    // ? 2906231052
    // floydWarshall({{0,1,43},{1,0,6},{-1,-1,0}});

    // ? 2906231141
    // cityWithLessNeighbours(4,{{0,1,3},{1,2,1},{1,3,4},{2,3,1}},4);

    // ? 2906231234
    // minTimeTravel({{0,1,2,4},{12,13,14,9},{15,5,11,10},{3,6,7,8}});

    cout << endl;
    return 0;
}



