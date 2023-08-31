#include <bits/stdc++.h> 
/********************************
    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

********************************/

void splitCircularList(Node *head)
{
    Node* slow = head;
    Node* fast = head;
    if(head==NULL || head->next==head){
        return;
    }
    while(fast->next!=head && fast->next->next!=head){
        slow=slow->next;
        fast=fast->next->next;

    }
    fast=fast->next;
    fast->next=slow->next;
    slow->next=head;


}
