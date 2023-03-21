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
        unordered_map<int,bool>map;
        ListNode *curr=head;
        int i=nums.size();
        while(i--){
            map[nums[i]]=true;
        }
        curr=head;
        int maxCount=0;
        int count=0;
        while(curr){
            if(map[curr->val]){
                count++;
            }
            else{
                if(count>0) maxCount++;
                count=0;
            }
            curr=curr->next;
        }
        if(count)
            return maxCount+1;
        return maxCount;
    }
};