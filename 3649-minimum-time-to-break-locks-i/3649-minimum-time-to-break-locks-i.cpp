class Solution {
public:
    int dp[1 << 8][81];
    int sol(int mask, int n, vector<int>&nums, int factor, int k)
    {
        if(mask == (1 << n) - 1)
            return 0;

        if(dp[mask][factor] != -1)
            return dp[mask][factor];

        int ans = 1e9;

        for(int i=0; i<n; i++)
        {
            if(!(mask & (1 << i)))
            {
                int val = 0;
                if(mask == 0)
                {
                    val = nums[i];
                }
                else
                {
                    val = nums[i] / factor;
                    if(nums[i] % factor) val++;
                }

                int steps = sol(mask | (1 << i), n, nums, factor + k, k) + val;
                ans = min(ans, steps);
            }
        }
        return dp[mask][factor] = ans;
    }
    int findMinimumTime(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        memset(dp, -1, sizeof(dp));
        return sol(0, n, nums, 1, k);
    }
};