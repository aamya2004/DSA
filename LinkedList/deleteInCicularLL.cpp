/****************************************************************

    Following is the class structure of the Node class:

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

*****************************************************************/

Node* deleteNode(Node* head, int key) 
{
        if(!head) return head;
        if(head->next==head){
                if(head->data == key){
                        return NULL;
                }
                return head;
        }
        Node* prev = head;
        Node* curr = head->next;
        while(curr!=head){
                if(curr->data == key){
                        curr = curr->next;
                        prev->next = curr;
                }
                else{
                        prev = curr;
                        curr = curr->next;
                }
        }

        if(head->data == key){
                prev->next = head->next;
                head = prev->next;
        }

        return head;
}