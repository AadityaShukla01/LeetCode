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
        ListNode*ptr=head;
        ListNode*last=NULL;
        while(ptr!=NULL){
            swap(ptr->next,last);
            swap(last,ptr);
        }
        return last;
    }
    ListNode* removeNodes(ListNode* head) {
        head=sol(head);//reverse the linked list
        ListNode*ptr=head;
        while(ptr and ptr->next){//traverse from last and if we find any samller element remove it from the linked list
            if(ptr->val > ptr->next->val){
                ptr->next=ptr->next->next;
            }
            else
            ptr=ptr->next;
        }
        
        return sol(head);
    }
};