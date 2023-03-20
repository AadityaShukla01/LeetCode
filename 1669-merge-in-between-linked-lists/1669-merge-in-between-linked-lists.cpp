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
        ListNode*curr=list1;
        int x=b-a;
        ListNode*curr2=list2;
        int i=1;
        while(curr){
            if(i==a){
                break;
            }
            curr=curr->next;
            i++;
        }
        ListNode*ptr;
        ptr=curr->next;
        while(x--){
            ptr=ptr->next;
        }
        curr->next=curr2;
        while(curr2->next) curr2=curr2->next;
        curr2->next=ptr->next;
        return list1;
    }
};