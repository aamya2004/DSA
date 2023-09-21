/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    int findLength(ListNode* head){
        ListNode* curr = head;
        int cnt = 0;
        while(curr!=NULL){
            curr=curr->next;
            cnt++;
        }
        return cnt;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans(k,NULL);
        ListNode* curr = head;
        ListNode* prev = NULL;
        int n = findLength(head);
        int rem = n%k;
        int noOfElements = n/k;
        for(int i = 0 ;curr && i<k ; i++){
            ans[i] = curr;
            for(int j = 0; j<noOfElements ; j++){
                prev=curr;
                curr= curr->next;
            }
            if(rem>0){
                prev=curr;
                curr=curr->next;
                rem--;
            }
            prev->next=NULL;
        }
        return ans;

    }
};