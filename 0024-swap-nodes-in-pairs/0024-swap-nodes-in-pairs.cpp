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
    ListNode* swapPairs(ListNode* head) {
        ListNode*curr=head;
        if(curr==NULL || curr->next==NULL)
            return curr;
        ListNode*res=head->next;

        while(res->next && curr->next && curr->next->next && res->next->next){
            swap(curr->val,res->val);
            curr=curr->next->next;
            res=res->next->next;
        }
        
        swap(curr->val,res->val);
        cout<<curr->val<<endl;
        cout<<res->val<<endl;
        return head;
    }
};