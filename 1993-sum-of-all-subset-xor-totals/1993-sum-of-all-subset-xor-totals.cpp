class Solution {
public:
    int dp[12][32];
    int sol(int i, int n, vector<int>&nums, int xorr)
    {
        if(i >= n) return xorr;

        if(dp[i][xorr] != -1)
            return dp[i][xorr];

        int p = sol(i + 1, n, nums, xorr ^ nums[i]);
        int np = sol(i + 1, n, nums, xorr);

        return dp[i][xorr] = p + np; 
    }
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        return sol(0, n, nums, 0);
    }
};