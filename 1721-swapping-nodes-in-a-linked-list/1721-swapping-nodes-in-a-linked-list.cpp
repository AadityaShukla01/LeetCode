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
ListNode*sol(ListNode*head){
    ListNode*ptr=head;
    ListNode*last=NULL;
    while(ptr){
        swap(ptr->next,last);
        swap(last,ptr);
    }
    return last;
}
    ListNode* swapNodes(ListNode* head, int k) {
       ListNode*ptr=head;
       ListNode*ans=head;
       ListNode*res=head;
       int i=0;
       while(ans){
           i++;
           ans=ans->next;
       }
       int q=i-k;
       while(k>1){
           ptr=ptr->next;
           k--;
       }
       
       while(q--){
           res=res->next;
       }
        swap(ptr->val,res->val);
       return head;
    }
};