class Solution {
public:
void inorder(TreeNode* root,vector<TreeNode*> &v){
if(root==NULL) return;
if(root->left) inorder(root->left,v);
        v.push_back(root);
if(root->right) inorder(root->right,v);
    }
    TreeNode* solve(int low,int high,vector<TreeNode*> &v){
if(low>high)
return NULL;
        int m=(low+high)/2;
        v[m]->left=solve(low,m-1,v);
        v[m]->right=solve(m+1,high,v);
return v[m];
    }
    TreeNode* balanceBST(TreeNode* root) {
     vector<TreeNode*> v;
     inorder(root,v);
return solve(0,v.size()-1,v);
    }
};