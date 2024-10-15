class Solution {
public:
    int mx = 0;  // Initialize to 0 to track the maximum ZigZag path length
    
    int sol(TreeNode* root, int left, int length) {
        if (!root) return 0;  // If root is null, there's no path to follow
        
        // Update the maximum ZigZag length found so far
        mx = max(mx, length);
        
        if (left == 1) {
            // Left direction: Move to the left child and continue the path
            sol(root->left, 0, length + 1);
            // Move to the right child and reset the path
            sol(root->right, 1, 1);
        } else {
            // Right direction: Move to the right child and continue the path
            sol(root->right, 1, length + 1);
            // Move to the left child and reset the path
            sol(root->left, 0, 1);
        }
        return mx;
    }

    int longestZigZag(TreeNode* root) {
        if (!root) return 0;
        sol(root, 1, 0);  // Start with left ZigZag
        sol(root, 0, 0);  // Start with right ZigZag
        return mx;
    }
};
