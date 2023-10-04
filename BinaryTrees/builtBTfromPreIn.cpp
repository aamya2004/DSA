    void createMapping(int in[],map<int,int> &indexMapping,int n){
        for(int i=0;i<n;i++){
            indexMapping[in[i]]=i;
        }
    }
    
    Node* solve(int in[],int pre[],int &preOrderIndex,int start,int end,map<int,int> &indexMapping,int n){
        if(preOrderIndex>=n || start>end){
            return NULL;
        }
        
        int element = pre[preOrderIndex++];
        Node* root = new Node(element);
        int position = indexMapping[element];
        
        root->left = solve(in,pre,preOrderIndex,start,position-1,indexMapping,n);
        root->right = solve(in,pre,preOrderIndex,position+1,end,indexMapping,n);
        
        return root;

    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        int preOrderIndex = 0;
        map<int,int> indexMapping;
        createMapping(in,indexMapping,n);
        Node* ans = solve(in,pre,preOrderIndex,0,n-1,indexMapping,n);
        return ans;
    }