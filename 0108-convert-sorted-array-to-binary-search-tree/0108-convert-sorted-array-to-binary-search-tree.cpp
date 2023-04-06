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
    TreeNode *sol(vector<int>nums,int l,int r){
        if(l>r) return NULL;

        int m=(l+r)/2;
        TreeNode *root=new TreeNode(nums[m]);
        //construct left part
        root->left=sol(nums,l,m-1);

        //construcr right part
        root->right=sol(nums,m+1,r);

        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sol(nums,0,nums.size()-1);
    }
};
