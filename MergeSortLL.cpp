/********************************************************************

    Following is the representation of the Singly Linked List Node:

    class node{
        public:
            int data;
            node * next;
            node(int data){
                this->data=data;
                this->next=NULL;
            }
    };
    
********************************************************************/

node* findMid(node* head){
    node* slow = head;
    node* fast = head->next;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast -> next ->next;
    }
    return slow;
}

node* merge(node* leftVali, node* rightVali){
    if(leftVali == NULL){
        return rightVali;
    }
    if(rightVali == NULL){
        return leftVali;
    }
    node* ans = new node(-1);
    node* temp = ans;

    while(leftVali!=NULL && rightVali!=NULL){
        if(leftVali->data < rightVali->data){
            temp -> next = leftVali;
            temp = leftVali;
            leftVali = leftVali -> next;
        }
        else{
            temp -> next = rightVali;
            temp = rightVali;
            rightVali = rightVali -> next;
        }
    }

    //bachi hui add krni hai
    while(leftVali!=NULL){
            temp -> next = leftVali;
            temp = leftVali;
            leftVali = leftVali -> next;       
    }
    while(rightVali!=NULL){
            temp -> next = rightVali;
            temp = rightVali;
            rightVali = rightVali -> next;       
    }
    ans = ans->next;
    return ans;
}

node* mergeSort(node *head) {
    if(head==NULL || head->next == NULL){
        return head;
    }
    //finding mid
    node* mid = findMid(head);
    //making two separate portions
    node* leftKaHead = head;
    node* rightKaHead = mid->next;
    mid->next = NULL;

    //recursive calls for sorting 
    leftKaHead = mergeSort(leftKaHead);
    rightKaHead = mergeSort(rightKaHead);
    node* resultKaHead = merge(leftKaHead,rightKaHead);
    return resultKaHead;
 
}
