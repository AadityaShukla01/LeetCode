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
        ListNode* dummy =new ListNode(0);
        dummy->next=head;
        ListNode*ptr=dummy;
        int sum=0;
        unordered_map<int,ListNode*>map;

        while(ptr){
            sum=sum+ptr->val;
            //if sum exists we found zero subaaray
            if(map.count(sum)){
                ptr=map[sum]->next;
                int p=ptr->val+sum;
                //performing deletions
                while(p!=sum){
                    map.erase(p); //you must delete values from map too for firther deletions if possible
                    ptr=ptr->next;
                    p+=ptr->val;
                }
                map[sum]->next=ptr->next;
            }
            //if value seen first time insert it into map
            else{
                map[sum]=ptr;
            }
            ptr=ptr->next;
        }
        return dummy->next;
    }
};