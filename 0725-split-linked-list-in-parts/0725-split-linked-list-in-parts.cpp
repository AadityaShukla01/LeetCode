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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = 0;
        ListNode* curr = head;
        while(curr){
            curr = curr->next;
            len++;
        }

        int rem = len % k;

        curr = head;
        int mnSize = len/k;
        int sz = mnSize;
        vector<ListNode*>ans(k);
        int i = 0;
        while(curr){
            ListNode* temp = curr;
            ListNode* dummy = curr;
            ListNode* pre = curr;
            while(sz > 0){
                pre = temp;
                temp = temp->next;
                sz--;
            }
            if(rem > 0){
                pre = temp;
                temp = temp->next;
            }
            rem--;
            if(temp){
                curr = temp;
                pre->next = NULL;
                ans[i] = (dummy);
            }
            else{
                ans[i] = dummy;
                break;
            }
            i++;
            sz = mnSize;
        }
        return ans;
    }
};