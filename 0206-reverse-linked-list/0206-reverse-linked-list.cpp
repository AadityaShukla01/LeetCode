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
    void sol(ListNode* &head,ListNode*curr,ListNode*pre){
        //base case ///if we reach last
        if(curr==NULL){
            head=pre;
            return ;
        }
        ListNode*forw=curr->next;
        sol(head,forw,curr);
        curr->next=pre;
    }
    ListNode* reverseList(ListNode* head) {
        //iterative method
        // if(head==NULL) return head;

        ListNode*curr=head;
        ListNode*forw=NULL;
        ListNode*pre=NULL;

        // while(curr){
        //     forw=curr->next; //reversing the connection
        //     curr->next=pre;
        //     //move ahead
        //     pre=curr;
        //     curr=forw;
        // }
        // return pre;
        sol(head,curr,pre);
        return head;
    }
};