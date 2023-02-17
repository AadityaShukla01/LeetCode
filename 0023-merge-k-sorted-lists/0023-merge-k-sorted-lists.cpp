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
    struct compare
    {
        bool operator()(const ListNode *l, const ListNode *r)
        {
            return l->val > r->val;
        }
    };
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *dummy = new ListNode(-1);
        ListNode *tail = dummy;

        priority_queue<ListNode *, vector<ListNode *>, compare> q;

        // inserrt head of list into priority queue
        for (int i = 0; i < lists.size(); i++)
        {
            if (lists[i] != NULL)
                q.push(lists[i]);
        }
        //keep  untile queue becomes empty!
        while (q.size())
        {
            ListNode *temp = q.top();
            q.pop();
            tail->next = temp;
            tail = temp;
            if (temp->next)
                q.push(temp->next);
        }
        return dummy->next;
    }
};