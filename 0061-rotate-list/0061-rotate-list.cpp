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
    ListNode* rotateRight(ListNode* head, int k) {
        int len = 0;
        ListNode* curr = head;
        while(curr)
        {
            len++;
            curr = curr->next;
        }
        ListNode* s = head, *f = head;
        if(!k || !head || !head->next) return head;
        
        k = k % len;
        if(!k) return head;
        while(k--) f = f->next;

        while(f && f->next)
        {
            s = s->next;
            f = f->next;
        }

        ListNode* nxt = s->next;
        s->next = NULL;

        ListNode* temp = nxt;
        while(temp->next) temp = temp->next;

        temp->next = head;
        return nxt;
    }
};