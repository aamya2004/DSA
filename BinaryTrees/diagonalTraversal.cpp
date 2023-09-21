vector<int> diagonal(Node *root)
{
   vector<int> ans;
   queue<Node*> q;
   if(root==NULL){
       return ans;
   }
   q.push(root);
   
   while(!q.empty()){
       Node* curr = q.front();
       q.pop();
       
       while(curr!=NULL){
           ans.push_back(curr->data);
           if(curr->left){
               q.push(curr->left);
           }
           curr= curr->right;
       }
   }
   return ans;
}