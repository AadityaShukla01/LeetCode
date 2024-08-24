class Solution {
public:
    int dp[13][10001];
    int sol(int i, int n, vector<int>& coins, int amount) {
        if (i == n) {
            if(amount == 0) return 0;
            return 1e9;
        }
        if(dp[i][amount] != -1) return dp[i][amount];

        int ans = 1e9;
        if (amount >= coins[i]) {
            int pick = 1 + sol(i, n, coins, amount - coins[i]);

            ans = min(pick, ans);
        }
        
        int notPick = sol(i + 1, n, coins, amount);
        ans = min(ans,  notPick);


        return dp[i][amount] = ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        memset(dp, -1, sizeof(dp));
        int a = sol(0, n, coins, amount);
        if (a == 1e9)
            return -1;
        return a;
    }
};