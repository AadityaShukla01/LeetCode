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
        ListNode*ans=head;
        // ListNode*ans=sol(head);
        while(ans && ans->next){
            curr=curr->next;
            ans=ans->next->next;
        }
        ListNode*news=sol(curr);
        while(news){
            if(news->val!=head->val)
            return false;

            news=news->next;
            head=head->next;
        }
        return true;
    }
};