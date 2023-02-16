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

        // if lsit contains zero or 1 node
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *temp = head; // using it to store the node where we will partiotn
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next)
        {
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        // into 2 parts
        temp->next = NULL;

        // call sorting function on left half
        ListNode *l1 = sortList(head);

        // ryt part breaking
        ListNode *l2 = sortList(slow);

        // merge sorted parts
        return merge(l1, l2);
    }

    ListNode *merge(ListNode *l1, ListNode *l2)
    {
        // creating node to form new list
        ListNode *curr = new ListNode(0);
        ListNode *temp = curr;

        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                curr->next = l1;
                l1 = l1->next;
            }
            else
            {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        if (l1 != NULL)
        {
            curr->next = l1;
            l1 = l1->next;
        }

        if (l2 != NULL)
        {
            curr->next = l2;
            l2 = l2->next;
        }

        return temp->next;
    }
};