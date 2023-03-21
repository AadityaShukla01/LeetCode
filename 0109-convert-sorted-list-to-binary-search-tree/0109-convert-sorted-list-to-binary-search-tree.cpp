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
//  Traverse the list to get the middle element and make that the root. left side of the list forms left sub-tree and right side of the middle element forms the right sub-tree.
class Solution {
public:
TreeNode*sol(ListNode*head,ListNode*tail){
    if(head==tail) return NULL;
    if(head->next==tail) return new TreeNode(head->val);

    //reaching to middle of linked list
    ListNode*slo=head;
    ListNode*fast=head;
    while(fast!=tail && fast->next!=tail){
        slo=slo->next;
        fast=fast->next->next;
    }
    TreeNode*root=new TreeNode(slo->val);
    root->left=sol(head,slo);
    root->right=sol(slo->next,tail);
    return root;
}
    TreeNode* sortedListToBST(ListNode* head) {
        return sol(head,NULL);
    }
};