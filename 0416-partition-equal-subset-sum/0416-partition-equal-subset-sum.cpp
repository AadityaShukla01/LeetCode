class Solution {
public:
    int dp[201][101 * 201];
    bool sol(int i, int n, vector<int>&nums, int sum)
    {
        if(i >= n) return sum == 0;
        if(dp[i][sum] != -1) return dp[i][sum];

        bool np = sol(i + 1, n, nums, sum);

        bool p = false;

        if(sum >= nums[i])
        {
            p = sol(i + 1, n, nums, sum - nums[i]);
        }

        return dp[i][sum] = p || np;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        memset(dp, -1, sizeof(dp));
        for(auto el: nums) sum += el;

        if(sum % 2) return false;

        return sol(0, n, nums, sum / 2);
    }
};