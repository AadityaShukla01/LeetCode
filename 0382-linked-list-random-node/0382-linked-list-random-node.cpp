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
    ListNode*cal;
    int count=0;
    Solution(ListNode* head) {
        cal=head;
        ListNode*temp=cal;

        while(temp){
            temp=temp->next;
            count++;
        }
    }
    
    int getRandom() {
        int in=rand()%count;
        ListNode*curr=cal;
        for(int i=0;i<in;i++){
            curr=curr->next;
        }
        return curr->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */