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
    ListNode* reverseLL(ListNode* head){
        ListNode* pre = NULL;
        ListNode* forw = NULL;
        ListNode* curr = head;
        while(curr){
            forw = curr->next;
            curr->next = pre;
            pre = curr;
            curr = forw;
        }
        return pre;
    }
    void reorderList(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* secondHalf = reverseLL(slow);
        ListNode* nn = secondHalf;
        bool rev = false;
        ListNode* curr = head;
        ListNode* temp = new ListNode(-1);
        ListNode* dummy = temp;
        while(curr && nn){
            if(!rev){
                temp->next = curr;
                curr = curr->next;
            }
            else{
                temp->next = nn;
                nn = nn->next;
            }
            temp = temp->next;
            rev = !rev;
        }
        if(curr){
            temp->next = curr;
        }
        temp->next = NULL;
        return;
    }
};