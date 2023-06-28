//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    private:
    
    void insert(struct Node* &ansKaHead, struct Node* &ansKaTail, int nodeDalnaHai){
        Node* temp = new Node(nodeDalnaHai);
        if(ansKaHead == NULL){
            ansKaHead = temp;
            ansKaTail = temp;
            return;
        }
        else{
            ansKaTail->next = temp;
            ansKaTail = temp;
        }
    }
    
    
    Node* LLsum(struct Node* first, struct Node* second){
        Node* head1 = first;
        Node* head2 = second;
        Node* ansKahead = NULL;
        Node* ansKaTail = NULL;
        int carry = 0;
        
        while(head1!=NULL || head2!=NULL || carry!=0){
            int val1=0;
            int val2 = 0;
            if(head1!=NULL){
                val1 = head1->data;
            }
            if(head2!=NULL){
                val2= head2->data;
            }
            int sum = val1 + val2 + carry;
            int digit = sum%10;
            
            insert(ansKahead,ansKaTail,digit);
            carry = sum/10;
            if(head1!=NULL){
                head1=head1->next;
            }
            if(head2!=NULL){
                head2= head2->next;
            }
        }
        return ansKahead;
    }
 
    Node* reverse(struct Node* LLHead){
        Node* curr = LLHead;
        Node* next = NULL;
        Node* prev = NULL;
        while(curr!=NULL){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        Node* ifirst = reverse(first);
        Node* isecond = reverse(second);
        
        Node* sum = LLsum(ifirst,isecond);
        
        Node* ans = reverse(sum);
        
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends
