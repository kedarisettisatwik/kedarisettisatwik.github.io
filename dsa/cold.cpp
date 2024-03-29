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
    int top = 0;
    int right = c-1;
    int bottom = r-1;
    int left = 0;
    while (top <= bottom && left <= right){
        // move right , along top boundary
        for (int col = left; col <= right; col++){
            spiral.push_back(grid[top][col]);
        }
        top++;
        // move down , along right boundary
        for (int row = top; row <= bottom; row++){
            spiral.push_back(grid[row][right]);
        }
        right--;
        // move left , along bottom boundary
        if (top <= bottom){
            for (int col = right; col >= left; col--){
                spiral.push_back(grid[bottom][col]);
            }
            bottom--;
        }
        // move up , along left boudary
        if (left <= right){
            for(int row = bottom;row >= top;row--){
                spiral.push_back(grid[row][left]);
            }
            left++;
        }
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
Node* mergeLists(Node* t1,Node* t2){
    Node* dummy = new Node(0);
    Node* temp = dummy;
    while (t1 != NULL && t2 != NULL){
        if (t1->data <= t2->data){
            temp->bottom = t1;
            temp = temp->bottom;
            t1 = t1->bottom;
        }else{
            temp->bottom = t2;
            temp = temp->bottom;
            t2 = t2->bottom;
        }
    }
    if (t1 != NULL){
        temp->bottom = t1;
    }
    if (t2 != NULL){
        temp->bottom = t2;
    }
    return dummy->bottom;
}
Node*flattenList(Node *root){
    if (root == NULL) return NULL;
    if (root->next == NULL) return root;
    root->next = flattenList(root->next);
    root = mergeLists(root,root->next);
    return root;
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

// ? 1206231844
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
    sort(items.begin(),items.end(),sortCompare);
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

TNode* delMerge(TNode* root){
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

TNode* del_Node(TNode* root,int x){
    if (root == NULL) return NULL;
    TNode* temp = root;
    while (temp != NULL){
        if (temp-> data == x){
            return temp;
        }
        if (temp->data < x){
            temp = temp->right;
        }else if (temp->data > x){
            temp = temp->left;
        }
    }
    return NULL;
}

TNode* deleteNode(TNode* root, int x) {
    if (root == NULL) return NULL;
    
    TNode* n = del_Node(root,x);
    
    if (n == NULL) return root;
    
    return delMerge(n);
}

// ? 1906231751
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
    int l = (root->left != NULL && root->left->data == root->data) ? longestUnivaluePath(root->left, maxCount) : 0;
    int r = (root->right != NULL && root->right->data == root->data) ? longestUnivaluePath(root->right, maxCount) : 0;
    maxCount = max(maxCount,1 + l + r);
    return 1 + max(l,r);
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
vector<TNode*>possibleFullTrees(int l,int r) {
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
    dict.erase(beginWord);
    
    while (q.empty() == false){
        
        int s = q.size();
        vector<string>wordsUsed;
        
        for (int i = 0; i < s; i++){
            vector<string>path = q.front();
            string word = q.front().back();
            q.pop();
            
            if (word == endWord){
                ans.push_back(path);
                continue;
            }
            for (int i = 0; i < word.size(); i++){
                char original = word[i];
                for (char c = 'a'; c <= 'z'; c++) {
                    word[i] = c;
                    if ( dict.find(word) != dict.end() ) { 
                        path.push_back(word);
                        q.push(path);
                        wordsUsed.push_back(word);
                        path.pop_back();
                    }
                }
                word[i] = original;
            }
        }
        for(auto it : wordsUsed) dict.erase(it);
    
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

// ? 2906230801
int arriveDestination(int n, vector<vector<int>> &roads){
    vector<pair<int, int>> adj[n];
    for (auto it : roads){
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> dist(n, INT_MAX), ways(n, 0);
    dist[0] = 0;
    ways[0] = 1;
    pq.push({0, 0});

    int mod = (int)(1e9 + 7);
    while (!pq.empty()){
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto it : adj[node]){
            int adjNode = it.first;
            int edW = it.second;
            if (dis + edW < dist[adjNode]){
                dist[adjNode] = dis + edW;
                pq.push({dis + edW, adjNode});
                ways[adjNode] = ways[node];
            }
            else if (dis + edW == dist[adjNode]){
                ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
            }
        }
    }
    return ways[n - 1] % mod;
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

// ? 2906231438
void primsAlgoMinSpanTree(int v, vector<vector<int>> adj[]){
    int vis[v] = {0};
    int sum = 0;
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,0}); // wt node
    
    while (pq.empty() == false){
        int wt1 = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        
        if (vis[node] == 1) continue;
        vis[node] = 1;
        sum += wt1;
        
        for (auto it : adj[node]){
            int adjNode = it[0];
            int wt2 = it[1];
            if (vis[adjNode] == 0){
                pq.push({wt2,adjNode});
            }
        }
    }
    cout << "tree weight : " << sum << endl;
}

// ? 2906231514
class DisJointSet{
  vector<int>rank,parent,size;
  public:
    DisJointSet(int n){
        rank.resize(n+1,0);
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i = 0; i <= n;i++){
            parent[i] = i;
        }
    }
    int findSize(int x){
        return size[x];
    }
    int findParent(int x){
        return parent[x];
    }
    int findUltimateParent(int n){
        if (parent[n] == n) return n;
        parent[n] = findUltimateParent(parent[n]);
        return parent[n];
    }
    void unionByrank(int u,int v){
        int ulp_u = findUltimateParent(u);
        int ulp_v = findUltimateParent(v);
        if (ulp_v == ulp_u) return ; // both are already connected
        if (rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }else if (rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    void unionBySize(int u,int v){
        int ulp_u = findUltimateParent(u);
        int ulp_v = findUltimateParent(v);
        if (ulp_v == ulp_u) return ; // both are already connected
        if (size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
    void unionByNum(int u,int v){
        int parent_u = findUltimateParent(u);
        int parent_v = findUltimateParent(v);
        if (parent_u == parent_v) return ;
        if (parent_u <= parent_v){
            parent[parent_v] = parent_u;
        }else{
            parent[parent_u] = parent_v;
        }
    }
};

// ? 2906231529
void krushalMinSpanTree(int v, vector<vector<int>> adj[]){
    vector<pair<int,pair<int,int>>>edges; // wt, node1, node2
    for (int i = 0; i < v; i++) {
        for (auto it : adj[i]) {
            int adjNode = it[0];
            int wt = it[1];
            int node = i;
            edges.push_back({wt, {node, adjNode}});
        }
    }
    sort(edges.begin(),edges.end());
    
    int sum = 0;
    
    DisJointSet tree(v+1);
    for (auto edge : edges){
        int wt = edge.first;
        int n1 = edge.second.first;
        int n2 = edge.second.second;
        if (tree.findUltimateParent(n1) != tree.findUltimateParent(n2)){
            sum += wt;
            tree.unionBySize(n1,n2);
        }
    }
    cout << "tree sum : " << sum << endl;
}

// ? 2906231554
int connectingGraph(int n, vector<vector<int>>edges){
    int cnt_extras = 0;
    DisJointSet tree(n);
    for (auto it : edges){
        int p1 = tree.findUltimateParent(it[0]);
        int p2 = tree.findUltimateParent(it[1]);
        if (p1 == p2){
            cnt_extras++;
        }else{
            tree.unionBySize(it[0],it[1]);
            
        }
    }
    int cnt_components = 0;
    for (int i = 0; i < n;i++){
        if (tree.findParent(i) == i){
            cnt_components++;
        }
    }
    int edgesNeedToConnect = cnt_components-1;
    if (cnt_extras >= edgesNeedToConnect) return edgesNeedToConnect;
    return -1;
}

// ? 2906231929
vector<int> numOfIslands(int n, int m, vector<vector<int>>operators) {
    // [i][j] => (i * c + j)
    DisJointSet ds(n * m);
    int vis[n][m];
    memset(vis, 0, sizeof vis);
    int cnt = 0;
    vector<int> ans;
    for (auto it : operators) {
        int row = it[0];
        int col = it[1];
        if (vis[row][col] == 1) {
            ans.push_back(cnt);
            continue;
        }
        vis[row][col] = 1;
        cnt++;
        int dr[] = { -1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        for (int ind = 0; ind < 4; ind++) {
            int adjr = row + dr[ind];
            int adjc = col + dc[ind];
            if ( adjr >= 0 && adjr < n && adjc >= 0 && adjc < m ) {
                if (vis[adjr][adjc] == 1) {
                    int nodeNo = row * m + col;
                    int adjNodeNo = adjr * m + adjc;
                    if (ds.findUltimateParent(nodeNo) != ds.findUltimateParent(adjNodeNo)) {
                        cnt--;
                        ds.unionBySize(nodeNo, adjNodeNo);
                    }
                }
            }
        }
        ans.push_back(cnt);
    }
    return ans;
}

// ? 2906232011
int maxConnectionLand(vector<vector<int>>grid) {
    int r = grid.size();
    int c = grid[0].size();
    DisJointSet ds(r * c);
    // step - 1
    for (int row = 0; row < r ; row++) {
        for (int col = 0; col < c ; col++) {
            if (grid[row][col] == 0) continue;
            int dr[] = { -1, 0, 1, 0};
            int dc[] = {0, -1, 0, 1};
            for (int ind = 0; ind < 4; ind++) {
                int newr = row + dr[ind];
                int newc = col + dc[ind];
                if (newr >= 0 && newr < r && newc >= 0 && newc < c && grid[newr][newc] == 1) {
                    int nodeNo = row * c + col;
                    int adjNodeNo = newr * c + newc;
                    ds.unionBySize(nodeNo, adjNodeNo);
                }
            }
        }
    }
    // step 2
    int mx = 0;
    for (int row = 0; row < r; row++) {
        for (int col = 0; col < c; col++) {
            if (grid[row][col] == 1) continue;
            int dr[] = { -1, 0, 1, 0};
            int dc[] = {0, -1, 0, 1};
            set<int> components;
            for (int ind = 0; ind < 4; ind++) {
                int newr = row + dr[ind];
                int newc = col + dc[ind];
                if (newr >= 0 && newr < r && newc >= 0 && newc < c) {
                    if (grid[newr][newc] == 1) {
                        components.insert(ds.findUltimateParent(newr * c + newc));
                    }
                }
            }
            int sizeTotal = 0;
            for (auto it : components) {
                sizeTotal += ds.findSize(it);
            }
            mx = max(mx, sizeTotal + 1);
        }
    }
    for (int cellNo = 0; cellNo < r * c; cellNo++) {
        mx = max(mx, ds.findSize(ds.findUltimateParent(cellNo)));
    }
    return mx;
}

// ? 3006232047
int maxStonesRemove(vector<vector<int>>stones) {
    int n = stones.size();
    int maxRow = 0;
    int maxCol = 0;
    for (auto it : stones) {
        maxRow = max(maxRow, it[0]);
        maxCol = max(maxCol, it[1]);
    }
    DisJointSet ds(maxRow + maxCol + 1);
    unordered_map<int, int> stoneNodes;
    for (auto it : stones) {
        int nodeRow = it[0];
        int nodeCol = it[1] + maxRow + 1;
        ds.unionBySize(nodeRow, nodeCol);
        stoneNodes[nodeRow] = 1;
        stoneNodes[nodeCol] = 1;
    }

    int cnt = 0;
    for (auto it : stoneNodes) {
        if (ds.findUltimateParent(it.first) == it.first) {
            cnt++;
        }
    }
    return n - cnt;
}

// ? 3006230954
void dfsBridge(int n,vector<int>adjLs[],int vis[]){
    vis[n] = 1;
    for(auto it : adjLs[n]){
        if (vis[it] == 0){
            dfsBridge(it,adjLs,vis);
        }
    }
}
int numProvincesBridge(vector<int>adjLs[], int v) {
    int vis[v] = {0};
    int cnt = 0;
    for (int i = 0;i < v;i++){
        if (vis[i] == 0){
            cnt++;
            dfsBridge(i,adjLs,vis);        
        }
    }
    return cnt;
}
int isEdgeBridge(int v, vector<int> adj[], int c, int d){
    int cnt1 = numProvincesBridge(adj,v);
    
    vector<int>adj1[v];
    for (int i = 0; i < v;i++){
        for (auto it : adj[i]){
            if ((i == c && it == d ) || (i == d && it == c)){
                continue ;
            }
            adj1[i].push_back(it);
        }
    }
    int cnt2 = numProvincesBridge(adj1,v);
    
    if (cnt2 > cnt1) return 1;
    
    return 0;
}

// ? 3006231001
void dfsBridges(int node, int parent,int& timer,vector<int>&vis,vector<int> adj[], int tin[], int low[], vector<vector<int>>& bridges) {
    vis[node] = 1;
    tin[node] = low[node] = timer;
    timer++;
    for (auto it : adj[node]) {
        if (it == parent) continue;
        if (vis[it] == 0) {
            dfsBridges(it, node,timer,vis, adj, tin, low, bridges);
            low[node] = min(low[it], low[node]);
            // node --- it
            if (low[it] > tin[node]) {
                bridges.push_back({it, node});
            }
        }
        else {
            low[node] = min(low[node], low[it]);
        }
    }
}
void criticalConnections(int v, vector<vector<int>>connections) {
    vector<int>vis(v,0);
    int tin[v];
    int low[v];
    int timer = 0;
    vector<vector<int>>bridges;

    vector<int>adj[v]; 
    for (auto it : connections){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    for (int i = 0; i < v;i++){
        if (vis[i] == 0){
            dfsBridges(i,-1,timer,vis,adj,tin,low,bridges);
        }
    }
    for (int i = 0; i < v; i++){
        cout << low[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < v; i++){
        cout << tin[i] << " ";
    }
    cout << endl;
    printGrid(bridges);
}

// ? 0407231011
int climbStairs1(int n){
    int mod = 1e9 + 7;
    long long prev2 = 1;
    long long prev1 = 1;
    int i = 2;
    while (i <= n){
        long long curr = (prev2 + prev1) % mod;
        prev2 = prev1;
        prev1 = curr;
        i++;
    }
    return (prev1 % mod);
}

// ? 0407231134
int minEnergyFrogJump(vector<int>height){
    int n = height.size();
    int prev2 = INT_MAX;
    int prev1 = 0;
    int i = 1;
    while (i <= n-1){
        int jump1 = prev1 + abs(height[i-1] - height[i]);
        int jump2 = (i > 1) ? (prev2 + abs(height[i-2] - height[i])) : INT_MAX;
        int curr = min(jump1, jump2);
        prev2 = prev1;
        prev1 = curr;
        i++;
    }
    return prev1;
}

// ? 0407231203
int minCostKJumps(vector<int>heights,int k){
    int n = heights.size();
    vector<int>dp(n,1e9);
    dp[0] = 0;
    for (int i = 1; i < n;i++){
        // to reach step i we can k posibilites
        int minCost = 1e9;
        for (int j = 1;j <= k;j++){
            if(i - j >= 0){
                minCost = min(minCost, dp[i-j] + abs(heights[i] - heights[i-j]) );
            }
        }
        dp[i] = minCost;
    }
    return dp[n-1];
}

// ? 0407231238
int houseRobber1(vector<int>arr){
    int n = arr.size();
    int prev2 = 0;
    int prev1 = arr[0];
    for (int i = 1;i < n;i++){
        int take = arr[i];
        if (i - 1 >= 0) take += prev2;
        int notTake = 0 + prev1;
        
        int curr = max(notTake,take);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

// ? 0407231853
int maxPoints(vector<vector<int>>&points,vector<vector<int>>&dp,int n,int row,int col){
    if (row == n) return 0;
    if (dp[row][col] != -1) return dp[row][col];
    int ans = INT_MIN;
    for (int i = 0;i < 3;i++){
        if (i != col) ans = max(ans, points[row][col]  +  maxPoints(points,dp,n,row+1,i) );
    }
    return dp[row][col] = ans;
}
int maxPointsTrain(vector<vector<int>>& points){
    int n = points.size();
    int ans = INT_MIN;
    vector<vector<int>>dp(n,vector<int>(3,-1));
    for (int i = 0; i < 3;i++){
        ans = max(ans,maxPoints(points,dp,n,0,i));
    }
    return ans;
}

// ? 0507231006
int gridPaths1(int n, int m){
    vector<int>prev(m,0);
    for (int i = 0;i < n;i++){
        vector<int>curr(m,0);
        for (int j = 0;j < m;j++){
            if (i == 0 && j == 0) curr[j] = 1;
            else{
                int up = 0;
                int left = 0;
                if (i > 0) up = prev[j];
                if (j > 0) left = curr[j-1];
                curr[j] = up + left;
            }
        }
        prev = curr;
    }
    return prev[m-1];
}

// ? 0507231106
int gridPaths2(int n, int m, vector<vector<int>>grid){
    if (grid[n-1][m-1] == 1 || grid[0][0] == 1) return 0;
    vector<int>prev(m,0);
    int mod = 1e9 + 7;
    for (int i = 0;i < n;i++){
        vector<int>curr(m,0);
        for (int j = 0;j < m;j++){
            if (i == 0 && j == 0) curr[j] = 1;
            else{
                int up = 0;
                int left = 0;
                if (i > 0) {
                    if (grid[i-1][j] == 0) up = prev[j];
                }
                if (j > 0){
                    if (grid[i][j-1] == 0) left = curr[j-1];
                }
                curr[j] = (up + left) % mod;
            }
        }
        prev = curr;
    }
    return prev[m-1];
}

// ? 0507231135
int minSumPathGrid(vector<vector<int>>grid){
    int n = grid.size();
    int m = grid[0].size();
    vector<int>prev(m,0);
    for (int i = 0; i < n;i++){
        vector<int>curr(m,0);
        for (int j = 0; j < m;j++){
            if (i == 0 && j == 0) curr[j] = grid[i][j];
            
            int up = 0;
            if (i > 0) up += prev[j];
            else up += 1e9;

            int left = 0;
            if (j > 0) left += curr[j-1];
            else left += 1e9;

            curr[j] = min(up,left);
        }
        prev = curr;
    }
    return prev[m-1];
}

// ? 0507231145
int minSumTriangle(vector<vector<int>>triangle){
    int n = triangle.size();
    vector<int>bottom(n+1,0);
    for (int i = n-1;i >= 0;i--){
        vector<int>curr(n+1,0);
        for (int j = 0; j <= i;j++){
            if (i == n-1){
                curr[j] = triangle[i][j];
            }else{
                curr[j] = min( triangle[i][j] + bottom[j+1],triangle[i][j] + bottom[j] );
            }
        }
        bottom = curr;
    }
    return bottom[0];
}

// ? 0507231404
int maxSumFallGrid(vector<vector<int>>grid){
    int r = grid.size();
    int c = grid[0].size();
    
    vector<int>prev(c,0), curr(c,0);
    
    for (int j = 0;j < c;j++) prev[j] = grid[0][j];
    
    for (int i = 1;i < r;i++){
        for (int j = 0;j < c;j++){
            
            int u = grid[i][j] + prev[j];
            
            int ld = grid[i][j];
            if (j-1 >= 0) ld += prev[j-1];
            
            int rd = grid[i][j];
            if (j+1 < c) rd += prev[j+1];
            
            curr[j] = max(u, max(ld,rd));
        }
        prev = curr;
    }
    
    int ans = 0;
    for (int j = 0;j < c;j++){
        ans = max(ans, prev[j]);
    }
    return ans;
}

// ? 0607230753
bool subSetTarget(vector<int>arr, int k){
    int n = arr.size();
    vector<vector<bool>> dp(n,vector<bool>(k+1,false));

    for(int i = 0; i < n; i++){
        dp[i][0] = true;
    }
    
    if(arr[0] <= k)
        dp[0][arr[0]] = true;
    
    for(int ind = 1; ind < n; ind++){
        for(int target= 1; target <= k; target++){
            
            bool notTaken = dp[ind-1][target];
    
            bool taken = false;
                if(arr[ind]<=target)
                    taken = dp[ind-1][target-arr[ind]];
        
            dp[ind][target]= notTaken||taken;
        }
    }
    
    return dp[n-1][k];
}

// ? 0607230850
int minDiffSubSetPartition(vector<int>arr){
    int n = arr.size(); 
    int sum = 0;
    for (int i = 0;i < n;i++) sum += arr[i];
    
    vector<vector<bool>>dp(n,vector<bool>(sum+1,false));
    
    for (int i = 0; i < n;i++){
        dp[i][0] = true;
    }
    dp[0][arr[0]] = true;
    
    for (int i = 1;i < n;i++){
        for (int target = 1;target <= sum;target++){
            bool notPick = dp[i-1][target];
            bool pick = false;
            if (arr[i] <= target){
                pick = dp[i-1][target-arr[i]];
            }
            dp[i][target] = notPick || pick;
        }
    }
    
    int minDiff = INT_MAX;
    
    for (int target = 0; target <= sum;target++){
        if (dp[n-1][target]){
            minDiff = min(minDiff, abs(target - (sum - target)) );
        }
    }
    return minDiff;
} 

// ? 0607230858
bool equalPartitionSubSet(vector<int>arr){
    int n = arr.size();
    int sum = 0;
    for (int i = 0;i < n;i++) sum += arr[i];
    
    if (sum % 2 != 0) return false;
    
    int half = sum >> 1;
    vector<vector<bool>>dp(n,vector<bool>(half + 1,false));
    
    for (int i = 0; i < n;i++){
        dp[i][0] = true;
    }
    if (arr[0] <= half) dp[0][arr[0]] = true;
    
    for (int i = 1;i < n;i++){
        for (int target = 1;target <= half;target++){
            bool notPick = dp[i-1][target];
            bool pick = false;
            if (arr[i] <= target){
                pick = dp[i-1][target-arr[i]];
            }
            dp[i][target] = notPick || pick;
        }
    }
    
    return dp[n-1][half];
}

// ? 0607231009
int countSubSetsSumK(vector<int>arr, int k){
    int n = arr.size();
	int mod = 1e9 + 7;
    vector<vector<int>> dp(n, vector<int>(k + 1, 0));
    
    if (arr[0] <= k){
        dp[0][arr[0]] = 1;
    }
    
    dp[0][0] = 1; 
    if (arr[0] == 0) dp[0][0] = 2;
    
    for (int i = 1; i < n; i++){
        for (int target = 0; target <= k; target++){
            int notTake = dp[i-1][target];
            int take = 0;
            if (arr[i] <= target) take = dp[i-1][target-arr[i]];
            dp[i][target] = (take + notTake) % mod;
        }
    }

    return dp[n-1][k];
}

// ? 0607231112
int countSubSetsDiff(int n, int k,vector<int>arr){
    int mod = 1e9 + 7;
    vector<vector<int>> dp(n, vector<int>(k + 1, 0));
    
    if (arr[0] <= k){
        dp[0][arr[0]] = 1;
    }
    
    dp[0][0] = 1; 
    if (arr[0] == 0) dp[0][0] = 2;
    
    for (int i = 1; i < n; i++){
        for (int target = 0; target <= k; target++){
            int notTake = dp[i-1][target];
            int take = 0;
            if (arr[i] <= target) take = dp[i-1][target-arr[i]];
            dp[i][target] = (take + notTake) % mod;
        }
    }

    return dp[n-1][k];
}
int countPartitionsDiff(int d,vector<int>arr){
    int n = arr.size();
    int mod = 1e9 + 7;
    int sum = 0;
    for (int i = 0;i < n;i++) sum += arr[i];
    
    if (d > sum) return 0;
    
    // s1 = t
    // s2 = t - d 
    // sum = 2t - d => t = (sum + d)/2

    if ((sum + d) % 2 != 0) return 0;
    int target = (sum + d) >> 1;
    
    return countSubSetsDiff(n,target,arr);
}

// ? 0607231149
int knapSack10(int w, vector<int>wt, vector<int>val){
    int n = wt.size();
    vector<vector<int>> dp(n,vector<int>(w+1,0));

    for(int i = wt[0]; i <= w; i++){
        dp[0][i] = val[0];
    }
    
    for(int ind =1; ind < n; ind++){
        for(int cap = 0; cap <= w; cap++){
            
            int notTaken = 0 + dp[ind-1][cap];
            
            int taken = INT_MIN;
            if(wt[ind] <= cap)
                taken = val[ind] + dp[ind-1][cap - wt[ind]];
                
            dp[ind][cap] = max(notTaken, taken);
        }
    }
    
    return dp[n-1][w];
}

// ? 0607231522
int minCoinsInfiniteSupply(vector<int>coins, int x){
    int n = coins.size();
    vector<vector<int>>dp(n,vector<int>(x+1,1e9));
    
    // base case if x = 0 , 0 coins required
    for(int i = 0;i < n;i++) dp[i][0] = 0;
    
    for (int v = coins[0];v <= x;v++){
        if (v % coins[0] == 0) dp[0][v] = (v / coins[0]);
    }

    for (int i = 1;i < n;i++){
        for (int v = 1;v <= x;v++){
            int notPick = 0 + dp[i-1][v];
            int pick = 1e9;
            
            if (coins[i] <= v) pick = 1 + dp[i][v - coins[i]]; // dp[i] beacuse we have infinite supply of coins

            dp[i][v] = min(pick,notPick);
        }
    }
    if (dp[n-1][x] == 1e9) return -1;
    return dp[n-1][x];
}

// ? 0607232217
int countWaysInfiniteSupply(vector<int>coins, int x){
    int n = coins.size();
    vector<vector<int>>dp(n,vector<int>(x+1,0));
    
    for (int v = 0;v <= x;v++){
        if (v % coins[0] == 0) dp[0][v] = 1;
    }

    for (int i = 1;i < n;i++){
        for (int v = 0;v <= x;v++){
            int notPick = dp[i-1][v];
            int pick = 0;
            
            if (coins[i] <= v) pick = dp[i][v - coins[i]]; // dp[i] beacuse we have infinite supply of coins

            dp[i][v] = (pick + notPick);
        }
    }
    return dp[n-1][x];
}

// ? 0707230809
int knapSackInfinite(int w, vector<int>val,vector<int>wt){
    int n = wt.size();
    vector<vector<int>>dp(n,vector<int>(w+1,0));
    
    for (int cap = 0;cap <= w;cap++){
        if (wt[0] <= cap){
            dp[0][cap] = int(cap / wt[0]) * val[0];
        }
    }
    for (int i = 1;i < n;i++){
        for (int cap = 1;cap <= w;cap++){
            int notPick = 0 + dp[i-1][cap];
            int pick = 0;
            if (wt[i] <= cap){
                pick = val[i] + dp[i][cap - wt[i]];
            }
            dp[i][cap] = max(notPick,pick);
        }
    }
    return dp[n-1][w];
}

// ? 0707230827
int rodCutting(vector<int>val){
    int n = val.size();
    vector<vector<int>>dp(n+1,vector<int>(n+1,0)); // 1 based index
    
    for (int l = 1;l <= n;l++){
        dp[1][l] = val[0]*(l);
    }
    
    for (int i = 2;i <= n;i++){
        for (int l = 1;l <= n;l++){
            int notCut = dp[i-1][l];
            int cut = 0;
            if (i <= l){
                cut = val[i-1] + dp[i][l - i]; 
            }
            dp[i][l] = max(notCut,cut);
        }
    }
    return dp[n][n];
}

// ? 0707230846
int longCommonSubSeqString(string s1, string s2){
    int n=s1.size();
    int m=s2.size();

    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    
    for(int ind1 = 1;ind1 <= n;ind1++){
        for(int ind2 = 1;ind2 <= m;ind2++){
            if(s1[ind1-1] == s2[ind2-1])
                dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
            else
                dp[ind1][ind2] = 0 + max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
        }
    }
    
    return dp[n][m];
}

// ? 0707231053
void all_longest_common_subsequences(string s1, string s2){
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    
    for (int i = 1;i <= n;i++){
        for (int j = 1;j <= m;j++){
            if (s1[i-1] == s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    } // longest subSeq = dp[n][m] 
    
    // now backTrack
    int i = n;
    int j = m;
    unordered_set<string>st;
    queue<pair<pair<int,int>,string>>q; // coords, string
    q.push({{n,m},""});
    
    while (q.empty() == false){
        int r = q.front().first.first;
        int c = q.front().first.second;
        string str = q.front().second;
        q.pop();
        
        if (r == 0 || c == 0){
            st.insert(str);
            continue;
        }
        
        if (s1[r-1] == s2[c-1]){
            str = s1[r-1] + str;
            if (r-1 >= 0 && c-1 >= 0) q.push({{r-1,c-1},str});
        }else{
            // two ways {r-1,c} or {r,c-1} which is max
            int way1 = dp[r-1][c];
            int way2 = dp[r][c-1];
            
            if (way1 > way2){
                q.push({{r-1,c},str});
            }else if (way2 > way1){
                q.push({{r,c-1},str});
            }else{
                q.push({{r-1,c},str});
                q.push({{r,c-1},str});
            }
        }
    }
    for (auto& it : st){
        cout << it << " ";
    }
    cout << endl;
}

// ? 0707231144
int longestCommonSubstr(string s1, string s2){
    int n = s1.length();
    int m = s2.length();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    int ans = 0;
    for (int i = 1;i <= n;i++){
        for (int j = 1;j <= m;j++){
            if (s1[i-1] == s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
                ans = max(ans,dp[i][j]);
            }else{
                dp[i][j] = 0;
            }
        }
    }
    return ans;
}

// ? 0707231324
int longestPalinSubseq(string s) {
    int n = s.size();
    string s1 = s;
    string s2 = "";
    for (auto it : s) s2 = it + s2;
    // longestPalindrom subSeq in s == longest common subSequence in (S,reverse of S)
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    for (int i = 1;i <= n;i++){
        for (int j = 1;j <= n;j++){
            if (s1[i-1] == s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][n];
}

// ? 0707231417
int maxConsecutiveTF(string str, int k) {
    int n = str.length();
    int ans = 0;
    
    // finding max consecutive T's
    int l = 0;
    int chances = 0;
    for (int r = 0;r < n;r++){
        if (str[r] == 'F'){
            chances++;
        }
        while (chances > k){
            if (str[l] == 'F') chances--;
            l++;
        }
        ans = max(ans,(r - l+1));
    }

    // finding max consecutive F's
    l = 0;
    chances = 0;
    for (int r = 0;r < n;r++){
        if (str[r] == 'T'){
            chances++;
        }
        while (chances > k){
            if (str[l] == 'T') chances--;
            l++;
        }
        ans = max(ans,(r - l+1));
    }

    return ans;
}

// ? 0707231451
int minInsertionsToMakePalindrome(string s) {
    int n = s.size();
    string s1 = s;
    string s2 = "";
    for (auto it : s) s2 = it + s2;
    // longestPalindrom subSeq in s == longest common subSequence in (S,reverse of S)
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    for (int i = 1;i <= n;i++){
        for (int j = 1;j <= n;j++){
            if (s1[i-1] == s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return n - dp[n][n];
}

// ? 0707231510
int convertStringMinInsDel(string s1, string s2){
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    
    for(int ind1 = 1;ind1 <= n;ind1++){
        for(int ind2 = 1;ind2 <= m;ind2++){
            if(s1[ind1-1] == s2[ind2-1])
                dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
            else
                dp[ind1][ind2] = 0 + max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
        }
    }
    int lcs = dp[n][m];
    int del = n - lcs;
    int ins = m - lcs;
    return del + ins;
}

// ? 0707231518
int shortestCommonSuperSeq(string s1, string s2){
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    
    for(int ind1 = 1;ind1 <= n;ind1++){
        for(int ind2 = 1;ind2 <= m;ind2++){
            if(s1[ind1-1] == s2[ind2-1])
                dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
            else
                dp[ind1][ind2] = 0 + max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
        }
    }
    int lcs = dp[n][m];
    return (n + m - lcs);
}

// ? 0707231916
int find_s2_in_s1(string s1, string s2,int i,int j,vector<vector<int>>&dp){
    int mod = 1e9 + 7;
    if (j < 0) return 1; // found all char's of s2 in s1
    if (i < 0) return 0; // crossed s1 still some s2 char's not found
    if (dp[i][j] != -1) return dp[i][j];
    int ans = 0;
    if (s1[i] == s2[j]){
        ans += find_s2_in_s1(s1,s2,i-1,j-1,dp); // we can keep s1[i] as a matching char
        ans += find_s2_in_s1(s1,s2,i-1,j,dp); // or we can look for another duplicate char
    }else{
        ans = find_s2_in_s1(s1,s2,i-1,j,dp); 
    }
    dp[i][j] = ans % mod;
    return dp[i][j];
}
int subsequenceMatchCount(string t, string s){
    int lt = t.size();
    int ls = s.size();
    vector<vector<int>>dp(lt,vector<int>(ls,-1));
    find_s2_in_s1(t,s,lt-1,ls-1,dp);
    return dp[lt-1][ls-1];
} 

// ? 0707232043
int delReplaceInsert(string s1,string s2,int i,int j,vector<vector<int>>&dp){
    if (i < 0){
        return j + 1; // convert "" into s2[0..j] -> j + 1 insert operations  
    }
    if (j < 0){
        return i + 1; // convert s1[0..i] to "" -> i+1 delete operations
    }
    if (dp[i][j] != -1) return dp[i][j];
    
    if (s1[i] == s2[j]){
        dp[i][j] = delReplaceInsert(s1,s2,i-1,j-1,dp);
        return dp[i][j];
    }
    int ans = INT_MAX;
    ans = min(ans, 1 + delReplaceInsert(s1,s2,i-1,j,dp)); // del char in s1
    ans = min(ans, 1 + delReplaceInsert(s1,s2,i,j-1,dp)); // insert char after index i s1
    ans = min(ans, 1 + delReplaceInsert(s1,s2,i-1,j-1,dp)); // replace char in s1
    
    return dp[i][j] = ans;
}
int delReplaceInsertString(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>>dp(n,vector<int>(m,-1));
    delReplaceInsert(s1,s2,n-1,m-1,dp);
    return dp[n-1][m-1];
}

// ? 0807230739
int minScoreGraphCities(int n, vector<vector<int>>roads){
    // 1 based index
    vector<vector<pair<int,int>>>adjLs(n+1);
    for (auto r : roads){
        adjLs[r[0]].push_back({r[1],r[2]});
        adjLs[r[1]].push_back({r[0],r[2]});
    }
    vector<int>dis(n+1,1e9);
    queue<pair<int,int>>q;
    q.push({1e9,1}); // dis 0 node 1
    while (q.empty() == false){
        int node = q.front().second;
        int d = q.front().first;
        q.pop();
        for (auto it : adjLs[node]){
            int adjNode = it.first;
            int d1 = it.second;
            if (min(d,d1) < dis[adjNode]){
                dis[adjNode] = min(d,d1);
                q.push({dis[adjNode],adjNode});
            } 
        }
    }
    return dis[n];
}

// ? 0807230747
long long dividePlayers(vector<int>skill) {
    sort(skill.begin(),skill.end());
    int n = skill.size();
    int s = skill[0] + skill[n-1];
    long long chemistry = 0;
    int l = 0;
    int r = n-1;
    while (l < r){
        int temp = skill[l] + skill[r];
        if (temp != s) return -1;
        chemistry += (skill[l] * skill[r]);
        l++;
        r--;
    }
    return chemistry;
}

// ? 0807230756
int wildCardMatchStrings(string S1,string S2){
    // S1 = pattern
    // S2 = text
    int n = S1.size();
    int m = S2.size();

    vector <vector<bool>>dp(n + 1, vector <bool>(m, false));

    dp[0][0] = true;

    for (int j = 1; j <= m; j++) dp[0][j] = false; // empty pattern != non empty str
    for (int i = 1; i <= n; i++){
        // star * pattern == empty str 
        if (S1[i-1] == '*') dp[i][0] = dp[i-1][0];
        else dp[i][0] = false;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {

            if (S1[i - 1] == S2[j - 1] || S1[i - 1] == '?') dp[i][j] = dp[i - 1][j - 1];
            else {
                if (S1[i - 1] == '*')
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];

                else dp[i][j] = false;
            }
        }
    }

    return dp[n][m];
}

// ? 0807231041
int maxProfitStock1(vector<int>prices){
    int n = prices.size();
    int mini = prices[0];
    int maxProfit = 0;
    
    for(int i = 0;i < n;i++){
        int cost = prices[i] - mini;
        maxProfit = max(maxProfit,cost);
        mini = min(mini,prices[i]);
    }
    
    return maxProfit;
}

// ? 0807231055
void stockBuySellSegments(vector<int>prices){
    int n = prices.size();
    vector<vector<int>> segments;

    int start = -1; // Start of the segment
    int end = -1;   // End of the segment
    
    for (int i = 1; i < n; i++){
        if (prices[i] > prices[i-1]){
            // Potential selling day
            if (start == -1) {
                // If there was no previous segment, mark this as the start of a new segment
                start = i - 1;
            }
        }else if (prices[i] < prices[i-1]){
            // Potential buying day
            if (start != -1) {
                // If a start has been marked, mark this as the end of the segment and add it to the results
                end = i - 1;
                segments.push_back({start, end});
                start = -1; // Reset start for the next segment
            }
        }
    }
    
    // Check if there is an open segment at the end of the array
    // like if prices increased continously till last
    if (start != -1) {
        end = n - 1;
        segments.push_back({start, end});
    }

    printGrid(segments);
}

// ? 0807231134
long long maxProfitMultipleStocks(vector<long long>prices){
    int n = prices.size();
    long long profit = 0;
    int buy = -1;
    int sell = -1;
    for (int i = 1;i < n;i++){
        if (prices[i] > prices[i-1]){
            // price is increasing, good to buy at i - 1 if not yet bought
            if (buy == -1){
                buy = i-1;
            }
        }else if (prices[i] < prices[i-1]){
            // price is decreasing, if you already bought good to sell at i-1
            if (buy != -1){
                sell = i-1;
                profit += (prices[sell] - prices[buy]);
                buy = -1; // new stock
            }
        }
    }
    if (buy != -1){
        profit += (prices[n-1] - prices[buy]);
    }
    return profit;
}

// ? 0807231244
int maxBombs(vector<vector<int>>bombs) {
    int n = bombs.size();
    vector<int>adjLs[n];
    for (int i = 0;i < n;i++){
        for (int j = 0;j < n;j++){
            if (i != j){
                int x1 = bombs[i][0], y1 = bombs[i][1], r1 = bombs[i][2];
                int x2 = bombs[j][0], y2 = bombs[j][1], r2 = bombs[j][2];
                long long dis = (long long)(x1 - x2)*(x1 - x2) + (long long)(y1 - y2)*(y1-y2);
                if (dis <= (long long)r1*r1){
                    adjLs[i].push_back(j);
                } 
            }
        }
    }
    int maxCnt = 0;
    for(int i = 0;i < n;i++){
        // bfs
        int cnt = 0;
        vector<bool>vis(n,false);
        queue<int>q;
        vis[i] = true;
        q.push(i);
        cnt++;
        while (q.empty() == false){
            int f = q.front();
            q.pop();
            for(auto adjNode : adjLs[f]){
                if (vis[adjNode] == false){
                    vis[adjNode] = true;
                    cnt++;
                    q.push(adjNode);
                }
            }
        }
        maxCnt = max(maxCnt,cnt);
    }
    return maxCnt;
}

// ? 0807231344
 int buyStocks(int ind,int canBuy,int c,vector<int>&prices,int n,vector<vector<vector<int>>>&dp){
    if (c == 0) return 0;
    if (ind == n) return 0;
    if (dp[ind][canBuy][c] != -1) return dp[ind][canBuy][c];
    if (canBuy){
        int buy = -prices[ind] + buyStocks(ind+1,0,c,prices,n,dp);
        int notBuy = 0 + buyStocks(ind+1,1,c,prices,n,dp);
        return dp[ind][canBuy][c] = max(buy,notBuy);
    }else{
        int sell = prices[ind] + buyStocks(ind+1,1,c-1,prices,n,dp); // sell means a transcation completed, next we can Buy
        int notSell = 0 + buyStocks(ind+1,0,c,prices,n,dp);
        return dp[ind][canBuy][c] = max(sell,notSell);
    }
}
int stock_n_transactions(vector<int>&prices,int cap){
    int n = prices.size();
    vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(cap + 1,-1))); // n , 1 = buy 0 = notBuy, cap
    return buyStocks(0,1,cap,prices,n,dp);
}

// ? 0807231847
int longestSquareStreak(vector<int>nums){
    int n = nums.size();
    int maxLen = 0;
    unordered_set<int>st(nums.begin(),nums.end());
    for(int i = 0;i < n;i++){
        long long  x = nums[i];
        bool x_square = false;
        
        double sqrt_x1 = (sqrt(nums[i]));
        double r = sqrt_x1 - (int)sqrt_x1;
        if (r == 0.0){
            x_square = true;
        }

        long long sqrt_x = (long long)(sqrt(nums[i]));
        if (st.find(sqrt_x) == st.end() || x_square == false){
            // if x is not prefect square seq may start from
            // else if x is prefect square and if we have sqrt(x) in arr then longest seq won't start from x
            // if sqrt(x) not present then longest seq may start from x
            int len = 0;
            while (st.find(x) != st.end() && x <= 1e5){ // nums[i] max is 1e5
                x = x * x;
                len++;
            }
            maxLen = max(maxLen,len);
        }
    
    }
    if (maxLen < 2) return -1;
    return maxLen;
}

// ? 0807231936
int captureForts(vector<int>forts) {
    // ans = max zeros in btw -1 , 1
    int maxLen = 0;
    int n = forts.size();
    int startFort = 0;
    int l = 0;
    int r = 0;
    for (int i = 0;i < n;i++){
        if (startFort == 0 && forts[i] != 0){
            startFort = forts[i];
            l = i;
        }else{
            if (startFort == forts[i]){
                l = i;
            }else if (startFort == forts[i] * -1){
                r = i;
                maxLen = max(maxLen,r-l-1);
                startFort = forts[i];
                l = i;
            }
        }
    }
    return maxLen;
}

// ? 0907230758
int collectApples(int node,vector<int>&vis,vector<vector<int>>&adjLs,vector<int>hasApple){
    vis[node] = 1;
    int time = 0;
    for (auto child : adjLs[node]){
        if (vis[child] == 0) time += collectApples(child,vis,adjLs,hasApple);
    }
    if (node == 0){
        return time;
    }
    if (time == 0){
        // if child have no apples
        if (hasApple[node]){
            // if node itself have apples, 
            time = 2;
        }
        return 0;
    }
    return time + 2; // child have apples, so we should come and go back from this node
}
int collectAppleGraph(int n, vector<vector<int>>edges, vector<int>hasApple) {
    vector<int>vis(n,0);
    vector<vector<int>>adjLs(n);
    for (auto it : edges){
        adjLs[it[1]].push_back(it[0]);
        adjLs[it[0]].push_back(it[1]);
    }
    return collectApples(0,vis,adjLs,hasApple);
}

// ? 0907230942
int stockProfitCoolDown(bool canBuy,vector<int>&prices,int ind,int n,vector<vector<int>>&dp){
    if (ind >= n) return 0;
    if (dp[canBuy][ind] != -1) return dp[canBuy][ind];
    if (canBuy){
        int buy = -prices[ind] + stockProfitCoolDown(0,prices,ind+1,n,dp);
        int notBuy = 0 + stockProfitCoolDown(1,prices,ind+1,n,dp); 
        dp[canBuy][ind] = max(buy,notBuy);
    }else{
        int sell = prices[ind] + stockProfitCoolDown(1,prices,ind+2,n,dp);
        int notSell = 0 + stockProfitCoolDown(0,prices,ind+1,n,dp);
        dp[canBuy][ind] = max(sell,notSell);
    }
    return dp[canBuy][ind];
}
int sellBuyStockCoolDown(vector<int> &prices){
    int n = prices.size();
    vector<vector<int>>dp(2,vector<int>(n,-1));
    return stockProfitCoolDown(1,prices,0,n,dp);
}

// ? 0907230957
int stockProfitFee(int ind,int canBuy,vector<int>&prices,int fee,int n,vector<vector<int>>&dp){
    if (ind >= n) return 0;
    if (dp[canBuy][ind] != -1) return dp[canBuy][ind];
    if (canBuy){
        int buy = -prices[ind] + stockProfitFee(ind+1,0,prices,fee,n,dp);
        int notBuy = 0 + stockProfitFee(ind+1,1,prices,fee,n,dp);
        dp[canBuy][ind] =  max(buy,notBuy);
    }else{
        int sell = prices[ind] - fee + stockProfitFee(ind+1,1,prices,fee,n,dp);
        int notSell = 0 + stockProfitFee(ind+1,0,prices,fee,n,dp);
        dp[canBuy][ind] = max(sell,notSell);
    }
    return dp[canBuy][ind];
}
int sellBuyStockFee(int fee, vector<int> &prices){
    int n = prices.size();
    vector<vector<int>>dp(2,vector<int>(n,-1));
    return stockProfitFee(0,1,prices,fee,n,dp);
}

// ? 0907231136
void printLongestIncreasingSubSeq(vector<int> arr) {
    int n = arr.size();
	vector<int>dp(n,1),hash(n,0);
	int maxi = 1;
	int lastIndex = 0;
	for(int i = 0;i < n;i++){
		hash[i] = i;
		for(int prev = 0;prev < i;prev++){
			if (arr[prev] < arr[i] && dp[i] < (1 + dp[prev])){
				dp[i] = 1 + dp[prev];
				hash[i] = prev;
			}
		}
		if (dp[i] > maxi){
			maxi = dp[i];
			lastIndex = i;
		}
	}
	vector<int>ans;
	ans.push_back(arr[lastIndex]);
	while (lastIndex != hash[lastIndex]){
		lastIndex = hash[lastIndex];
		ans.push_back(arr[lastIndex]);
	}
	reverse(ans.begin(),ans.end());
    printVector(ans);
}

// ? 0907231233
void divisibleSet(vector<int>arr){
    sort(arr.begin(),arr.end());
    int n = arr.size();
    vector<int>dp(n,1),hash(n,0);
    int maxi = 1;
    int lastIndex = 0;
    for (int i = 0;i < n;i++){
        hash[i] = i;
        for(int prev = 0;prev < i;prev++){
            if ((arr[i] != 0 && arr[prev] % arr[i] == 0) || (arr[prev] != 0 && arr[i] % arr[prev] == 0)){
                if (dp[i] < 1 + dp[prev]){
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
            }
        }
        if (dp[i] > maxi){
            maxi = dp[i];
            lastIndex = i;
        }
    }
    vector<int>ans;
    ans.push_back(arr[lastIndex]);
    while (hash[lastIndex] != lastIndex){
        lastIndex = hash[lastIndex];
        ans.push_back(arr[lastIndex]);
    }
    printVector(ans);
}

// ? 0907231407
bool compareStrings(string str1,string str2){
    // str2 + char = str1
    int n = str1.size();
    int m = str2.size();
    if (n - m != 1) return false;
    
    int p1 = 0;
    int p2 = 0;
    while (p1 < n){
        if (p2 < m && str1[p1] == str2[p2]){
            p1++;
            p2++;
        }else{
            p1++;
        }
    }
    if (p1 == n && p2 == m) return true;
    return false;
}
bool comp(string s1, string s2){
    return s1.size() < s2.size();
}
void longestStrChain(vector<string>arr){
    sort(arr.begin(),arr.end(),comp);
    int n = arr.size();
    vector<int>dp(n,1);
    vector<int>hash(n,0);
    int maxi = 1;
    int lastIndex = 0;
    for(int i = 0;i < n;i++){
        hash[i] = i;
        for(int prev = 0;prev < i;prev++){
            if (compareStrings(arr[i],arr[prev])){
                if (dp[i] < 1 + dp[prev]){
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
            }
        }
        if (dp[i] > maxi){
            maxi = dp[i];
            lastIndex = i;
        }
    }
    vector<string>ans;
    ans.push_back(arr[lastIndex]);
    while (hash[lastIndex] != lastIndex){
        lastIndex = hash[lastIndex];
        ans.push_back(arr[lastIndex]);
    }
    for(auto it : ans) cout << it << " - ";
    cout << endl;
}

// ? 0907231537
int findNumberOfLIS(vector<int>arr){
    int n = arr.size();
    int maxi = 1;
    vector<int>cnt(n,0),dp(n,0);
    for(int i = 0;i < n;i++){
        dp[i] = 1;
        cnt[i] = 1;
        for (int prev = 0;prev < i;prev++){
            if (arr[prev] < arr[i]){
                if (dp[i] < 1 + dp[prev]){
                    dp[i] = 1 + dp[prev];
                    cnt[i] = cnt[prev];
                }else if (dp[i] == 1 + dp[prev]){
                    cnt[i] += cnt[prev];
                }
            }
        }
        if (dp[i] > maxi){
            maxi = dp[i];
        }
    }
    int ans = 0;
    for (int i = 0;i < n;i++){
        if (dp[i] == maxi) ans += cnt[i];
    }
    return ans;
}

// ? 0907231751
int longestBitonicSequence(vector<int>arr){
    int n = arr.size();
	vector<int>dp1(n,1);
	vector<int>dp2(n,1);
	vector<int>bitonic(n,1);
	
	for(int i = 0;i < n;i++){
		for(int prev = 0;prev < i;prev++){
			if (arr[prev] < arr[i]){
				dp1[i] = max(dp1[i],1 + dp1[prev]);
			}
		}
	} 
	for(int i = n-1;i >= 0;i--){
		for(int prev = n-1;prev > i;prev--){
			if(arr[prev] < arr[i]){
				dp2[i] = max(dp2[i],1 + dp2[prev]);
			}
		}
	}
	int maxi = 0;
	for(int i = 0;i < n;i++){
		bitonic[i] = (dp1[i] + dp2[i] - 1);
		maxi = max(maxi,bitonic[i]);
	}
	return maxi;
} 

// ? 0907231835
int matrixPartition(int i,int j,vector<int>arr,vector<vector<int>>&dp){
    if (i == j) return 0; // no more multiplications needed
    if (dp[i][j] != -1) return dp[i][j];
    int mini = 1e9;
    // we want to divide at index k
    // i to k, k+1 to j
    for(int k = i;k < j;k++){
        // multiplication of A[i] ... A[k] will give matrix[ A[i-1] * A[k] ]
        // multiplication of A[k+1] .... A[j] will give matrix[ A[k+1-1] * A[j] ] 
        int x = arr[i - 1] * arr[k] * arr[j] + matrixPartition(i,k,arr,dp) + matrixPartition(k+1,j,arr,dp);
        mini = min(mini,x); 
    }
    dp[i][j] = mini;
    return mini;
}
int matrixChainMultiplication(vector<int>arr){
    int n = arr.size()-1;
    // n = 2, two matrixs, arr = [10,20,30]
    // -> M1 = [10 x 20] , M2 = [20 x 30]
    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    return matrixPartition(1,n,arr,dp); // multiply 1 to n matrixs
}

// ? 1007231025
string smallestEquivalentString(string s1, string s2, string baseStr){
    DisJointSet ds(26);
    int n = s1.length();
    for(int i = 0;i < n;i++){
        if (s1[i] < s2[i]){
            ds.unionByNum(int(s1[i]-'a'),int(s2[i]-'a'));
        }else if (s1[i] > s2[i]){
            ds.unionByNum(int(s2[i]-'a'),int(s1[i]-'a'));
        }
    }
    string ans = baseStr;
    n = baseStr.length();
    for(int i = 0;i < n;i++){
        ans[i] = char(ds.findUltimateParent(int(baseStr[i] - 'a')) + 'a');
    }
    return ans;
}

// ? 1007231123
int cutProfit(int i,int j,vector<int>&cuts,int rodStart,int rodEnd,vector<vector<vector<int>>>&dp){
	if (i > j) return 0;
    int length = rodEnd - rodStart+1;
    if (dp[i][j][length] != -1) return dp[i][j][length];
	int ans = 1e9;
	for(int k = i;k <= j;k++){
        int c = cuts[k];
		int cost = length + cutProfit(i,k-1,cuts,rodStart,c,dp) + cutProfit(k+1,j,cuts,c+1,rodEnd,dp);
		ans = min(ans, cost);
	}
	return dp[i][j][length] = ans;
}
int minCostCutting(int length,vector<int>cuts){
	int c = cuts.size();
    sort(cuts.begin(),cuts.end());
    vector<vector<vector<int>>>dp(c,vector<vector<int>>(c,vector<int>(length+1,-1)));
	return cutProfit(0,c-1,cuts,1,length,dp);
}

// ? 1007231136
int cutRod(int length,vector<int>price,vector<int>&dp){
	if (length <= 0) return 0;
	if(dp[length] != -1) return dp[length];
	int ans = 0;
	for(int i = 1;i <= length;i++){
		int c = price[i-1] + cutRod(length-i,price,dp);
		ans = max(ans,c);
	}
	return dp[length] = ans;
}
int maxCutRod(vector<int>price, int n){
	vector<int>dp(n+1,-1);
	return cutRod(n,price,dp);
}

// ? 1007231420
int maxBallonCoins(int i,int j,vector<int>a,vector<vector<int>>&dp){
    if (i > j) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    int ans = 0;
    for(int k = i;k <= j;k++){
        int x = a[i-1] * a[k] * a[j+1] + maxBallonCoins(i,k-1,a,dp) + maxBallonCoins(k+1,j,a,dp);  
        ans = max(ans, x);
    }
    return dp[i][j] = ans;
}
int ballonCoins(vector<int>a) {
    int n = a.size();
    a.push_back(1);
    a.insert(a.begin(),1);
    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    return maxBallonCoins(1,n,a,dp);
}

// ? 1007231437
int evaluateExpTF(int i,int j,bool isTrue,string exp,vector<vector<vector<long long>>>&dp){
    int mod = 1e9 + 7;
    if(i > j) return 0;
    if (dp[i][j][isTrue] != -1) return dp[i][j][isTrue];
    if (i == j){
        if (isTrue) dp[i][j][isTrue] = ( exp[i] == 'T');
        else dp[i][j][isTrue] = ( exp[i] == 'F');
        return dp[i][j][isTrue]; 
    }
    int ans = 0;
    for(int k = i+1;k <= j-1;k+=2){
        long long lt = evaluateExpTF(i,k-1,true,exp,dp); // how many ways to make left exp true;
        long long lf = evaluateExpTF(i,k-1,false,exp,dp); // how many ways to make left exp false;
        long long rt = evaluateExpTF(k+1,j,true,exp,dp); // how many ways to make right exp true;
        long long rf = evaluateExpTF(k+1,j,false,exp,dp); // how many ways to make right exp false;
        if (exp[k] == '|'){
            if (isTrue) ans += (lt * rt)%mod + (lf * rt)%mod + (lt * rf)%mod;
            else ans += (lf * rf)%mod;
        }else if (exp[k] == '&'){
            if (isTrue) ans += (lt * rt)%mod;
            else ans += (lf * rf)%mod + (lt * rf)%mod + (lf * rt)%mod;
        }else if (exp[k] == '^'){
            if (isTrue) ans += (lt * rf)%mod + (lf * rt)%mod;
            else ans += (lf * rf)%mod + (lt * rt)%mod;
        }
    }
    return dp[i][j][isTrue] = ans % mod;
}
int noWaysToMakeExpTrue(string exp){
    int n = exp.size();
    vector<vector<vector<long long>>>dp(n,vector<vector<long long>>(n,vector<long long>(2,-1)));
    return evaluateExpTF(0,n-1,true,exp,dp);
}

// ? 1007231523
bool isPalindrome(string str, int l, int r) {
    while (l < r) {
        if (str[l] != str[r]) return false;
        l++;
        r--;
    }
    return true;
}
void partitionStr(string str, int index, vector<string>& path, vector<vector<string>>& res) {
    if (index == str.size()) {
        res.push_back(path);
        return;
    }
    for (int i = index; i < str.size(); i++) {
        if (isPalindrome(str, index, i)) {
            path.push_back(str.substr(index, i - index + 1));
            partitionStr(str, i + 1, path, res);  // Fixed the recursive call here
            path.pop_back();
        }
    }
}
void palindromePartitioning1(string s) {
    vector<vector<string>> res;
    vector<string> path;
    partitionStr(s, 0, path, res);
    for(auto it : res){
        for(auto i : it) cout << i << " ";
        cout << endl;
    }
}

// ? 1007231543
int minPartitions(string str,int i,int n,vector<int>&dp){
    if (i == n) return 0;
    if (dp[i] != -1) return dp[i];
    int ans = INT_MAX;
    for(int j = i;j < n;j++){
        if (isPalindrome(str,i,j)){
            ans = min(ans, 1 + minPartitions(str,j+1,n,dp));
        }
    }
    return dp[i] = ans;
}
int palindromePartitioning2(string str){
    int n = str.size();
    vector<int>dp(n,-1);
    return minPartitions(str,0,n,dp) - 1;
}

// ? 1007231604
int maxSubArray(int i,int n,vector<int>nums,int k,vector<int>&dp){
    if (i == n) return 0;
    if (dp[i] != -1) return dp[i];
    int ans = INT_MIN;
    int maxi = INT_MIN;
    int len = 0;
    for(int ind = i;ind < min(i + k,n);ind++){
        len++;
        maxi = max(maxi,nums[ind]);
        int x = maxi * len + maxSubArray(ind+1,n,nums,k,dp); // (maximum upto i,ind)*(ind - i + 1) + f(ind+1,j,n,nums,k,dp)
        ans = max(ans,x);
    }
    return dp[i] = ans;
}
int maxSumPartitionArray(vector<int>nums, int k){
    int n = nums.size();
    vector<int>dp(n,-1);
    return maxSubArray(0,n,nums,k,dp);
}

// ? 1007231716
int maxRectangleAreaHistogram(vector<int>heights) {
    int n = heights.size();
    vector<int>leftWidth(n,0);
    vector<int>rightWidth(n,0);
    
    stack<int>st;
    for(int i = 0;i < n;i++){
        while(st.empty() == false && heights[st.top()] >= heights[i]){
            st.pop();
        }
        if (st.empty()) leftWidth[i] = i;
        else leftWidth[i] = i - st.top() - 1;
        st.push(i);
    }
    while (st.empty() == false) st.pop(); // clear stack

    for(int i = n-1;i >= 0;i--){
        while(st.empty() == false && heights[st.top()] >= heights[i]){
            st.pop();
        }
        if (st.empty()) rightWidth[i] = n-i-1;
        else rightWidth[i] = st.top() - i - 1;
        st.push(i);
    }
    int ans = 0;
    for(int i = 0;i < n;i++){
        ans = max(ans, ( rightWidth[i] + leftWidth[i] + 1)*heights[i]);
    }
    return ans;
}

// ? 1007231725
int maxRectangleGrid(vector<vector<int>>matrix) {
    int maxi = 0;
    int r = matrix.size();
    int c = matrix[0].size();
    vector<int>heights(c,0);
    for(int i = 0;i < r;i++){
        for(int j = 0;j < c;j++){
            if (matrix[i][j] == 1) heights[j]++;
            else heights[j] = 0;
        }
        maxi = max(maxi,maxRectangleAreaHistogram(heights));
    }
    return maxi;
}

// ? 1007231752
int countSubSquares(vector<vector<int>>matrix) {
    int r = matrix.size();
    int c = matrix[0].size();
    vector<vector<int>>dp(r,vector<int>(c,0)); // now of squares with in grid[i][j]
    
    // top row, left col only single side squares are possible
    for(int i = 0;i < r;i++){
        dp[i][0] = matrix[i][0];
    }
    for(int j = 0;j < c;j++){
        dp[0][j] = matrix[0][j];
    }
    
    for(int i = 1;i < r;i++){
        for(int j = 1;j < c;j++){
            if(matrix[i][j] == 0){
                dp[i][j] = 0;
            }else{
                dp[i][j] = 1 + min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
            }
        }
    }
    
    int sum = 0;
    for(int i = 0; i < r;i++){
        for(int j = 0;j < c;j++){
            sum += dp[i][j];
        }
    }
    printGrid(dp);
    return sum;
}

// ? 1107230901
int minCostConnectRopes(vector<int>arr){
	int n = arr.size();
    int cost = 0;
	
	priority_queue<int,vector<int>,greater<int>>pq;
	for(int i = 0;i < n;i++) pq.push(arr[i]);

	while (pq.empty() == false){
		int x1 = (pq.empty() == false) ? pq.top() : 0;
		pq.pop();
		int x2 = (pq.empty() == false) ? pq.top() : 0;
		pq.pop();
		cost += (x1 + x2);
		if (pq.empty() == false) pq.push({x1+x2});
	}

	return cost;
}

// ? 1107231030
int trappingWater(vector<int>heights){
    int n = heights.size();
    if (n == 0) return 0;
    
    stack<int>st;
    vector<int>leftMax(n,0);
    for(int i = 0;i < n;i++){
        if (st.empty()){
            leftMax[i] = 0;
            st.push(heights[i]);
        }
        else{
            int x = st.top();
            leftMax[i] = x;
            if (heights[i] >= x){
                st.pop();
                st.push(heights[i]);
            }
        }
    }

    while (st.empty() == false) st.pop(); // clear stack 
    vector<int>rightMax(n,0);
    for(int i = n-1;i >= 0;i--){
        if (st.empty()){
                rightMax[i] = 0;
                st.push(heights[i]);
        }
        else{
            int x = st.top();
            rightMax[i] = x;
            if (heights[i] >= x){
                st.pop();
                st.push(heights[i]);
            }
        }
    }

    vector<int>res(n,0);
    int ans = 0;
    for(int i = 0;i < n;i++){
        res[i] = min(leftMax[i],rightMax[i]);
        ans += max(0,res[i]-heights[i]);
    }
    return ans;
}

// ? 1107231133
class QUEUE {

	int front, rear;
	int cnt;
	int cap;
	vector<int> arr;

    public:
        QUEUE(int n){
            front = 0;
            rear = 0;
            cnt = 0;
            cap = n; 
            arr.resize(n+1);
        }

        // Enqueue (add) element 'e' at the end of the queue.
        void enqueue(int e){
            if (cnt == cap) return;
            arr[rear % cap] = e;
            rear++;
        }

        // Dequeue (retrieve) the element from the front of the queue.
        int dequeue(){
            if (front != rear){
                front++;
                return arr[front-1];
            }
            return -1;
        }
};

// ? 1107231146
class STACK {
    queue<int>q1;
    queue<int>q2;
    int size;
   public:
    STACK(){
        size = 0;
    }
    int getSize(){
        return size;
    }
    bool isEmpty(){
        return (size == 0);
    }
    void push(int ele){
        size++;
        // push ele to Q2
        // shift all elements from Q1 to Q2 one by one
        // swap q1 q2
        q2.push(ele);
        while (q1.empty() == false){
            q2.push(q1.front());
            q1.pop();
        }
        queue<int>q;
        q = q1;
        q1 = q2;
        q2 = q;
    }
    int pop(){
        if (size == 0) return -1;
        // top of q1
        size--;
        int x = q1.front();
        q1.pop();
        return x;
    }
    int top(){
        if (size == 0) return -1;
        return q1.front();
    }
};

// ? 1107231407
void nextGreaterElement(vector<int>arr){
    int n = arr.size();
	vector<int>nextMax(n,0);
	stack<int>st;
	for(int i = n-1;i >= 0;i--){
		while(st.empty()==false && st.top() <= arr[i]){
			st.pop();
		}
		if (st.empty()){
			nextMax[i] = -1;
		}else{
			nextMax[i] = st.top();
		}
		st.push(arr[i]);
	}
    printVector(arr);
    printVector(nextMax);
}

// ? 1107231428
void countGreater(vector<int>arr){
    int n = arr.size();
    vector<int>nextGreater(n,0);
    for(int i = 0;i < n;i++){
        int cnt = 0;
        for(int j = i+1;j < n;j++){
            if (arr[j] > arr[i]) cnt++;
        }
        nextGreater[i] = cnt;
    }
    printVector(arr);
    printVector(nextGreater);
}

// ? 1107231514
void collidingAsteroids(vector<int>rocks){
    int n = rocks.size();
    stack<int>st;
    for(int i = 0;i < n;i++){
        if (rocks[i] > 0){
            st.push(rocks[i]);
        }else{
            int r1 = rocks[i]*-1; // size of rock = absolute val
            // r1 moving in left direction

            if(st.empty()){
                st.push(r1 * -1);
                continue;
            }
            // if nearest left rock is moving left there is no rock to collide
            if (st.top() <= 0){
                st.push(r1 * -1);
                continue;
            }
            // if nearest left rock > r1, r1 will blast
            if(st.top() > r1){
                continue;
            }
            // if nearest left rock == r1 , both will blast
            if (st.top() == r1){
                st.pop();
                continue;
            }
            // r1 will remove all rocks to its left which are smaller in size
            while(st.empty() == false && st.top() >= 0 && st.top() < r1){
                st.pop();
            }
            if (st.empty()){
                st.push(-1 * r1);
            }else if (st.top() < 0) {
                st.push(-1 * r1);
            }else if (st.top() == r1) {
              st.pop();
            }
        }
    }
    vector<int>ans = {};
    while(st.empty() == false){
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    printVector(rocks);
    printVector(ans);
}

// ? 1107231639
int sumSubarrayMins(vector<int>arr){
    int ans = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        int left = 1;  // Count of subarrays with arr[i] as the minimum element
        int right = 1;

        // Count the number of subarrays on the left side of arr[i]
        int j = i - 1;
        while (j >= 0 && arr[j] >= arr[i]) {
            left++;
            j--;
        }

        // Count the number of subarrays on the right side of arr[i]
        j = i + 1;
        while (j < n && arr[j] > arr[i]) {
            right++;
            j++;
        }

        // Update the answer
        ans += arr[i] * left * right;
        ans %= 1000000007;  // Take the modulo to avoid overflow
    }
    return ans;
}

// ? 1107231927
struct DNode{
    int key;
    int value;
    DNode* prev;
    DNode* next;
    DNode(int k,int v){
        key = k;
        value = v;
        prev = NULL;
        next = NULL;
    }
};
class LRUCache{
    DNode* head;
    DNode* tail;
    unordered_map<int,DNode*>mp;
    int cap;
    int size;

    DNode* update(DNode* x){
        DNode* x1 = new DNode(x->key,x->value);
        // key is most used 

        // delete x 
        DNode* prevX = x->prev;
        DNode* nextX = x->next;
        prevX->next = nextX;
        nextX->prev = prevX;
        
        // and insert new Node with same key,value after head
        DNode* headNext = head->next;
        head->next = x1;
        x1->next = headNext;
        x1->prev = head;
        headNext->prev = x1;

        return x1;
    }

public:
    LRUCache(int capacity){
        head = new DNode(0,0);
        tail = new DNode(0,0);
        head->next = tail;
        head->prev = NULL;
        tail->prev = head;
        tail->next = NULL;
        cap = capacity;
        size = 0;
    }
    int get(int key){
        if (mp.find(key) == mp.end()){
            return -1;
        }
        // now key is most recent, so remove x and add x1 with same values of x after head
        DNode* x = mp[key];
        DNode* x1 = update(x);

        // update map 
        mp[key] = x1;
        return x1->value;
    }

    void put(int key, int value){
        if (mp.find(key) != mp.end()){
            // now key is most recent, so remove x and add x1 with same values of x after head
            DNode* x = mp[key];
            DNode* x1 = update(x);

            // update map
            mp[key] = x1;
            x1->value = value;
        }else{
            if (size == cap){
                // remove lcu
                DNode* lcu = tail->prev;
                DNode* lcuPrev = lcu->prev;
                lcuPrev->next = tail;
                tail->prev = lcuPrev;

                mp.erase(lcu->key);
                size--;
            }
            DNode* x1 = new DNode(key,value);
            DNode* headNext = head->next;
            head->next = x1;
            x1->prev = head;
            headNext->prev = x1;
            x1->next = headNext;
            mp[key] = x1;
            size++;
        }
    }
};

// ? 1207230801
struct DNode1{
    int key;
    int value;
    int freq;
    DNode1* prev;
    DNode1* next;
    DNode1(int k,int v,int f){
        key = k;
        value = v;
        freq = f;
        prev = NULL;
        next = NULL;
    }
};
class LRUList{
    DNode1* head;
    DNode1* tail;
    int size;
    int cap;
    public:
        LRUList(int capacity){
            head = new DNode1(0,0,0);
            tail = new DNode1(0,0,0);
            cap = capacity;
            size = 0;
            head->next = tail;
            head->prev = NULL;
            tail->prev = head;
            tail->next = NULL;
        }
        int getSize(){
            return size;
        }
        DNode1* getLRU(){
            if (size == 0) return NULL; 
            DNode1* lru = tail->prev;
            return lru;
        }
        void removeNode(DNode1* x){
            DNode1* xPrev = x->prev;
            DNode1* xNext = x->next;
            x->prev = NULL;
            x->next = NULL;
            xPrev->next = xNext;
            xNext->prev = xPrev;
            size--;
        }
        void push(DNode1* x1){
            if (size == cap){
                DNode1* lru = getLRU();
                removeNode(lru);
                size--;
            }
            DNode1* headNext = head->next;
            head->next = x1;
            x1->prev = head;
            x1->next = headNext;
            headNext->prev = x1;
            size++;
        }
};
class LFUCache{
    int size;
    int cap;
    int minFreq;
    unordered_map<int,DNode1*>mp; // key , node address
    unordered_map<int,LRUList*>freqMap; // freq, lru list
public:
    LFUCache(int capacity) {
        size = 0;
        cap = capacity;
        minFreq = 0;
    }
    void update(DNode1* x){   
        DNode1* x1 = new DNode1(x->key,x->value,x->freq+1);
        
        // remove x from current freqList 
        int f = x->freq;
        LRUList* f_list = freqMap[f];
        f_list->removeNode(x);
        mp[x1->key] = x1;

        // and add to nextList
        if (freqMap.find(x1->freq) == freqMap.end()){
            LRUList* x_List = new LRUList(cap);
            x_List->push(x1); 
            freqMap[x1->freq] = x_List;
        }else{
            LRUList* x_List = freqMap[x1->freq];
            x_List->push(x1); 
        }

        // if x is in MinFreq and afterRemoving x if (size of List == 0) increase minFreq
        if (f == minFreq){
            if (f_list->getSize() == 0){
                minFreq++;
            }
        }
    }
    int get(int key){
        if (mp.find(key) == mp.end()){
            return -1;
        }else{
            // update node
            DNode1* x = mp[key];
            int v = x->value;
            update(x);
            return v;
        }
    }
    void put(int key, int value){
        if (mp.find(key) == mp.end()){
            // new Node
            DNode1* x1 = new DNode1(key,value,1);
            if (size == cap){
                LRUList* x_List = freqMap[minFreq];
                DNode1* lru = x_List->getLRU();
                x_List->removeNode(lru);
                mp.erase(lru->key);

                LRUList* x1_List = freqMap[1];
                x1_List->push(x1);
                mp[x1->key] = x1;
            }else{
                if (freqMap.find(1) == freqMap.end()){
                    LRUList* x1_List = new LRUList(cap);
                    x1_List->push(x1);
                    mp[x1->key] = x1;
                    freqMap[1] = x1_List;
                }else{
                    LRUList* x1_List = freqMap[1];
                    x1_List->push(x1);
                    mp[x1->key] = x1;
                }
                size++;
            }
            minFreq = 1;
        }else{
            // update node
            DNode1* x = mp[key];
            x->value = value;
            update(x);
        }
    }
};

// ? 1207231142
bool knows(int a,int b){
    // given in question
    return true; // if a knows b, else false
}
int findCelebrity(int n){
	int candidate = 0;

    // Find a potential candidate who might be the celebrity
    for (int i = 1; i < n; i++) {
        if (knows(candidate, i)){
			// candidate knows i -> so candidate can't be a celebrity
			// i may have chance to be a celebrity
            candidate = i;
        }
    }

    // Verify if the candidate is the celebrity
    for (int i = 0; i < n; i++) {
        if (i != candidate && (knows(candidate, i) || !knows(i, candidate))) {
            return -1;  // The candidate is not a celebrity
        }
    }

    return candidate;
}

// ? 1207231206
int lengthOfLongestSubstring(string s) {
    int maxLen = 0;
    int n = s.length();
    int l = 0;
    int r = 0;
    unordered_set<char>st;
    while (r < n){
        if (st.find(s[r]) == st.end()){
            st.insert(s[r]);
        }else{
            while(st.find(s[r]) != st.end()){
                st.erase(s[l]);
                l++;
            }
            st.insert(s[r]);
        }
        maxLen = max(maxLen,(r-l+1));
        r++;
    }
    return maxLen;
}

// ? 1207231219
int kDistinctChars(int k, string str){
    int n = str.size();
    int maxLen = 0;
    int l = 0;
    int r = 0;
    unordered_map<char,int>mp;
    
    while (r < n){
        if (mp.find(str[r]) == mp.end()){
            // new char
            mp[str[r]] = 1;
            while (mp.size() > k){
                mp[str[l]]--;
                if (mp[str[l]] == 0){
                    mp.erase(str[l]);
                }
                l++;
            }
        }else{
            mp[str[r]]++;
        }
        maxLen = max(maxLen,r-l+1);
        r++;
    }

    return maxLen;
}

// ? 1207231225
int kDistinctSubarrays(vector<int>arr, int k){
    int n = arr.size();
    int ans = 0;
    int l = 0;
    int r = 0;
    unordered_map<int,int>mp;
    
    while (r < n){
        if (mp.find(arr[r]) == mp.end()){
            // new char
            mp[arr[r]] = 1;
            while (mp.size() > k){
                mp[arr[l]]--;
                if (mp[arr[l]] == 0){
                    mp.erase(arr[l]);
                }
                l++;
            }
        }else{
            mp[arr[r]]++;
        }
        ans += (r-l+1);
        r++;
    }

    return ans;
}

// ? 1207231310
int characterReplacement(string str, int k){
    int n = str.length();
    int l = 0;
    int r = 0;
    unordered_map<char,int>mp;
    int maxLen = 0;
    int maxCount = 0; // stores the cnt of  max Repeating char
    
    while(r < n){
        mp[str[r]]++;
        maxCount = max(maxCount,mp[str[r]]);
        if ((r-l+1)-maxCount > k){
            mp[str[l]]--;
            l++;
        }
        maxLen = max(maxLen,(r-l+1));
        r++;
    }
    return maxLen;
}

// ? 1207231341
 int numBinarySubarraysWithSum(vector<int>arr, int goal) {
    int ans = 0;
    int n = arr.size();
    int l = 0;
    int r = 0;
    int sum = 0;
    
    while (r < n){
        sum += arr[r];
        while (sum > goal){
            sum -= arr[l];
            l++;
        }
        if (sum == goal && l <= r){
            ans += 1;
            for(int i = l;i < r;i++){
                if (arr[i] == 0) ans++;
                else break;
            }
        }
        r++;
    }

    return ans;
}

// ? 1207231459
class MinStack {
    stack<pair<int,int>>st; // value , minimal till now
public:
    MinStack() { }
    void push(int val) {
        if (st.empty()){
            st.push({val,val});
        }else{
            int t = st.top().second;
            if (t < val){
                st.push({val,t});
            }else{
                st.push({val,val});
            }
        }
    }
    void pop() {
        st.pop();
    }
    int top() {
        return st.top().first;
    }
    int getMin() {
        return st.top().second;
    }
};

// ? 1207231533
class Queue2{
    stack<int>st1;
    stack<int>st2;
    public:
    Queue2(){ }
    void enQueue(int val){
        while(st1.empty() == false){
            st2.push(st1.top());
            st1.pop();
        }
        st1.push(val);
        while(st2.empty() == false){
            st1.push(st2.top());
            st2.pop();
        }
    }
    int deQueue(){
        if (st1.empty()) return -1;
        int x = st1.top();
        st1.pop();
        return x;
    }
    int peek(){
        if (st1.empty()) return -1;
        return st1.top();
    }
    bool isEmpty() {
        return (st1.empty());
    }
};

// ? 1307230817
int getRank(char c){
	if (c == '^') return 3;
  	
	if (c == '/' || c == '*') return 2;
  
  	if (c == '+' || c == '-') return 1;
  
    return -1;
}
string infixToPostfix(string exp){
	string ans = "";
	stack<char>st;

	for(char op : exp){
		if ((op >= 'a' && op <= 'z') || (op >= 'A' && op <= 'Z') || (op >= '0' && op <= '9')){
			ans += op;
		}else if (op == '('){
			st.push(op);
		}else if (op == ')'){
			// all operations remaining in btw ( and )to be completed
			while(st.top() != '('){
				ans += st.top();
				st.pop();
			}
			st.pop(); // pop (
		}else{
			while(st.empty() == false && getRank(st.top()) >= getRank(op)){
				ans += st.top();
				st.pop();
			}
			st.push(op);
		}
    }
	
	while (st.empty() == false) {
        ans += st.top();
        st.pop();
    }
	
	return ans;
}

// ? 1307230833
string infixToPrefix(string exp){
    reverse(exp.begin(),exp.end());
    for(int i = 0; i < exp.length();i++){
        if (exp[i] == '('){
            exp[i] = ')';
        }
        else if (exp[i] == ')'){
            exp[i] = '(';
        }
    }
    string postfixOfReverseExp = infixToPostfix(exp);
    reverse(postfixOfReverseExp.begin(),postfixOfReverseExp.end());
    return postfixOfReverseExp;
}

// ? 1307230911
string postToInfix(string postfix) {
    stack<string>st;
    for(char op : postfix){
        if ((op >= 'A' && op <= 'Z') || (op >= 'a' && op <= 'z') || (op >= '0' && op <= '9')){
            st.push(string(1, op)); // Convert char to string
        }else{
            string exp2 = st.top(); // 2nd operand
            st.pop();
            string exp1 = st.top(); // 1st operand
            st.pop();
            st.push('('+exp1 + string(1, op) + exp2+')');
        }
    }
    return st.top();
}

// ? 1307231018
string prefixToInfix(string prefix){
	stack<string>st;
	reverse(prefix.begin(),prefix.end());
	string postfix = prefix;
	string ans = "";
	for(auto op : postfix){
		if ((op >= 'A' && op <= 'Z') || (op >= 'a' && op <= 'z') || (op >= '0' && op <= '9')){
			st.push(string(1,op));
		}else{
			string exp2 = st.top();
			st.pop();
			string exp1 = st.top();
			st.pop();
			st.push('('+exp1+op+exp2+')');
		}
	}
	ans = st.top();
	reverse(ans.begin(),ans.end());
	for(int i = 0; i < ans.length();i++){
		if (ans[i] == '('){
			ans[i] = ')';
		}else if (ans[i] == ')'){
			ans[i] = '(';
		}
	}
	return ans;
}

// ? 1307231155
class BinaryTreeNode{
public :
    char data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
    BinaryTreeNode(char d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};
int getRank1(char op){
    if(op == '+' || op == '-'){
        return 1;
    }
    if (op == '*' || op == '/'){
        return 2;
    }
    if (op == '^'){
        return 3;
    }
    return -1;
}
string infix_Postfix(string exp){
    string ans = "";
    stack<char>st;
    for(char op : exp){
        if (op == '('){
            st.push(op);
        }
        else if (op == ')'){
            // pop all in btw ( )
            while (st.top() != '('){
                ans += st.top();
                st.pop();
            }
            st.pop(); // remove (
        }
        else if ((op >= 'A' && op <= 'Z') || (op >= 'a' && op <= 'z') ||(op >= '0' && op <= '9')){
            ans += op;
        }else{
            while(st.empty() == false && getRank1(st.top()) >= getRank1(op)){
                ans += st.top();
                st.pop();
            }
            st.push(op);
        }
    }
    while (st.empty() == false){
        ans += st.top();
        st.pop();
    }
    return ans;
}
void binaryExpressionTree(string exp){
    string postFix = infix_Postfix(exp);
    stack<BinaryTreeNode*>st;
    
    for(auto op : postFix){
        if ((op >= 'A' && op <= 'Z') || (op >= 'a' && op <= 'z') || (op >= '0' && op <= '9')){
            st.push(new BinaryTreeNode(op));
        }else{
            BinaryTreeNode* exp2 = st.top();
            st.pop();
            BinaryTreeNode* exp1 = st.top();
            st.pop();
            BinaryTreeNode* op1 = new BinaryTreeNode(op);
            op1->left = exp1;
            op1->right = exp2;
            st.push(op1);
        }
    }
    // st.top() is the answer
}

// ? 1307231417
struct TrieNode{
    TrieNode* dict[26];
    bool end = false;

    bool containChar(char ch){
        return (dict[ch-'a'] != NULL);
    }
    void put(char ch,TrieNode* n){
        dict[ch-'a'] = n;
    }
    TrieNode* getSubNode(char ch){
        return dict[ch-'a'];
    }
    void setEnd(){
        end = true;
    }
    bool isEnd(){
        return end;
    }
};
class Trie{
    TrieNode* root;
public:
    Trie(){
        root = new TrieNode();
    }
    void insert(string word) {
        TrieNode* node = root;
        for(auto ch : word){
            if (node->containChar(ch) == false){
                node->put(ch,new TrieNode());
            }
            // node moves to subNode
            node = node->getSubNode(ch);
        }
        node->setEnd(); // end of the word
    }
    bool search(string word) {
        TrieNode* node = root;
        for(auto ch : word){
            if (node->containChar(ch) == false) return false;
            node = node->getSubNode(ch);
        }
        // word completed, trie should also be completed
        return node->isEnd();
    }
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for(auto ch : prefix){
            if (node->containChar(ch) == false) return false;
            node = node->getSubNode(ch);
        }
        // prefix completed, but trie need not be completed
        return true;
    }
};

// ? 1307231513
struct TrieNode1{
    TrieNode1* dict[26];
    int cntEnd = 0;
    int cntPrefix = 0;
    
    void put(char ch,TrieNode1* n){ dict[ch-'a'] = n; }
    TrieNode1* getSubNode(char ch){ return dict[ch-'a']; }
    bool containsChar(char ch){ return (dict[ch-'a'] != NULL); }
    void increaseEnd(){ cntEnd++; }
    void increasePrefix(){ cntPrefix++; }
    int getPrefix(){ return cntPrefix; }
    int getEnd(){ return cntEnd; }
    void reducePrefix(){ cntPrefix--; }
    void deleteEnd(){ cntEnd--; }
};
class Trie1{
    TrieNode1* root;
    public:
    Trie1(){
        root = new TrieNode1();
    }
    void insert(string word){
        TrieNode1* node = root;
        for(auto ch : word){
            if (node->containsChar(ch) == false){
                node->put(ch,new TrieNode1());
            }
            node = node->getSubNode(ch);
            node->increasePrefix();
        }
        node->increaseEnd();
    }
    int cntWordEqualTo(string word){
        TrieNode1* node = root;
        for(auto ch : word){
            if (node->containsChar(ch) == false) return 0;
            node = node->getSubNode(ch);
        }
        return node->getEnd();
    }
    int cntWordsStartsWith(string word){
        TrieNode1* node = root;
        for(auto ch : word){
            if (node->containsChar(ch) == false) return 0;
            node = node->getSubNode(ch);
        }
        return node->getPrefix();
    }
    void remove(string word){ 
        // words are not deleted from trie, but instead we decrease the cnt
        TrieNode1* node = root;
        for(auto ch : word){
            if (node->containsChar(ch) == false) return ; // word not exisited;
            node = node->getSubNode(ch);
            node->reducePrefix();
        }
        node->deleteEnd();
    }
    bool isCompleteString(string str){
        TrieNode1* node = root;
        for(auto ch : str){
            if (node->containsChar(ch) == false) return false; // word not even exists
            node = node->getSubNode(ch);
            // check if any word ended here
            // if no word ended here means one of the prefix of str is not present in trie
            // so str can't be a complete string
            if (node->getEnd() == 0) return false;
        }
        return true;
    }
};

// ? 1307231552
string completeString(vector<string>words){
    int n = words.size();
    Trie1* trie = new Trie1();
    for(auto str : words){
        trie->insert(str);
    }
    string maxString = "";
    // all words inserted to trie
    for(int i = 0;i < n;i++){
        string str = words[i];
        int l = str.length();
        if (trie->isCompleteString(str)){
            if (l >= maxString.length()){
                maxString = str;
            }
        }
    }
    if (maxString == "") return "None";
    return maxString;
}

// ? 1307231647
class Trie2{
    TrieNode* root;
public:
    int cntDistinct;
    Trie2(){
        root = new TrieNode();
        cntDistinct = 1; // empty string
    }
    void insert(string word){
        TrieNode* node = root;
        for(auto ch : word){
            if (node->containChar(ch) == false){
                node->put(ch,new TrieNode());
                cntDistinct++;
            }
            node = node->getSubNode(ch);
        }
        node->setEnd();
    }
};
int countDistinctSubstrings(string str){
    Trie2* trie = new Trie2();
    int n = str.length();
    for(int i = 0;i < n;i++){
        trie->insert(str.substr(i,n-i));
    }
    return trie->cntDistinct;
}

// ? 1307232027
void per(vector<int>nums,int n,int ind,vector<vector<int>>&ans){
    if (ind == n){
        ans.push_back(nums);
        return ;
    }
    for(int i = ind;i < n;i++){
        // swap i,ind -> recursive
        swap(nums[i],nums[ind]);

        per(nums,n,ind+1,ans);

        // swap i,ind back
        swap(nums[i],nums[ind]);
    }
}
void permutationList(vector<int> nums) {
    vector<vector<int>>ans;
    per(nums,nums.size(),0,ans);
    printGrid(ans);
}

// ? 1307230811
int getXOR(int a, int b){
    // a xor b
    return (a ^ b);
}
int getBit(int num, int i){
    // checking if i th bit of num is 1
    return ((num >> i) & 1 != 0);
}
int setBit(int num, int i){
    // making i th bit of num as 1
    return (num | (1 << i));
}
int eraseBit(int num,int i){
    // making i th bit of num as 0
    return(num & (~(1 << i)));
}
string evenOdd(int num){
    // if first bit is set then odd
    int firstBit = 1 & (num); 
    if (firstBit == 1){
        return "odd";
    }
    return "false";
}
bool isPowerOfTwo(int n){
    // check if n = power of 2
    int x = 1;
    while (x < n){
        x = (x << 1);
    }
    return (x == n);
}

// ? 1307231013
int setRightMostBit(int n){
    int x = n;
    int i = 0;
    int j = -1;
    while (x != 0){
        if ((x & 1) == 0){
            j = i;
            break;
        }
        i++;
        x = x >> 1;
    }
    // j th bit is the rightMost unset bit in n
    if (j == -1) return n;
    n = (n | (1 << j));
    return n;
}

// ? 1307231153
int flipBits(int A, int B){
    // number of bits needed to be flip to make A -> B
    int x = A ^ B;
    // count set bits in x
    int cnt = 0;
    while (x != 0){
        if ((1 & x) == 1) cnt++;
        x = x >> 1;
    }
    return cnt;
}

// ? 1307231354
void permuteUnique(vector<int>nums){
    // nums may have duplicates
    int n = nums.size();
    if (n == 0) return ;
    vector<vector<int>>ans;

    queue<pair<vector<int>,int>>q;
    q.push({nums,0});
    
    while(q.empty() == false){
        vector<int>vec = q.front().first;
        int ind = q.front().second;
        q.pop();
        if (ind == n-1){
            ans.push_back(vec);
            continue;
        }
        unordered_set<int>st;
        for(int j = ind;j < n;j++){
            if (st.find(vec[j]) != st.end()) continue;
            
            st.insert(vec[j]);
            // swap ind,j
            int x = vec[ind];
            vec[ind] = vec[j];
            vec[j] = x;

            q.push({vec,ind+1});
            // swap back
            x = vec[ind];
            vec[ind] = vec[j];
            vec[j] = x;
        }
    }
    printGrid(ans);
}

// ? 1607231006
void heapify(vector<int>&nums,int ind,int n){
    int l = 2 * ind + 1;
    int r = 2 * ind + 2;
    int largest = ind;

    if (l < n && nums[l] > nums[largest]) {
        largest = l;
    }
    if (r < n && nums[r] > nums[largest]) {
        largest = r;
    }

    if (largest != ind) {
        swap(nums[ind], nums[largest]);
        heapify(nums, largest, n);
    }
}
void buildHeap(vector<int>&nums,int n){
    for(int i = n/2-1;i >= 0;i--){
        heapify(nums,i,n);
    }
}
vector<int> heapSort(vector<int>& nums){
    int n = nums.size();
    buildHeap(nums,n);
    for(int i = n-1;i >= 0;i--){
        // swap nums[0] <-> nums[i]
        swap(nums[0],nums[i]);
        heapify(nums,0,i);
    }
    return nums;
}

// ? 1607231020
int minBracketsAddToMakeValid(string str) {
    int openCount = 0;
    int moves = 0;

    for (char c : str){
        if (c == '(') {
            openCount++;
        } else if (c == ')'){
            if (openCount > 0) {
                openCount--;
            } else {
                moves++;
            }
        }
    }

    moves += openCount;
    return moves;
}

// ? 1607231039
LLNode* swapTwo(LLNode* head,int l){
    if (head == NULL || l < 2) return head;
    LLNode* n1 = head;
    LLNode* n2 = head->next;
    LLNode* n3 = head->next->next;
    n2->next = n1;
    n1->next = swapTwo(n3,l-2);
    return n2;
}
LLNode* swapPairs(LLNode* head){
    int len = 0;
    LLNode* temp = head;
    while (temp != NULL){
        len++;
        temp = temp->next;
    }
    return swapTwo(head,len);
}

// ? 1607231926
string addBinary(string a, string b) {
    string ans = "";

    int aN = a.length()-1;
    int bN = b.length()-1;
    int carry = 0;

    while (aN >= 0 || bN >= 0 || carry != 0){
        int a1 = (aN >= 0) ? (a[aN] == '1' ? 1 : 0) : 0;
        int b1 = (bN >= 0) ? (b[bN] == '1' ? 1 : 0) : 0;
        
        if (a1 + b1 + carry == 0){
            ans = '0' + ans;
            carry = 0;
        }
        else if (a1 + b1 + carry == 1){
            ans = '1' + ans;
            carry = 0;
        }
        else if (a1 + b1 + carry == 2){
            ans = '0' + ans;
            carry = 1;
        }
        else if (a1 + b1 + carry == 3){
            ans = '1' + ans;
            carry = 1;
        }
        aN--;
        bN--;
    }
    return ans;
}

// ? 1607232013
LLNode* partitionList(LLNode* head, int x){
    LLNode* dummy1 = new LLNode(0);
    LLNode* dummy2 = new LLNode(0);
    
    LLNode* t1 = dummy1;
    LLNode* t2 = dummy2;

    
    LLNode* temp = head;
    
    while (temp != NULL){
        if(temp->data < x){
            LLNode* t = temp->next;
            temp->next = NULL;
            t1->next = temp;
            t1 = t1->next;
            temp = t;
        }
        else{
            LLNode* t = temp->next;
            temp->next = NULL;
            t2->next = temp;
            t2 = t2->next;
            temp = t;
        }
    }
    
    if (dummy1->next == NULL) return dummy2->next;

    t1->next = dummy2->next;
    return dummy1->next;
}

// ? 1707230839
int maxPointsLine(vector<vector<int>>points){
    int n = points.size();
    unordered_map<double, int> mp; // {slope, count}
    int maxPoints = 0;

    for (int i = 0; i < n; i++){
        mp.clear(); // Clear the map for each point

        int verticalPoints = 0; // Count of points with vertical lines

        for (int j = i + 1; j < n; j++){
            if (points[i][0] == points[j][0]){
                // Count the points with the same x-coordinate
                verticalPoints++;
            }else{
                // Calculate the slope of the line passing through points[i] and points[j]
                double slope = (double)(points[j][1] - points[i][1]) / (points[j][0] - points[i][0]);
                mp[slope]++;
            }
        }

        // Find the maximum count of points on the same line
        int currentMax = verticalPoints;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            currentMax = max(currentMax, it->second);
        }

        maxPoints = max(maxPoints, currentMax + 1);
    }

    return maxPoints;
}

// ? 2507231142
class MedianFinder {
    priority_queue<int>pq1; // max heap
    priority_queue<int,vector<int>,greater<int>>pq2; // min heap
public:
    MedianFinder() {}
    void addNum(int num) {
        if (pq1.empty() || num < pq1.top()){
            pq1.push(num);
        }else{
            pq2.push(num);
        }
        // make sure sizes of pq2 , pq1 differ atmost by 1 

        if (pq1.size() > pq2.size() + 1){ 
            // move one ele from pq1 to pq2
            pq2.push(pq1.top());
            pq1.pop();
        }
        else if (pq2.size() > pq1.size() + 1){
            // move one ele from pq2 to pq1
            pq1.push(pq2.top());
            pq2.pop();
        }
    }
    double findMedian() {
        if (pq1.size() == 0) return 0.0;
        if (pq1.size() == pq2.size()) { 
            // even count
            return (pq1.top() + pq2.top())/ 2.0;
        }else{
            // odd count
            if (pq2.size() > pq1.size()) return double( pq2.top() );
            return double( pq1.top() );
        }
    }
};

// ? 2507231431
int nearestExit(vector<vector<int>>maze, vector<int>entrance){
    // 1 -> open. 0 -> wall
    int r = maze.size();
    int c = maze[0].size();
    queue<pair<int,pair<int,int>>>q; // {dis , x1 , y1}
    q.push({0,{entrance[0],entrance[1]}});
    maze[entrance[0]][entrance[1]] = 0;
    while (q.empty() == false){
        int d = q.front().first;
        int r1 = q.front().second.first;
        int c1 = q.front().second.second;
        q.pop();
        int d1[4] = {-1,0,1,0};
        int d2[4] = {0,-1,0,1};
        for(int i = 0; i < 4;i++){
            int r2 = r1 + d1[i];
            int c2 = c1 + d2[i];
            if (r2 >= 0 && c2 >= 0 && r2 < r && c2 < c){
                if (maze[r2][c2] == 1){
                    if (c2 == 0 || c2 == c-1 || r2 == 0 || r2 == r-1) return d+1;
                    q.push({d+1,{r2,c2}});
                    maze[r2][c2] = 0;
                }
            }
        }
    }
    return -1;
}

// ? 2607231206
static bool compareEvents(vector<int>&e1,vector<int>&e2){
    // sorted based on end day, 
    // same end day => based on start day
    if (e1[1] == e2[1]) return e1[0] < e2[0];
    return e1[1] < e2[1];
}
int maxTime(vector<vector<int>>events){
    int maxi = 0;
    for(auto e : events){
        maxi = max(maxi,e[1]);
    }
    return maxi;
}
int maxEventsAttend(vector<vector<int>>events){
    int n = events.size();
    if (n == 0) return 0;
    sort(events.begin(),events.end(),compareEvents);
    unordered_map<int,int>mp;
    int cnt = 1;
    int endTime = events[0][1];
    mp[events[0][0]] = 1; 
    for(int i = 1;i < n;i++){
        if (events[i][0] > endTime){
            cnt++;
            mp[events[i][0]] = 1;
            continue;
        }
        for(int j = events[i][0]; j <= events[i][1];j++){
            if (mp.find(j) == mp.end()){
                cnt++;
                mp[j] = 1;
                break;
            }
        }
    }
    return cnt;
}

// ? 2707231004
int dfsGrid(vector<vector<int>>&matrix,int r1,int c1,vector<vector<int>>& dp,int r,int c){
    if (dp[r1][c1] != 0) return dp[r1][c1];
    int maxLen = 1;
    int d1[4] = {-1,0,1,0};
    int d2[4] = {0,-1,0,1};
    for(int i = 0;i < 4;i++){
        int r2 = r1 + d1[i];
        int c2 = c1 + d2[i];
        if (r2 >= 0 && r2 < r && c2 >=0 && c2 < c){
            if (r2 >= 0 && r2 < r && c2 >= 0 && c2 < c && matrix[r2][c2] > matrix[r1][c1]) {
                maxLen = max(maxLen, 1 + dfsGrid(matrix, r2, c2, dp, r, c));
            }
        }
    }
    return dp[r1][c1] = maxLen;
}
int longestIncreasePathGrid(vector<vector<int>>matrix){
    int ans = 0;
    int r = matrix.size();
    int c = matrix[0].size();
    vector<vector<int>>dp(r,vector<int>(c,0));
    for(int i = 0; i < r;i++){
        for(int j = 0;j < c;j++){
            int maxLen = dfsGrid(matrix,i,j,dp,r,c);
            ans = max(ans,maxLen);
        }
    }
    return ans;
}

// ? 2607231136
int mostBooked(int n, vector<vector<int>>meetings) {
    sort(meetings.begin(), meetings.end()); // based on starting time

    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>engaged; // end Time, room
    priority_queue<int,vector<int>,greater<int>>unused;
    
    unordered_map<int,int>m;
    for(int i = 0; i < n; i++) unused.push(i);

    for(auto x : meetings) {
        int start = x[0],end = x[1];
        // free room with completed meetings
        while(engaged.size() > 0 && engaged.top().first <= start){
            int room = engaged.top().second;
            engaged.pop();
            unused.push(room);
        }
        if(unused.size() > 0){
            int room = unused.top();
            unused.pop();
            m[room]++;
            engaged.push({end,room});    // room not available until end time
        }
        else{
            // no free room , waiting 
            // meet x will continue the top meet room which will complete first
            pair<long long,int>topmost = engaged.top();
            engaged.pop();
            m[topmost.second]++; // usage of room
            long long newend = topmost.first;
            newend += (end-start);   // end time of room increased by x meet duration 
            engaged.push({newend,topmost.second});
        }
    }

    int maxi=0;
    for(int i=0; i<n; i++){
        if(m[i] > m[maxi])
            maxi=i;
    }
    return maxi;
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

    // ? 1206231844
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

    // ? 2906231438
    // vector<vector<int>>adj[5] = {{{1,2},{2,1}},{{0,2},{2,1}},{{0,2},{1,1},{4,2},{3,2}},{{2,2},{4,1}},{{2,2},{3,1}}};
    // primsAlgoMinSpanTree(5,adj);

    // ? 2906231514
    // DisJointSet set1(7);
    // cout << set1.findUltimateParent(2) << endl;
    // set1.unionBySize(1,2);
    // cout << set1.findUltimateParent(2) << endl;
    // set1.unionBySize(2,3);
    // set1.unionBySize(4,5);
    // cout << set1.findUltimateParent(5) << endl;
    // set1.unionBySize(6,7);
    // set1.unionBySize(5,6);
    // cout << set1.findUltimateParent(7) << endl;
    // set1.unionBySize(3,7);
    // cout << set1.findUltimateParent(7) << endl;

    // ? 2906231529
    // vector<vector<int>>adj[5] = {{{1,2},{2,1}},{{0,2},{2,1}},{{0,2},{1,1},{4,2},{3,2}},{{2,2},{4,1}},{{2,2},{3,1}}};
    // krushalMinSpanTree(5,adj);

    // ? 2906231554
    // cout << connectingGraph(6,{{0,1},{0,2},{0,3},{1,2},{1,3}}) << endl;

    // ? 2906231929
    // numOfIslands2(4,5,{{0,0},{1,3},{1,1},{0,4},{0,3},{0,1},{0,2}});

    // ? 2906232011
    // cout << maxConnectionLand({{1,1,0,1,1},{0,1,0,1,0},{0,0,0,0,0}}) << endl;

    // ? 3006232047
    // cout << maxStonesRemove({{0,0},{0,1},{1,0},{1,2},{2,1} ,{2,2}}) << endl;

    // ? 3006230954
    // vector<int>adj[5] = {{1,3,2},{0,2},{1,0},{0,4},{3}};
    // cout << isEdgeBridge(5,adj,0,3) << endl;

    // ? 3006231001
    // criticalConnections(12,{{0,1},{0,3},{1,2},{2,3},{3,4},{4,5},{5,6},{5,8},{6,7},{7,8},{7,9},{9,10},{9,11},{11,10}});
    // criticalConnections(13,{{0,1},{0,3},{1,2},{2,3},{3,4},{4,5},{5,6},{5,8},{6,7},{7,8},{7,9},{9,12},{12,8},{9,10},{9,11},{11,10}});

    // ? 0407231011
    // cout << climbStairs1(10) << endl;

    // ? 0407231134
    // cout << minEnergyFrogJump({10,10}) << endl;

    // ? 0407231203
    // cout << minCostKJumps({10,30,40,50,20},3) << endl;

    // ? 0407231238
    // cout << houseRobber1({5,5,10,100,10,5}) << endl;

    // ? 0407231853
    // vector<vector<int>>points = {{1,2,5},{3,1,1},{3,3,3}};
    // cout << maxPointsTrain(points) << endl;

    // ? 0507231006
    // cout << gridPaths1(3,3) << endl;

    // ? 0507231106
    // cout << gridPaths2(3,3,{{0,0,0},{0,1,0},{0,0,0}}) << endl;

    // ? 0507231135
    // cout << minSumPathGrid({{9,4,9,9},{6,7,6,4},{8,3,3,7},{7,4,9,10}}) << endl;

    // ? 0507231145
    // cout << minSumTriangle({{2},{3,4},{6,5,7},{4,1,8,3}}) << endl;

    // ? 0507231404
    // cout << maxSumFallGrid({{348, 391},{618, 193}}) << endl;

    // ? 0607230753
    // cout << subSetTarget({3,34,4,12,5,2},9) << endl;

    // ? 0607230850
    // cout << minDiffSubSetPartition({1,6,11,5}) << endl;

    // ? 0607230858
    // cout << equalPartitionSubSet({1,5,11,5}) << endl;

    // ? 0607231009
    // cout << countSubSetsSumK({0,0,1},1) << endl;

    // ? 0607231112
    // cout << countPartitionsDiff(3,{5,2,6,4}) << endl;

    // ? 0607231149
    // cout << knapSack10(4,{4,5,1},{1,2,3}) << endl;

    // ? 0607231522
    // cout << minCoinsInfiniteSupply({1,2,3},7) << endl;

    // ? 0607232217
    // cout << countWaysInfiniteSupply({1,2,3},4) << endl;

    // ? 0707230809
    // cout << knapSackInfinite(8,{1,4,5,7},{1,3,4,5}) << endl;

    // ? 0707230827
    // cout << rodCutting({2,5,8,9,10,17,17,20}) << endl;

    // ? 0707230846
    // cout << longCommonSubSeqString("ABCDGH","AEDFHR") << endl;

    // ? 0707231053
    // all_longest_common_subsequences("abaaa","baabaca");

    // ? 0707231144
    // cout << longestCommonSubstr("ABCDGH","ACDGHR") << endl;

    // ? 0707231324
    // cout << longestPalinSubseq("bbabcbcab") << endl;

    // ? 0707231417
    // cout << maxConsecutiveTF("TTFTF",1) << endl;
    
    // ? 0707231451
    // cout << minInsertionsToMakePalindrome("abcaa") << endl;

    // ? 0707231510
    // cout << convertStringMinInsDel("heap","pea") << endl;

    // ? 0707231518
    // cout << shortestCommonSuperSeq("abcd","cdyx") << endl;

    // ? 0707231916
    // cout << subsequenceMatchCount("babgbag","bag") << endl;

    // ? 0707232043
    // cout << delReplaceInsertString("geek","gesek") << endl;

    // ? 0807230739
    // cout << minScoreGraphCities(4,{{1,2,9},{2,3,6},{2,4,5},{1,4,7}}) << endl;

    // ? 0807230747
    // cout << dividePlayers({3,2,5,1,3,4}) << endl;

    // ? 0807230756
    // cout << wildCardMatchStrings("**a?b","acb") << endl;

    // ? 0807231041
    // cout << maxProfitStock1({7,1,2,9,10}) << endl;

    // ? 0807231055
    // stockBuySellSegments({100,180,260,310,40,535,695});

    // ? 0807231134
    // cout << maxProfitMultipleStocks({100,180,260,310,40,535,695}) << endl;

    // ? 0807231244
    // cout << maxBombs({{1,2,3},{2,3,1},{3,4,2},{4,5,3},{5,6,4}}) << endl;

    // ? 0807231344
    // vector<int>prices = {10,22,5,75,65,80};
    // cout << stock_n_transactions(prices,2) << endl;

    // ? 0807231847
    // cout << longestSquareStreak({2,1,4,8,16,64}) << endl;

    // ? 0807231936
    // cout << captureForts({1,0,0,-1,0,0,0,1}) << endl;

    // ? 0907230758
    // cout << collectAppleGraph(7,{{0,1},{0,2},{2,3},{2,6},{1,4},{1,5}},{0,0,1,0,1,1,0}) << endl;

    // ? 0907230942
    // vector<int>prices = {4,9,0,4,10};
    // cout << sellBuyStockCoolDown(prices) << endl;

    // ? 0907230957
    // vector<int>prices = {1,3,5,6};
    // cout << sellBuyStockFee(2,prices) << endl;

    // ? 0907231136
    // printLongestIncreasingSubSeq({1,3,4,2,11,5});

    // ? 0907231233
    // divisibleSet({1,15,16,3,4,8});

    // ? 0907231407
    // longestStrChain({"x","xy","xx","xyx","y"});

    // ? 0907231537
    // cout << findNumberOfLIS({20,3,60,50,90,80}) << endl;

    // ? 0907231751
    // cout << longestBitonicSequence({12,11,40,5,3,1}) << endl;

    // ? 0907231835
    // cout << matrixChainMultiplication({10,15,20,25}) << endl;

    // ? 1007231025
    // cout << smallestEquivalentString("aba","mxt","abmxtv") << endl;

    // ? 1007231123
    // cout << minCostCutting(7,{1,4,3,5}) << endl;

    // ? 1007231136
    // cout << maxCutRod({2,5,7,8,10},5) << endl;

    // ? 1007231420
    // cout << ballonCoins({7,1,8}) << endl;

    // ? 1007231437
    // cout << noWaysToMakeExpTrue("T^F|T&F^T|F") << endl;

    // ? 1007231523
    // palindromePartitioning1("aaba");

    // ? 1007231543
    // cout << palindromePartitioning2("aaba") << endl;

    // ? 1007231604
    // cout << maxSumPartitionArray({1,20,13,4,4,1},3) << endl;

    // ? 1007231716
    // cout << maxRectangleAreaHistogram({2,1,5,6,2,3}) << endl;

    // ? 1007231725
    // cout << maxRectangleGrid({{1,0,1,0,0},{1,1,1,1,1},{1,0,1,1,1},{0,0,0,1,1}}) << endl;

    // ? 1007231752
    // cout << countSubSquares({{1,0,1,1},{0,1,1,1},{1,1,1,1},{0,1,1,1}}) << endl;

    // ? 1107230901
    // cout << minCostConnectRopes({4,3,2,6}) << endl;

    // ? 1107231030
    // cout << trappingWater({0,1,0,2,1,0,1,3,2,1,2,1}) << endl;

    // ? 1107231133
    // QUEUE q1(7);
    // q1.enqueue(5);
    // q1.enqueue(2);
    // cout << q1.dequeue() << endl;

    // ? 1107231146
    // STACK st;
    // st.push(2);
    // st.push(3);
    // cout << st.top() << endl;

    // ? 1107231407
    // nextGreaterElement({1,3,4,2,6,8,10,7,3});

    // ? 1107231428
    // countGreater({1,2,4,3,10,6});

    // ? 1107231514
    // collidingAsteroids({6,7,-9,7});

    // ? 1107231639
    // cout << sumSubarrayMins({1,5,4,2,3,6,7}) << endl;

    // ? 1107231927

    // ? 1107232103
    
    // ? 1207231142
    // cout << findCelebrity(5) << endl;

    // ? 1207231206
    // cout << lengthOfLongestSubstring("abcabdcabe") << endl;

    // ? 1207231219
    // cout << kDistinctChars(2,"abbbbbbc") << endl;

    // ? 1207231225
    // cout << kDistinctSubarrays({1,1,2,3},2) << endl;

    // ? 1207231310
    // cout << characterReplacement("aabcaac",2) << endl;

    // ? 1207231341
    // cout << numBinarySubarraysWithSum({1,0,1,0,0,1},2) << endl;

    // ? 1207231459
    // MinStack* st = new MinStack();
    // st->push(4);
    // st->push(-1);
    // st->push(3);
    // cout << st->getMin() << endl;
    // st->pop();
    // cout << st->getMin() << endl;

    // ? 1207231533

    // ? 1307230817
    // cout << infixToPostfix("A+B/C*(D-E)") << endl;

    // ? 1307230833
    // cout << infixToPrefix("A+B/C*(D-E)") << endl;

    // ? 1307230911
    // cout << postToInfix("sl+Pi+-") << endl;

    // ? 1307231018
    // cout << prefixToInfix("/*/sy+jt*/wj*dc") << endl;

    // ? 1307231155
    // cout << binaryExpressionTree("A+B/C*(D-E)") << endl;

    // ? 1307231417
    // Trie* t = new Trie();
    // t->insert("apple");
    // t->insert("apps");
    // t->insert("age");
    // cout << t->startsWith("app") << endl; // gives 1 if there is atleast one word starting with app

    // ? 1307231513
    // Trie1* t = new Trie1();
    // t->insert("apple");
    // t->insert("apps");
    // t->insert("apple");
    // t->insert("bat");
    // t->insert("age");
    // cout << t->cntWordsStartsWith("app") << endl; 
    // cout << t->cntWordEqualTo("apple") << endl; 

    // ? 1307231552
    // cout << completeString({"n","ni","nin","ninj","ninja","ning"}) << endl;

    // ? 1307231647
    // cout << countDistinctSubstrings("abab") << endl;

    // ? 1307232027
    // permutationList({1,2,3,4});

    // ? 1307230811

    // ? 1307231013
    // cout << setRightMostBit(13) << endl;

    // ? 1307231153
    // cout << flipBits(3,9) << endl;

    // ? 1307231354
    // permuteUnique({1,2,1});

    // ? 1607231006
    // vector<int>vec = {-4,0,7,4,9,-5,-1,0,-7,-1};
    // printVector(vec);
    // heapSort(vec);
    // printVector(vec);

    // ? 1607231020
    // cout << minBracketsAddToMakeValid("((()(()))(") << endl;

    // ? 1607231039
    // LLNode* l = buildList({1,2,3,4,5});
    // printList(l);
    // l = swapPairs(l);
    // printList(l);

    // ? 1607231926
    // cout << addBinary("111","101") << endl;

    // ? 1607232013
    // LLNode* l = buildList({1,4,3,2,5,2});
    // printList(l);
    // l = partitionList(l,3);
    // printList(l);

    // ? 1707230839
    // cout << maxPointsLine({{1,1},{3,3},{4,4},{-1,0},{-2,-1}}) << endl;

    // ? 2507231431
    // cout << nearestExit({{0,0,0},{1,1,1},{0,0,0}},{1,0}) << endl;

    // ? 2607231206
    // cout << maxEventsAttend({{3,5},{3,5},{3,5}}) << endl;

    // ? 2707231004
    // cout << longestIncreasePathGrid({{9,9,4},{6,6,8},{2,1,1}}) << endl;

    // ? 2607231136
    cout << mostBooked(3,{{1,20},{2,10},{3,5},{4,9},{6,8}}) << endl;

    cout << endl;
    return 0;
}
