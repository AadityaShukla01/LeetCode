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
    int len(ListNode*ptr){
        int count=0;
        while(ptr){
            ptr=ptr->next;
            count++;
        }
        return count;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int length=len(head); //to calculate size of Linked list
        int partSize=length/k; //length  of each part
        int plusNodes=length%k; //for extra nodes to finish at the start

        vector<ListNode*>ans;
        ListNode *curr=head;
        ListNode *pre=NULL;

        while(head){
            int eachSize=partSize;
            ans.push_back(curr);
            while(eachSize--){
                pre=curr;
                curr=curr->next;
            }
            //if because we need to run it only once
            if(plusNodes!=0 && curr){
                pre=curr;
                curr=curr->next;
                plusNodes--;
            }
            //breaking linked list into parts
            if(pre!=NULL){
                head=curr;
                pre->next=NULL;
            }
        }
        while(ans.size()!=k){
            ans.push_back(NULL);
        }
        return ans;
    }
};