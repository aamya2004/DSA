    int minDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        if(!root->left && !root->right){
            return 1;
        }
        if(!root->left){
            return minDepth(root->right)+1;
        }
        if(!root->right){
            return minDepth(root->left)+1;
        }
        int leftAns = minDepth(root->left);
        int rightAns = minDepth(root->right);

        int ans = min(leftAns,rightAns)+1;
        return ans;
    }