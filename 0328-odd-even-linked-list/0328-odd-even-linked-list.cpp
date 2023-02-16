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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL)
        return head;

        ListNode*o=head;
        ListNode*e=head->next;
        ListNode*ans=new ListNode(0);
        ans->next=e;
        ListNode*rest=o;
        bool res=false;
        head=head->next;
        while(o && e && e->next && o->next){
            o->next=o->next->next;
            o=o->next;

            e->next=e->next->next;
            e=e->next;
        }
        o->next=ans->next;
        return rest;
    }
};