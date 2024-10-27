class Solution {
public:
    int dp[201][202][202];
    const int mo = 1e9 + 7;
    int sol(int i, int g1, int g2, vector<int>& nums, int n) {
        if (i >= n)
            return g1 == g2;

        if(dp[i][g1 + 1][g2 + 1] != -1)
            return dp[i][g1 + 1][g2 + 1];

        long long ans = 0;    

        ans += sol(i + 1, g1, g2, nums, n);

        if (g1 == -1) {
            ans += sol(i + 1, nums[i], g2, nums, n);
        }

        if (g2 == -1) {
            ans += sol(i + 1, g1, nums[i], nums, n);
        }
        if (g1 != -1) {
            ans += sol(i + 1, __gcd(g1, nums[i]), g2, nums, n);
        }
        if (g2 != -1) {
            ans += sol(i + 1, g1, __gcd(g2, nums[i]), nums, n);
        }
        ans %= mo;
        return dp[i][g1 + 1][g2 + 1] = ans;
    }
    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        return sol(0, -1, -1, nums, n) - 1;
    }
};