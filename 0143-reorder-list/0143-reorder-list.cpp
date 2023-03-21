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
        ListNode*q=ptr;
        ListNode*last=NULL;
        while(q){
            swap(q->next,last);
            swap(last,q);
        }
        return  last;
    }
    void reorderList(ListNode* head) {
        ListNode *slo=head;
        ListNode *fast=head;
        ListNode *curr=head;
        ListNode *temp=new ListNode(0);
        ListNode *dummy=temp;
        ListNode *breaker;
        while(fast && fast->next){  
            breaker=slo;
            slo=slo->next;
            fast=fast->next->next;
        }
        // breaker->next=NULL;
        ListNode *newNode=sol(slo);
        bool flag=false;
        while( newNode && curr){
            if(!flag){
                temp->next=curr;
                curr=curr->next;
            }
            else{
                temp->next=newNode;
                newNode=newNode->next;
            }
            flag=!flag;
            temp=temp->next;
        }
        head=dummy->next;
        // return dummy->next;
    }
};