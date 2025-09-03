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
    ListNode* merge(ListNode* p, ListNode* q) {
        if (!p)
            return q;
        if (!q)
            return p;

        ListNode* temp = new ListNode(-1);
        ListNode* dummy = temp;

        while (p && q) {
            if (p->val < q->val) {
                temp->next = p;
                p = p->next;
            } else {
                temp->next = q;
                q = q->next;
            }
            temp = temp->next;
        }
        if (q)
            temp->next = q;
        if (p)
            temp->next = p;

        return dummy->next;
    }
    ListNode* sol(int l, int r, vector<ListNode*> lists) {
        if (l >= r)
            return lists[l];

        int mi = l + (r - l) / 2;

        ListNode* left = sol(l, mi, lists);
        ListNode* ryt = sol(mi + 1, r, lists);

        return merge(left, ryt);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if (n == 0)
            return NULL;
        return sol(0, n - 1, lists);
    }
};