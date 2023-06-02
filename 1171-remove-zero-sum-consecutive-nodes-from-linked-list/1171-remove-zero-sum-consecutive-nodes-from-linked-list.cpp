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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* curr = head;
        int prefixSum = 0;
        unordered_map<int,ListNode*>map;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        map[0] = dummy;

        while(head){
            prefixSum += head->val;
            if(map.find(prefixSum) != map.end()){

                ListNode* temp = map[prefixSum];
                ListNode* start = temp;
                int sum = prefixSum;

                while(temp != head){
                    temp = temp->next;
                    sum += temp->val;

                    if(temp != head)
                        map.erase(sum);
                }
                start->next = head->next;
            }
            else{
                map[prefixSum] = head;
            }
            head = head->next;
        }
        return dummy->next;
    }
};