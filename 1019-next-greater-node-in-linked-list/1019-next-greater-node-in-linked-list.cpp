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
    ListNode *reverses(ListNode *head){
        if(head == NULL)
            return NULL;
        ListNode *pre = NULL;
        ListNode *forw = NULL;

        while(head){
            forw = head->next;
            head->next = pre;
            pre = head;
            head = forw;
        }
        return pre;
    }
    vector<int> nextLargerNodes(ListNode* head) {
        stack<int>st;
        ListNode *ptr = reverses(head);
        vector<int>res;
        // while(ptr){
        //     res.push_back(ptr->val);
        //     ptr = ptr->next;
        // }
        vector<int>ans;
        while(ptr){
            if(st.empty() == true){
                ans.push_back(0);
            }
            else if(st.empty() == false && st.top() > ptr->val){
                ans.push_back(st.top());
            }
            else if(st.empty() == false && st.top() <= ptr->val){
                while(st.empty() == false && st.top() <= ptr->val){
                    st.pop();
                }
                if(st.size() == 0)
                    ans.push_back(0);
                else
                    ans.push_back(st.top());
            }
            st.push(ptr->val);
            ptr = ptr->next;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};