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
        if(!head || !head->next) return head;
        ListNode* curr = head;
        while(curr)
        {
            if(curr->next && curr->next->val == curr->val)
            {
                ListNode* temp = curr;
                while(temp->next && temp->next->val == temp->val)
                {
                    temp = temp->next;
                }

                curr->next = temp->next;
                curr = curr->next;
            }
            else curr = curr->next;
        }

        return head;
    }
};