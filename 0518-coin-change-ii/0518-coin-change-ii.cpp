class Solution {
public:
    int sol(int amount,int i,vector<int>&coins,vector<vector<int>>&dp){
        if(amount==0) return 1;
            if(i==0){
            if(amount%coins[i]==0)
            return 1;

            return 0;
        }
        if(dp[i][amount]!=-1)
        return dp[i][amount];
        int pick=0;
        if(amount>=coins[i])
        pick=sol(amount-coins[i],i,coins,dp);

        int notPick=sol(amount,i-1,coins,dp);
        //no of ways pucha hain isisliye add kiya
        return dp[i][amount]=pick+notPick;
    }
    int change(int amount, vector<int>& coins) {
        int size=coins.size()-1;
        vector<vector<int>>dp(size+1,vector<int>(amount+1,-1));
        int q=sol(amount,size,coins,dp);
        return q;
    }
};