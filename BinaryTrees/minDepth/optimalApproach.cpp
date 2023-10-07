public:
    int minDepth(TreeNode* root) {
        
        if(root==NULL) return 0;

        int l = minDepth(root->left);
        int r = minDepth(root->right);

        return 1+(min(l,r)?min(l,r):max(l,r));

    }