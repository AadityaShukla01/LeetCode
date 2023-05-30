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
        int x = 0;
        ListNode *curr = head;
        while(curr->next){
            curr = curr->next;
            x++;
        }
        long long sum = 0;
        while(head){
            sum += (pow(2,x))*head->val;
            x--;
            head = head->next;
        }
        return sum;
    }
};