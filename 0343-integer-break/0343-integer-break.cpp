class Solution {
public:
    int dp[1001];
    int sol(int i, int n)
    {
        if(i == n) return 1;
        if(i > n) return 0;
        if(dp[i] != -1) return dp[i];
        int ans = 0;
        for(int j=1; j<n; j++)
        {
            int steps = sol(i + j, n) * j;
            ans = max(ans, steps);
        }
        return dp[i] = ans;
    }
    int integerBreak(int n) {
        memset(dp, -1, sizeof(dp));
        return sol(0, n);
    }
};