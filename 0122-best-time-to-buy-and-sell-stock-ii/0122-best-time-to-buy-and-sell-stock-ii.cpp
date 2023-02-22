class Solution
{
public:
    int sol(int i, bool buy, vector<int> &prices, int &profit, vector<vector<int>> &dp)
    {
        if (i == prices.size()) // you can not biy or sell now
            return 0;
        // we can only buy if we have sold something since we can not buy 2 itemsa ata time

        if (dp[i][buy] != -1)
            return dp[i][buy];

        if (buy)
        {                //take                                             //not take
            profit = max(sol(i + 1, 0, prices, profit, dp) + (-prices[i]), sol(i + 1, 1, prices, profit, dp) + 0);
        }

        else
        {
            profit = max(sol(i + 1, 1, prices, profit, dp) + prices[i], sol(i + 1, 0, prices, profit, dp) + 0);
        }
        return dp[i][buy] = profit;
    }
    int maxProfit(vector<int> &prices)
    {
        int i = 0;
        bool buy = true;
        int profit = 0;
        int num=prices.size();
        vector<vector<int>> dp(num, vector<int>(2, -1));
        sol(0, buy, prices, profit, dp);
        return profit;
    }
};