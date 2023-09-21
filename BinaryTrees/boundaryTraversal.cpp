
    void leftPart(Node* &root, vector<int> &ans){
        
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right == NULL){
            return;
        }
        ans.push_back(root->data);
        if(root->left){
            leftPart(root->left,ans);
        }
        else{
            leftPart(root->right,ans);
        }
    }
    
    void traverseLeaf(Node* &root, vector<int> &ans){
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right ==NULL){
            ans.push_back(root->data);
            return;
        }
        traverseLeaf(root->left,ans);
        traverseLeaf(root->right,ans);

        
    }
    
    void traverseRight(Node* &root, vector<int> &ans){
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right == NULL){
            return;
        }
        if(root->right) traverseRight(root->right,ans);
        else traverseRight(root->left,ans);
        //wapas aagye niche se upar
        ans.push_back(root->data);
    }

    vector <int> boundary(Node *root)
    {
        vector<int> ans;
        if(root == NULL){
            return ans;
        }
        ans.push_back(root->data);
        leftPart(root->left,ans);
        
        //left sub tree //leaf traversal
        traverseLeaf(root->left,ans);
        //right sub tree
        traverseLeaf(root->right,ans);
        
        //right part traversal
        traverseRight(root->right,ans);
        return ans;
    }