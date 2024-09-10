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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* curr = head;

        while(curr && curr->next)
        {
            int v1 = curr->val;
            int v2 = curr->next->val;

            ListNode * newNode = new ListNode(__gcd(v1, v2));

            ListNode* nxt = curr->next;

            curr->next = newNode;
            newNode->next = nxt;
            curr = curr->next->next;
        }
        return head;
    }
};