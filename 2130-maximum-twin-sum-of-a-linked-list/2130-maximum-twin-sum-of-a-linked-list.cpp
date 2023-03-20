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
    ListNode *sol(ListNode*head){
        ListNode*curr=head;
        ListNode*pre=NULL;
        ListNode*future=NULL;
        while(curr){
            future=curr->next;
            curr->next=pre;
            pre=curr;
            curr=future;
        }
        return pre;
    }
public:
    int pairSum(ListNode* head) {
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast->next!=NULL and fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        slow->next=sol(slow->next);
        slow=slow->next;int sum=0;
        int maxi=0;
        while(slow!=NULL){
            sum=head->val+slow->val;
            cout<<sum<<endl;
            maxi=max(sum,maxi);
            sum=0;
            slow=slow->next;
            head=head->next;
        }
        return maxi;
    }
};