class Solution {
public:
    int dp[16][1 << 17];
    int sol(int i, int n, int curr, int mxOr, vector<int>& nums) {
        if (i >= n)
            return curr == mxOr;
        if(dp[i][curr] != -1) return dp[i][curr];

        int np = sol(i + 1, n, curr, mxOr, nums);
        int p = sol(i + 1, n, curr | nums[i], mxOr, nums);

        return dp[i][curr] = p + np;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int mxOr = 0;
        for (auto el : nums)
            mxOr |= el;
        memset(dp, -1, sizeof(dp));
        return sol(0, n, 0, mxOr, nums);
    }
};