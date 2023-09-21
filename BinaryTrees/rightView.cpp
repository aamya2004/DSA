    vector<int> rightView(Node *root)
    {
        vector<int> ans;
        map<int,int> nodes;
        queue<pair<Node*,int>>q;
        if(root==NULL){
            return ans;
        }
        q.push(make_pair(root,0));
        
        while(!q.empty()){
            pair<Node*,int> temp = q.front();
            Node* frontNode = temp.first;
            int lvl = temp.second;
            q.pop();
            
            //only line changed
            nodes[lvl] = frontNode->data;
            
            
            if(frontNode->left){
                q.push(make_pair(frontNode->left,lvl+1));
            }
            if(frontNode->right){
                q.push(make_pair(frontNode->right,lvl+1));
            }
            
            
        }
        for(auto i : nodes){
                
            ans.push_back(i.second);
            }
        
        return ans;
    }