class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(k, 1));
        int mx = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int rem = (nums[i] + nums[j]) % k;
                dp[i][rem] = dp[j][rem] + 1;
                mx = max(mx, dp[i][rem]);
            }
        }
        return mx;
    }
};