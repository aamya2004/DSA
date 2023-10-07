    Node* createMapping(Node* root, int target, map<Node*,Node*> &nodeToParent){
        Node* res = NULL;
        //mapping
        queue<Node*> q;
        q.push(root);
        nodeToParent[root] = NULL;
        while(!q.empty()){
            Node* front = q.front();
            q.pop();
            
            if(front->data == target){
                res = front;
            }
            if(front->left){
                nodeToParent[front->left] = front; //creating mapping of parent node
                q.push(front->left);  //storing left and right nodes in queue if they exist
            }
            if(front->right){
                nodeToParent[front->right] = front;
                q.push(front->right);
            }
        }
        return res;
    }
    
    int burnTree(Node* root, map<Node*,Node*> &nodeToParent){
        //creating a visited array
        map<Node*,bool> visited;
        queue<Node*> q;
        
        q.push(root);
        visited[root] = true;
        
        int ans = 0;
        
        while(!q.empty()){
            bool flag = 0;
            int size = q.size();
            for(int i = 0; i<size; i++){
                //processing neighbouring node
                Node* front = q.front();
                q.pop();
                
                //left right ya parent
                if(front->left && !visited[front->left]){
                    flag = 1;
                    q.push(front->left);
                    visited[front->left] = 1;
                }
                if(front->right && !visited[front->right]){
                    flag =1;
                    q.push(front->right);
                    visited[front->right] = 1;
                }
                if(nodeToParent[front] && !visited[nodeToParent[front]]){
                    flag = 1;
                    q.push(nodeToParent[front]);
                    visited[nodeToParent[front]] = 1;
                }
                
            }
            if(flag==1){
                ans++;
            }
        }
        return ans;
    }
    
    int minTime(Node* root, int target) 
    {
        map<Node*,Node*> nodeToParent;
        Node* targetNode = createMapping(root,target,nodeToParent);
        int ans =  burnTree(targetNode, nodeToParent);
        return ans;
    }