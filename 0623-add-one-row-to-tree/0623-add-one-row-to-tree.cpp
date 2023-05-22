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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        queue<TreeNode *>q;
        q.push(root);
        int l=1;
        if(depth==1){
            TreeNode *n=new TreeNode(val);
            n->left=root;
            return n;
        }
        while(q.empty()==false){
            int size=q.size();
            l++;
            for(int i=0;i<size;i++){
                TreeNode *node=q.front();
                q.pop();
                if(l==depth){
                    TreeNode *n1=new TreeNode(val);
                    TreeNode *n2=new TreeNode(val);
                    n1->left=node->left;
                    n2->right=node->right; 
                    node->left=n1;
                    node->right=n2;  
                }
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
        }
        return root;
    }
};