class Solution {
public:
    void preOrder(TreeNode* root, vector<TreeNode*>& nodes) {
        if (root == NULL) return;
        nodes.push_back(root);
        preOrder(root->left, nodes);
        preOrder(root->right, nodes);
    }

    void flatten(TreeNode* root) {
        if (root == NULL) return;
        
        vector<TreeNode*> nodes;
        preOrder(root, nodes);
        
        for (int i = 0; i + 1 < nodes.size(); i++) {
            nodes[i]->left = NULL;
            nodes[i]->right = nodes[i + 1];
        }
        nodes.back()->left = NULL;
        nodes.back()->right = NULL;
    }
};