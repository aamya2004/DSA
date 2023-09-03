Node* reverseDLL(Node * head)
{
    Node* curr = head;
    Node* forward = curr->next;
    while(forward!=NULL){
        curr->next = curr->prev;
        curr->prev = forward;
        curr = forward;
        forward = forward ->next;
    }
    curr->next = curr->prev;
    curr->prev =NULL;
    return curr;
}