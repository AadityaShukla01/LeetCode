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
class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        //merge sort -> divide - merge+sort
        if(head==NULL || head->next==NULL) return head;

        ListNode *temp=head;
        ListNode *slo=head;
        ListNode *fast=head;
        //finding mid
        while(fast && fast->next){
            temp=slo;
            slo=slo->next;
            fast=fast->next->next;
        }
        //break'em into parts
        temp->next=NULL;

        //divide
        ListNode *p=sortList(head);
        ListNode *q=sortList(slo);

        //conquer//merge'em
        return merge(p,q);
    }

    ListNode *merge(ListNode *p, ListNode *q)
    {
        if(p==NULL || q==NULL) return NULL;
        ListNode *curr=new ListNode(0);
        ListNode *dummy=curr;
        while(p && q){
            if(p->val <q->val){
                curr->next=p;
                p=p->next;
            }
            else{
                curr->next=q;
                q=q->next;
            }
            curr=curr->next;
        }
        if (p != NULL)
        {
            curr->next = p;
            p = p->next;
        }
        if (q != NULL)
        {
            curr->next = q;
            q = q->next;
        }
        return dummy->next;
    }
};