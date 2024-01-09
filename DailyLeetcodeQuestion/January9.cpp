// 872. Leaf-Similar Trees
// Easy
// 3.7K
// 79
// Companies
// Consider all the leaves of a binary tree, from left to right order, the values of those leaves form a leaf value sequence.



// For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).

// Two binary trees are considered leaf-similar if their leaf value sequence is the same.

// Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.

 

// Example 1:


// Input: root1 = [3,5,1,6,2,9,8,null,null,7,4], root2 = [3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]
// Output: true
// Example 2:


// Input: root1 = [1,2,3], root2 = [1,3,2]
// Output: false
 

// Constraints:

// The number of nodes in each tree will be in the range [1, 200].
// Both of the given trees will have values in the range [0, 200].


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

void tree1(TreeNode* root, vector<int> &ans) {
    if (root == nullptr) {
        return;  // Add a check for null pointer
    }

    if (root->left == nullptr && root->right == nullptr) {
        ans.push_back(root->val);
        return;
    }

    tree1(root->left, ans);
    tree1(root->right, ans);
}

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> ans1;
        vector<int> ans2;
        tree1(root1,ans1);
        tree1(root2,ans2);
        if(ans1.size()!=ans2.size()){
            return false;
        }
        for(int i = 0 ; i<ans1.size() ; i++){
            if(ans1[i]!=ans2[i]){
                return false;
            }
        }

     //   cout<<"hi";
        return true;
    }
};