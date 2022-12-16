#include<iostream>
#include<unordered_map>
#include<algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    int robber(TreeNode* root, bool linked, unordered_map<TreeNode*, int>& hmap, unordered_map<TreeNode*, int>& hmapl) {
        if(root == nullptr) return 0;

        if(!linked && hmap.find(root) != hmap.end()) return hmap[root];
        if(linked && hmapl.find(root) != hmapl.end()) return hmapl[root];

        int include = 0, exclude = 0;

        if(!linked) 
                include = root->val + robber(root->left, true, hmap, hmapl) + robber(root->right, true, hmap, hmapl);

        exclude = robber(root->left, false, hmap, hmapl) + robber(root->right, false, hmap, hmapl);
        
        hmapl.insert({root, exclude});

        int ans = max(include, exclude);
        
        if(!linked)
            hmap.insert({root, ans});

        return ans;
    }
    
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int>hmap, hmapl;
        return robber(root, false, hmap, hmapl);
    }
};