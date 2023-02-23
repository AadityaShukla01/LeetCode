class Solution {
public:
    int sol(int i,int buy,vector<int>&prices,int profit,int fee,vector<vector<int>>&dp){
        if(i==prices.size()) return 0;

        if(dp[i][buy]!=-1) return dp[i][buy];
        if(buy){
            profit=max(sol(i+1,0,prices,profit,fee,dp)-prices[i],sol(i+1,1,prices,profit,fee,dp));
        }
        else{
            profit=max(sol(i+1,1,prices,profit,fee,dp)+prices[i]-fee,sol(i+1,0,prices,profit,fee,dp));
        }
        return dp[i][buy]=profit;
}
    int maxProfit(vector<int>& prices, int fee) {
        bool buy = true;
        int profit = 0;
        // vector<vector<int>> dp(num, vector<int>(2, -1));

        int num=prices.size();
        //space optimization
        long currBuy=0,aheadBuy=0,currNotBuy =0,aheadNotBuy=0;
        for(int i=num-1;i>=0;i--){
            currNotBuy=max(prices[i]+aheadBuy,aheadNotBuy+0);

            currBuy=max(-prices[i]+aheadNotBuy-fee,aheadBuy+0);

            aheadBuy=currBuy;
            aheadNotBuy=currNotBuy;
        }
        // sol(0, buy, prices, profit, dp);
        return aheadBuy;
    }
};