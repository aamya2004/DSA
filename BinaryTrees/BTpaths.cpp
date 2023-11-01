    void solve(TreeNode* root, vector<string> &ans,string path){
        path+=(path.size() ? "->" : "")+to_string(root->val);
        if(!root->left && !root->right){
            ans.push_back(path);
        }
        if(root->left) solve(root->left,ans,path);
        if(root->right) solve(root->right,ans,path);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string path ="";
        solve(root,ans,path);
        return ans;
    }