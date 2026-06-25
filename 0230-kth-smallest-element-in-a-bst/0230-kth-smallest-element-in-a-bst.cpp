/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void smallest(TreeNode* root,int &k,vector<int> &ans){
        if(!root) return;
        smallest(root->left,k,ans);
        ans.push_back(root->val);
        smallest(root->right,k,ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> ans;
        smallest(root,k,ans);
        return ans[k-1];
    }
};