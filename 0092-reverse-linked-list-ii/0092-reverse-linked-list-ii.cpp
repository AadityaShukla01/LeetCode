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
      ListNode*sol(ListNode*ptr){
          ListNode*curr=ptr;
          ListNode*last=NULL;
          while(curr){
              swap(curr->next,last);
              swap(curr,last);
          }
          return last;
      }
      ListNode* reverseBetween(ListNode* head, int left, int right) {
       ListNode*ans=new ListNode(0);
       ans->next=head;
       ListNode*res=ans->next;
       ListNode*pre=ans;
        for(int i=0;i<left-1;i++){
            pre=pre->next;
        }
        ListNode*curr=pre->next;
        for(int i=0;i<right-left;i++){
            ListNode*fora=curr->next;
            curr->next=fora->next;
            fora->next=pre->next;
            pre->next=fora;
        }
        return ans->next;//dummy list pre==duumy because we also need to handle the case qhen left=1 at that time prev=dummy curr=left and fora=curr->next
}   
};


