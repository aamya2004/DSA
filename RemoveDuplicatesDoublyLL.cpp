/**
 * Definition of doubly linked list:
 * class Node {
 * public:
 *      int data;
 *      Node *prev;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next, Node *prev) {
 *          this->data = data;
 *          this->prev = prev;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node * removeDuplicates(Node *head)
{
    Node* curr = head->next;
    Node* prev = head;
    while(curr!=NULL){
        if(curr->next!=NULL && prev->data==curr->data){
            curr->prev=NULL;
            prev->next=curr->next;
            curr->next=NULL;
            //prev->next->prev=prev;
            delete(curr);
            curr=prev->next;
            curr->prev=prev;
        }
        else{
            prev=curr;
            curr=curr->next;
        }
    }
    return head;
}
