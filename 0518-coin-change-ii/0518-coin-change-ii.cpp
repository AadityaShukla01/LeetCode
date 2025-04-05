class Solution {
public:
    int dp[301][5002];
    int sol(int i, int n, int amount, vector<int>&coins)
    {
        if(i >= n) return amount == 0;
        if(dp[i][amount] != -1)
            return dp[i][amount];

        int p = 0, np = 0;

        if(amount >= coins[i])
            p = sol(i, n, amount - coins[i], coins);
        np = sol(i + 1, n, amount, coins);

        return dp[i][amount] = p + np;     
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        memset(dp, -1, sizeof(dp));
        return sol(0, n, amount, coins);
    }
};