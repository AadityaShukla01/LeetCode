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
    bool sol(TreeNode* root, ListNode* head)
    {
        if(head == NULL) return true;
        if(!root) return false;
        if(root->val != head->val) return false;

        bool ans = false;


        ans = ans | sol(root->left, head->next);
        ans = ans | sol(root->right, head->next);

        return ans;
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(!root) return false;
        bool ans = false;
        if(head->val == root->val)
            ans = ans | sol(root, head);

        ans |= isSubPath(head, root->left);
        ans |= isSubPath(head, root->right);

        return ans;
    }
};