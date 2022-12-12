#include<iostream>
#include<vector>
#include<cstdlib>
#include<queue>

using namespace std;

// HEAP => Ordered Binary Tree
// MAX HEAP => val of parent > val of child

/*
Functions Required

* BUILD MAX HEAP => creates max heap from unsorted array
* HEAPIFY => similar to BUILD MAX HEAP but assumes part of array is already sorted

Procedure

* Create MAX HEAP
* Remove largest item
* Place item in sorted partition

Represent array as tree
2 8 5 3 9 1
                   
                    2
            8               5
        3       9       1

assume array is unsorted
call BUILD MAX HEAP
                    9
            8               5
        3       2       1
*/

struct Node {
    int val;
    struct Node* left;
    struct Node* right;
};

void buildMaxHeapTree(struct Node* root, struct Node* parent) {
    if(root->left != nullptr) {
        buildMaxHeapTree(root->left, root);
    }
    if(root -> right != nullptr) {
        buildMaxHeapTree(root->right, root);
    }
    if(parent == nullptr) return;
    if(root->val > parent-> val) {
        int t = parent->val;
        parent->val = root->val;
        root->val = t;
        buildMaxHeapTree(root, parent);
    }
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapify(vector<int>& nums, int max, int n) {
    int left = (2*max)+1;
    int right = (2*max)+2;
    int largest = max;
    if(left < n && nums[left] > nums[max])
        largest = left;
    if(right < n && nums[right] > nums[max])
        largest = right;
    
    if(max != largest) {
        swap(&nums[max], &nums[largest]);
        heapify(nums, largest, n);
    }
}

void buildMaxHeap(vector<int>& nums) {
    int n = nums.size();
    for(int i=n/2 - 1; i>=0; i--) {
        heapify(nums, i, n);
    }
}

void heapSort(vector<int>& nums) {
    int n = nums.size();
    buildMaxHeap(nums);
    for(int i=n-1; i>=0; i--) {
        swap(&nums[0], &nums[i]);
        heapify(nums, 0, i);
    }
}

struct Node* deleteAndMerge(struct Node* root, vector<int>& ans) {
    ans.push_back(root->val);
    struct Node* iter = root;
    while(iter->right!=nullptr) iter = iter->right;
    iter->right = root->left;
    root = root->right;
    return root;
}

struct Node* makeNode(int x, struct Node* l = nullptr, struct Node* r = nullptr) {
    struct Node* root = (struct Node*)malloc(sizeof(struct Node));
    root->val = x;
    root->left = l;
    root->right = r;
    return root;
}

struct Node* arrayToTree(vector<int>& nums, int i, int n) {
    struct Node* root = nullptr;
    if(i < n) {
        root = makeNode(nums[i]);
        root->left = arrayToTree(nums, (2*i)+1, n);
        root->right = arrayToTree(nums, (2*i)+2, n);
    }
    return root;
}

void printLevelOrder(struct Node* root) {
    queue<struct Node*>q;
    q.push(root);
    while(!q.empty()) {
        struct Node* fn = q.front();
        cout<<fn->val<<" ";
        if(fn->left != nullptr) q.push(fn->left);
        if(fn->right != nullptr) q.push(fn->right);
        q.pop();
    }
}

void inputVector(vector<int>& nums, int s) {
    int t;
    for (int i = 0; i < s; i++) {
        cin >> t;
        nums.push_back(t);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<int>v;

    inputVector(v, n);
    // struct Node* tree = arrayToTree(v, 0, n);

    // vector<int>ans;
    // while(tree != nullptr) {
    //     buildMaxHeapTree(tree, nullptr);
    //     tree = deleteAndMerge(tree, ans);
    // }

    // for(int i:ans) cout<<i<<" ";

    heapSort(v);
    for(int i:v) cout<<i<<" ";

    return 0;
}