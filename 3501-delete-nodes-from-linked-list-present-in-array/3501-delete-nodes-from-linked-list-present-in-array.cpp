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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int>set;
        for(auto el: nums) set.insert(el);


        while(head && set.find(head->val) != set.end()){
            head = head->next;
        }

        if(!head) return NULL;
        ListNode* curr = head;

        while(curr){
            ListNode* temp = curr->next;

            while(temp && set.find(temp->val) != set.end()){
                temp = temp->next;
            }

            curr->next = temp;
            curr = curr->next;
        }
        return head;
    }
};