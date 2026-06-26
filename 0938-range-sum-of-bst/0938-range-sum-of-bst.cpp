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
     int ans = 0;
void helper(TreeNode* root, int l, int r) {
    if(!root) return;
        helper(root->left, l, r);
    if(l <= root->val && root->val <= r) ans += root->val;
        helper(root->right, l, r);
    }
int rangeSumBST(TreeNode* root, int low, int high) {
        helper(root, low, high);
    return ans;
    }
};