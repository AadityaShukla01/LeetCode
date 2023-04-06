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
    unordered_map<int,int>map;
    TreeNode *sol(int left,int right,vector<int>& nums){
        if(left>right) return NULL;
        int maxi=-1;
        int maxAns=-1;

        for(int i=left;i<=right;i++)
            maxAns=max(maxAns,nums[i]);

        maxi=map[maxAns];

        TreeNode *root=new TreeNode(maxAns);
        //build tree -> recursion
        root->left=sol(left,maxi-1,nums);
        root->right=sol(maxi+1,right,nums);

        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        // if(root==NULL) return NULL;
        for(int i=0;i<nums.size();i++){
            map[nums[i]]=i;
        }

        return sol(0,nums.size()-1,nums);
    }
};