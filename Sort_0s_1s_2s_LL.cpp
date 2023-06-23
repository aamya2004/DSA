/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/
void insert(Node* &head,Node* &temp){
    head->next=temp;
    head=temp;
} 


Node* sortList(Node *head){
    Node* zeroHead = new Node(-1);
    Node* oneHead = new Node(-1);
    Node* twoHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneTail = oneHead;
    Node* twoTail = twoHead;

    Node* temp = head;
    while(temp!=NULL){
        if(temp->data==0){
            insert(zeroTail,temp);
        }
        else if(temp->data==1){
            insert(oneTail,temp);
        }
        else{
            insert(twoTail,temp);
        }
        temp=temp->next;
    }

    if(oneHead->next!=NULL){
        zeroTail->next = oneHead->next;
    } else {
      zeroTail->next = twoHead->next;
    }
    oneTail->next = twoHead->next;
    twoTail->next = NULL;
    head = zeroHead->next;
    delete oneHead;
    delete twoHead;
    delete zeroHead;

    return head;

}
