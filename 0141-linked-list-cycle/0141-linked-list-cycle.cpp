/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slo = head;
        ListNode* fast = head;

        while(fast && fast->next){
            slo = slo->next;
            fast = fast->next->next;

            if(slo == fast) return true;
        }
        return false;
    }
};