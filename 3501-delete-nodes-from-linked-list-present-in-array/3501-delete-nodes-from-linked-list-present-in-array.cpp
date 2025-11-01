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
        ListNode* temp = new ListNode(-1);
        ListNode* dummy = temp;
        ListNode* curr =head;
        unordered_set<int>set;
        for(auto el: nums) set.insert(el);

        while(curr){
            if(set.find(curr->val) == set.end()){
                temp->next = curr;
                temp = temp->next;
            }
            curr = curr->next;
        }
        temp->next = NULL;
        return dummy->next;
    }
};