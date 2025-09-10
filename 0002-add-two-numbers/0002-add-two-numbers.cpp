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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p = l1;
        ListNode* q = l2;
        ListNode* temp = new ListNode(-1);
        ListNode* dummy = temp;
        int carry = 0;

        while (p || q) {
            int a = 0, b = 0;
            if (p)
                a = p->val;
            if (q)
                b = q->val;

            int sum = (a + b + carry) % 10;
            carry = (a + b + carry) / 10;
            temp->next = new ListNode(sum);
            temp = temp->next;
            if (p)
                p = p->next;
            if (q)
                q = q->next;
        }

        if (carry)
            temp->next = new ListNode(carry);

        return dummy->next;
    }
};