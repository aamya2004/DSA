//Insert node at head and print the linked list
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
};

void insertionAtHead(Node* &head, int data){
    Node* temp = new Node(data);
    temp->next = head;
    head=temp;
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
    insertionAtHead(head,20);
    print(head);

    return 0;
}
