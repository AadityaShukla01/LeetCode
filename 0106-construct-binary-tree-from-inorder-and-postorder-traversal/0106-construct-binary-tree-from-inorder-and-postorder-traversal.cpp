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
    TreeNode *sol(vector<int>& inorder, vector<int>& postorder,int &postIn,int left,int right){
        if(left>right)
            return NULL;
        
        int element=postorder[postIn--];
        int in=map[element];

        TreeNode *root=new TreeNode(element);
        root->right=sol(inorder,postorder,postIn,in+1,right);
        root->left=sol(inorder,postorder,postIn,left,in-1);

        return root;
    }
    unordered_map<int,int>map;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
       int n=inorder.size();
       for(int i=0;i<n;i++)
        map[inorder[i]]=i;

        int postIn=n-1;
        return sol(inorder,postorder,postIn,0,n-1);
    }
};