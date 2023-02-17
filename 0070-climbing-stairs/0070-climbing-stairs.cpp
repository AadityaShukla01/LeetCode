class Solution {
public:
    int sol(int n ,vector<int>&dp){
        if(n==0)
        return 1;

        if(n==1)
        return 1;

        if(dp[n]!=-1)
        return dp[n];

        else dp[n]= sol(n-1,dp)+sol(n-2,dp);

        return dp[n];
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return sol(n,dp);
    }
};