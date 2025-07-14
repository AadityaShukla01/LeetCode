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
    int getDecimalValue(ListNode* head) {
        int pos = 0;
        int number = 0;

        ListNode* curr = head;
        int len = 0;

        while(curr){
            curr = curr->next;
            len++;
        }
        curr = head;
        len--;
        while(curr){
            number += curr->val * pow(2, len);
            curr = curr->next;
            len--;
        }
        return number;
    }
};