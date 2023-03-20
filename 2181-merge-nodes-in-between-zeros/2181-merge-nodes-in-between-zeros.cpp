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
    ListNode* mergeNodes(ListNode* head) {
        if(head==NULL) return NULL;

        ListNode*curr=head;
        ListNode* res=new ListNode(0);
        ListNode*q=res;
        int ans=0;
        while(curr){
            if(curr->val==0){
                res->next=new ListNode(ans);
                res=res->next;
                ans=0;
            }
            ans=ans+curr->val;
            curr=curr->next;
        }
        return q->next->next;
    }
};