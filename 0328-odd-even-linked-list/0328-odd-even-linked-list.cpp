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
        if(head==NULL) return NULL;
        ListNode*o=head;
        ListNode*e=head->next;
        ListNode*ans=e;
        ListNode*top=o;
        bool flag=true;
        while(o->next && e->next){
            o->next=e->next; //making connections
            e->next=o->next->next;
            //moving ahead
            o=o->next;
            e=e->next;
        }
        o->next=ans;
        return top;
    }
};