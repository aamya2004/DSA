class Solution
{
    public:
    Node* reverse(Node* node){
        if(node == NULL || node -> next == NULL){
            return node;
        }
        Node* curr = node;
        Node* prev = NULL;
        Node* forward = NULL;
        
        while(curr != NULL){
            forward = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
    
    void insertAtTail(Node* &ansHead, Node* &ansTail, Node* &store){
        if(ansHead == NULL){
           ansHead = store;
           ansTail = store;
       }
       else{
           ansTail -> next = store;
           ansTail = store;
       }
    }
    
    
    Node* add(Node* first, Node* second){
        Node* ansHead = NULL;
        Node* ansTail = NULL;
        
        int sum = 0;
        int carry = 0;
        
        while(first != NULL || second != NULL || carry != 0){
            int val1 = 0;
            if(first != NULL){
                val1 = first -> data;
            }
            int val2 = 0;
            if(second != NULL){
                val2 = second -> data;
            }
            
            sum = val1 + val2 + carry;
            
            int digit = sum%10;
            Node* store = new Node(digit);
            
            insertAtTail(ansHead, ansTail, store);
            
            carry = sum/10;
            
            if(first != NULL){
                first = first -> next;
            }
            
            if(second != NULL){
                second = second -> next;
            }
            
        }
        return ansHead;
    }
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
         // code here
        first = reverse(first);
        second = reverse(second);
        
        Node* ans = add(first, second);
        ans = reverse(ans);
        return ans;
    }
};