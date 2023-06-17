//Insertion and deletion in a singly linked list
#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node *next;
    
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
    
    ~Node(){
        int value = this->data;
        if(this-> next != NULL){
            delete next;
            this->next=NULL;
        }
    }
};

void insertionAtHead(Node* &head, int data){
    Node* temp = new Node(data);
    temp->next = head;
    head=temp;
}

void insertionAtTail(Node* &tail, int data){
    Node* temp = new Node(data);
    tail->next = temp;
    tail=tail->next;
}


void insertionAtAnyPosition(Node* &tail,Node* &head, int data , int position){
    //inserting at head
    if(position==1){
        insertionAtHead(head,data);
        return;
    }
    
    Node* temp=head;
    int cnt = 1;
    while(cnt<position-1){
        temp=temp->next;
        cnt++;
    }
    
    if(temp->next==NULL){
        insertionAtTail(tail,data);
        return;
        
    }
    Node* nodeToInsert = new Node(data);
    nodeToInsert->next=temp->next;
    temp->next = nodeToInsert;
    
}

void deletionOfNode(Node* &head,int position){
    if(position==1){
        Node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
    else{
        Node* curr=head;
        Node* prev=NULL;
        int cnt=1;
        while(cnt<=position){
            prev=curr;
            curr=curr->next;
            cnt++;
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
        
    }
}

void print(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp= temp->next;
    }
}

int main() {
    Node *node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    print(head);
    cout<<endl;
    insertionAtTail(tail,20);
    print(head);
    cout<<endl;
    insertionAtAnyPosition(tail,head,30,3);
    insertionAtAnyPosition(tail,head,40,1);
    print(head);
    cout<<endl;
    deletionOfNode(head,2);
    print(head);
    return 0;
}
