class Solution
{
public:
    int sol(int i, int buy, vector<int> &prices, int profit, vector<vector<int>> &dp)
    {
        if (i >= prices.size())
            return 0;
        if (dp[i][buy] != -1)
            return dp[i][buy];

        if (buy)
        {
            profit = max(sol(i + 1, 0, prices, profit, dp) - prices[i], sol(i + 1, 1, prices, profit, dp));
        }
        else
        {
            profit = max(sol(i + 2, 1, prices, profit, dp) + prices[i], sol(i + 1, 0, prices, profit, dp));
        }
        return dp[i][buy] = profit;
    }
    int maxProfit(vector<int> &prices)
    {
        int a = prices.size();
        int profit = 0;
        vector<vector<int>> dp(prices.size() + 2, vector<int>(2, 0));
        // return sol(0,1,prices,profit,ram);
        for (int i = prices.size() - 1; i >= 0; i--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                if (buy == 1)
                {
                    dp[i][buy] = max(dp[i + 1][0] - prices[i], dp[i + 1][1]);
                }
                else
                {
                    dp[i][buy] = max(dp[i + 2][1] + prices[i], dp[i + 1][0]);
                }
            }
        }
        return dp[0][1];
    }
};