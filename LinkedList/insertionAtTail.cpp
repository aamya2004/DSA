//Insert node at tail and print the linked list
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

void insertionAtTail(Node* &tail, int data){
    Node* temp = new Node(data);
    tail->next = temp;
    tail=tail->next;
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
    insertionAtTail(tail,15);
    print(head);

    return 0;
}
