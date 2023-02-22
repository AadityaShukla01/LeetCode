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
            profit = max(sol(i + 1, 0, prices, profit, dp) -prices[i], sol(i + 1, 1, prices, profit, dp) + 0);
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
        // vector<vector<int>> dp(num, vector<int>(2, -1));

        int num=prices.size();
        //space optimization
        long currBuy=0,aheadBuy=0,currNotBuy =0,aheadNotBuy=0;
        for(int i=num-1;i>=0;i--){
            currNotBuy=max(prices[i]+aheadBuy,aheadNotBuy+0);

            currBuy=max(-prices[i]+aheadNotBuy,aheadBuy+0);

            aheadBuy=currBuy;
            aheadNotBuy=currNotBuy;
        }
        // sol(0, buy, prices, profit, dp);
        return aheadBuy;
    }
};