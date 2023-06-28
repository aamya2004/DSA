/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */
Node* merge(Node* leftVali, Node* rightVali){
    if(leftVali == NULL){
        return rightVali;
    }
    if(rightVali == NULL){
        return leftVali;
    }
    Node* temp = new Node(-1);
    Node* res = temp;

    while(leftVali!=NULL && rightVali!=NULL){
        if(leftVali->data < rightVali->data){
            temp -> child = leftVali;
            temp = temp -> child;
            leftVali = leftVali -> child;
        }
        else{
            temp -> child = rightVali;
            temp = temp->child;
            rightVali = rightVali -> child;
        }
    }

    //bachi hui add krni hai
	if(leftVali){
		temp->child=leftVali;
	}
	else{
		temp->child=rightVali;
	}

    //ans = ans->child;
    return res->child;
}

Node* flattenLinkedList(Node* head) 
{
	if(head == NULL || head->next == NULL){
		return head;
	}

	//down-> next = head -> child;
	Node* right = flattenLinkedList(head->next);
	Node* down = head;
	down->next = NULL;

	Node* resultKaHead = merge(down,right);
	return resultKaHead;

}
