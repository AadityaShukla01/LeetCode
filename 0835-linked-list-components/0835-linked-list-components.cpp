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
    int numComponents(ListNode* head, vector<int>& nums) {
        int n = nums.size();
        set<int>set;
        for(auto el: nums) set.insert(el);
        bool f = false;
        ListNode* curr = head;
        int cnt = 0;
        while(curr)
        {
            int curr_num = curr->val;
            
            if(set.find(curr->val) != set.end())
            {
                cnt++;
                while(curr && set.find(curr->val) != set.end())
                    curr = curr->next;
            }
            else curr = curr->next;
        }
        return cnt;
    }
};