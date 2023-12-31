//   Given the root of a binary search tree (BST) with duplicates, return all the mode(s) (i.e., the most frequently occurred element) in it.

// If the tree has more than one mode, return them in any order.

// Assume a BST is defined as follows:

// The left subtree of a node contains only nodes with keys less than or equal to the node's key.
// The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
// Both the left and right subtrees must also be binary search trees.
 

// Example 1:


// Input: root = [1,null,2,2]
// Output: [2]
// Example 2:

// Input: root = [0]
// Output: [0]
 

// Constraints:

// The number of nodes in the tree is in the range [1, 104].
// -105 <= Node.val <= 105  
    
    
    
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