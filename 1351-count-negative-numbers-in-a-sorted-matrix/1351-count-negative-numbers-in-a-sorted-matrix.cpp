class Solution {
public:
    int sol(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = n - 1;
        int ans = -1;
        while (i <= j) {
            int m = (i + j) / 2;
            if (nums[m] < 0) {
                j = m - 1;
            } else {
                ans = m;
                i = m + 1;
            }
        }
        return n - (ans + 1);
    }
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int count = 0;

        for (int i = 0; i < n; i++) {
            count += sol(grid[i]);
        }
        return count;
    }
};