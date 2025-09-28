class Solution {
public:
    int dp[100001];
    int sol(int i, int n, vector<int>& costs) {
        if (i > n)
            return 1e9;
        if (i == n)
            return 0;
        if(dp[i] != -1) return dp[i];
        int ans = 1e9;

        if (i + 1 <= n)
            ans = min(ans, sol(i + 1, n, costs) + (costs[i] + 1));

        if (i + 2 <= n)
            ans = min(ans, sol(i + 2, n, costs) + (costs[i + 1] + 4));

        if (i + 3 <= n)
            ans = min(ans, sol(i + 3, n, costs) + (costs[i + 2] + 9));

        return dp[i] = ans;
    }
    int climbStairs(int n, vector<int>& costs) { 
        memset(dp, -1, sizeof(dp));
        return sol(0, n, costs); 
    }
};