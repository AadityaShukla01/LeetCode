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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* s = head;
        ListNode* f = head;
        if(!head || head->next == NULL) return NULL;
        while(n--) 
        {
            f = f->next;
        }
        if(!f) return head->next;
        while(f && f->next)
        {
            s = s->next;
            f = f->next;
        }

        s->next = s->next->next;
        return head;
    }
};