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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode *sol(ListNode *head, ListNode *tail){
        if(head==tail) return NULL;
        //only one lement remaining
        if(head->next==tail) return new TreeNode(head->val);

        ListNode *slow = head;
        ListNode *fast = head;

        while(fast!= tail && fast->next!=tail){
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode *root = new TreeNode(slow->val);
        root->left = sol(head,slow);
        root->right = sol(slow->next,tail);

        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode *tail =NULL;
        return sol(head,tail);
    }
};