#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
    
    Node(int d){
        this->data = d;
        this->left=NULL;
        this->right= NULL;
    }
};

Node* buildTree(Node* root){

    cout<<"enter the data: """<<endl;
    int data;
    cin>>data;
    root = new Node(data); //created root node
    if(data == -1){
        return NULL;
    }
    //put in left
    cout<<"ENter for left : "<<endl;
    root->left = buildTree(root->left);
    cout<<"enter for right: "<<endl;
    root->right = buildTree(root->right);
    return root;

}

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(temp==NULL){
            //last level completely traversed
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
        cout<<temp->data<<" ";

        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
        }
    }

}

void inOrder(Node* root){
    if(root == NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void preOrder(Node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node* root){
    if(root == NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

void buildFromLevelOrder(Node* &root){
    queue<Node*> q;
    cout<<"Enter data for root "<<endl;
    int data;
    cin>>data;
    root = new Node(data);
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        cout<<"Enter data for left node of "<<root->data<<endl;
        int leftData;
        cin>>leftData;

        if(leftData!=-1){
            temp->left= new Node(leftData);
            q.push(temp->left);
        }

        cout<<"Enter data for right node of "<<root->data<<endl;
        int rightData;
        cin>>rightData;

        if(rightData!=-1){
            temp->right= new Node(rightData);
            q.push(temp->right);
        }
    }

}

int main()
{
    Node* root = NULL;
    // root = buildTree(root);
    buildFromLevelOrder(root);
    levelOrderTraversal(root);

    // cout<<"inOrder Traversal is: "<<endl;
    // inOrder(root);
    // cout<<endl;
    // cout<<"preOrder Traversal is: "<<endl;
    // preOrder(root);
    // cout<<endl;
    // cout<<"postOrder Traversal is: "<<endl;
    // postOrder(root);
    // cout<<endl;
    return 0;
}