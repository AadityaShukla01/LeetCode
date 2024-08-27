
class Solution {
public:
    // tc is height of tree we can reduce space to constant by using iterative
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root) {
            if ((root->val > p->val) && (root->val > q->val)) {
                root = root->left;
            }
            else if ((root->val < p->val) && (root->val < q->val)) {
                root = root->right;
            }
            else
                return root;
        }
        return NULL;
    }
};