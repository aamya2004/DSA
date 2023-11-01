    void solve(TreeNode* root, vector<int> &ans){
        if(root==NULL){
            return;
        }
        ans.push_back(root->val);
        if(root->left) solve(root->left,ans);
        if(root->right) solve(root->right,ans);

    }

    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        vector<int> ans1;
        unordered_map<int, int> mp;
        solve(root,ans);
        int maxx = 0;
        for(int i = 0 ;i<ans.size() ; i++){
            mp[ans[i]]++;
            maxx = max(maxx,mp[ans[i]]);
        }
        for(auto i : mp){
            if(i.second==maxx){
                ans1.push_back(i.first);
            }
        }
        return ans1;

    }