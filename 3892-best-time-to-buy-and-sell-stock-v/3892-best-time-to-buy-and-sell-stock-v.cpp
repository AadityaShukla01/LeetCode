class Solution {
public:
    long long dp[1001][502][4];
    long long sol(int i, int n, vector<int>&prices, int k, int buy){
        if (i >= prices.size()) {
            if (buy != 0) return -1e18;
            return 0;
        }

        if (k == 0) return 0;

        if(dp[i][k][buy] != -1) return dp[i][k][buy];

        long long ans = 0;

        if(buy == 0){
            long long op1 = sol(i + 1, n, prices, k, 0);
            long long op2 = sol(i + 1, n, prices, k, 1) - 1LL * prices[i] ;
            long long op3 = sol(i + 1, n, prices, k, 2) + 1LL * prices[i] ;

            ans = max({op1, op2, op3});
        }
        else if(buy == 1){
            long long op1 = sol(i + 1, n, prices, k - 1, 0) + 1LL * prices[i];
            long long op2 = sol(i + 1, n, prices, k, 1);

            ans = max({op1, op2});
        }
        else {
            long long op1 = sol(i + 1, n, prices, k - 1, 0) - 1LL * prices[i];
            long long op2 = sol(i + 1, n, prices, k, 2);

            ans = max({op1, op2});
        }
        return dp[i][k][buy] = ans;
    }

    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        memset(dp, -1, sizeof(dp));
        return sol(0, n, prices, k, 0);
    }
};