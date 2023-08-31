/****************************************************************

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

*****************************************************************/

Node* findIntersection(Node *firstHead, Node *secondHead)
{
    Node* a = firstHead;
    Node* b = secondHead;
    Node * ans = NULL;
    while (a != b) {
        if(a==NULL){
            a = secondHead;
        }
        else{
            a=a->next;
        }

        if(b==NULL){
            b=firstHead;
        }
        else{
            b=b->next;
        }
    }

    return a;

}
