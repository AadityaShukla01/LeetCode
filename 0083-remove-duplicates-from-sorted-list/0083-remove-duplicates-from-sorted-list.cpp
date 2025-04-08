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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return nullptr;
        ListNode* curr = head;
        ListNode* temp = new ListNode(-1);
        ListNode* dummy = temp;

        while(curr)
        {
            while(curr->next && curr->val == curr->next->val)
            {
                curr = curr->next;
            }
            temp->next = curr;
            temp = temp->next;
            curr = curr->next;
        }
        return dummy->next;
    }
};