class Solution {
public:
    int dp[21][2001];
    int sol(int i, int n, int sum, vector<int>&nums, int target)
    {
        if(i >= n) return sum == target;

        if(dp[i][sum + 1000] != -1)
            return dp[i][sum + 1000];

        int op1 = sol(i + 1, n, sum + nums[i], nums, target);
        int op2 = sol(i + 1, n, sum - nums[i], nums, target);

        return dp[i][sum + 1000] = op1 + op2;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        return sol(0, n, 0, nums, target);
    }
};