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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *curr = list1;
        ListNode *temp = list1;
        while(a > 1){
            curr = curr->next;
            a--;
        }
        // curr = curr->next;
        while(b--){
            temp = temp->next;
        }
        temp = temp->next;
        while(list2){
            curr->next=list2;
            list2=list2->next;
            curr= curr->next;
        }
        // curr->next = list2;
        curr->next = temp;
        return list1;
    }
};