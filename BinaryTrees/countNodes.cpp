class Solution {
public:
    int countNodes(TreeNode* root) {
        int i;
        if (root == NULL)
            return 0;
        i = 1 + countNodes(root->left) + countNodes(root->right);
        return i;
    }
};