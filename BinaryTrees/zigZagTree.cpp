    vector <int> zigZagTraversal(Node* root)
    {
    	vector<int> finalAns;
    	queue<Node*> q;
    	if(root==NULL){
    	    return finalAns;
    	}
    	q.push(root);
    	bool leftToRight = true;
    	while(!q.empty())
        {
        	int size = q.size();
            vector<int> ans(size);
            for(int i = 0; i<size; i++){
                Node* frontNode = q.front();
                q.pop();
                    
                int index = leftToRight ? i : size-i-1;
                ans[index] = frontNode->data;
                
                if(frontNode->left){
                    q.push(frontNode->left);
                }
                if(frontNode->right){
                    q.push(frontNode->right);
                }
            }
            
            leftToRight = !leftToRight;
            
            for(int i = 0; i<ans.size();i++){
                finalAns.push_back(ans[i]);
            }
        } 
        return finalAns;
    }