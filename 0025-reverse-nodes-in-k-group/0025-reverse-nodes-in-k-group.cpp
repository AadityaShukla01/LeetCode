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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode*preCal=head;
        //so that only k nodes get reverse and extran not
        for(int i=0;i<k;i++){
            if(preCal==NULL)
            return head;
            preCal=preCal->next;
        }
     ListNode*curr=head;
     ListNode*pre=NULL;
     ListNode*forw=NULL;
     int count=0;
     ListNode*ans=new ListNode(0);
     while(count<k){
         forw=curr->next;
         curr->next=pre;
         pre=curr;
         curr=forw;
         count++;
     }   
    
     head->next=reverseKGroup(forw,k);
     
     return pre;
    }
};