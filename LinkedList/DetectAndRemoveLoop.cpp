/*************************************************
    
    class Node {
        public :

        int data;
        Node *next;

        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
    };

*************************************************/
Node* getIntersection(Node *head){
    if(head==NULL){
        return NULL;
    }
    Node* fast= head;
    Node* slow = head;
    while(slow!=NULL && fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
        }
        slow=slow->next;
        if(slow==fast){
            return fast;
        }
    }
    return NULL;
}


Node* getStartingNode(Node *head){
    if(head==NULL){
        return NULL;
    }
    Node* fast = getIntersection(head);

    if(fast==NULL){
        return NULL;
    }

    Node* slow = head;
    while(slow!=fast){
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}

Node *removeLoop(Node *head)
{
    if(head==NULL){
        return head;
    }
    Node* start= getStartingNode(head);

    if(start==NULL){
        return head;
    }
    Node* temp = start;
    while(temp->next!=start){
        temp=temp->next;
    }
    temp->next=NULL;
    return head;
}
