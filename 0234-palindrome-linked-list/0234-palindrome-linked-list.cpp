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
ListNode* sol(ListNode*head){
    ListNode*curr=head;
    ListNode*prev=NULL;
    ListNode*aage=NULL;
    while(curr){
        aage=curr->next;
        curr->next=prev;
        prev=curr;
        curr=aage;
    }
    return prev;
}
    bool isPalindrome(ListNode* head) {
        ListNode*curr=head;
        ListNode*slow=head;
        ListNode*fast=head;

        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode*ans=sol(slow);
        while(curr && ans){
            if(curr->val!=ans->val) return false;
            curr=curr->next;
            ans=ans->next;
        }   
        return true;
    }   
};