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
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode*curr=head;
        vector<int>ans;
        while(curr){
            ans.push_back(curr->val);
            curr=curr->next;
        }
        stack<int>st;
        int sz=ans.size();
        vector<int>res(sz);
        cout<<ans.size();
        for(int i=0;i<ans.size();i++)
        {   
            while(!st.empty() && ans[st.top()]<ans[i]){
                res[st.top()]=ans[i];
                st.pop();
            }
            st.push(i);
        }
        cout<<res.size();
        for(int i=0;i<res.size();i++){
            if(res[i]==0)
            res[i]=0;
        }
        return res;
    }
};