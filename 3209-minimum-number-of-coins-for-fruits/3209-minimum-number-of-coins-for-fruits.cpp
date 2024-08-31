class Solution {
public:
    int dp[1011][2];
    int sol(int i, int n, bool free, vector<int>& prices) {
        if (i >= n)
            return 0;

        if (dp[i][free] != -1)
            return dp[i][free];

        int ans = 1e9;

        if (free) {
            int nextIndex = (i - 1) + (i + 1);
            for (int j = i; j < min(n, nextIndex); j++) {
                int op1 = sol(j + 1, n, false, prices);
                ans = min(op1, ans);
            }
        }

        ans = min(ans, sol(i + 1, n, true, prices) + prices[i]);

        return dp[i][free] = ans;
    }
    int minimumCoins(vector<int>& prices) {
        int n = prices.size();
        memset(dp, -1, sizeof(dp));
        return sol(0, n, false, prices);
    }
};