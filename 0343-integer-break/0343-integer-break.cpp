class Solution {
public:
    int sol(int n,vector<int>&dp){
        if(n<0) return 1;

        if(dp[n]!=-1) return dp[n];

        int ans=0;
        for(int i=1;i<n;i++){
            int res=max(i*(n-i) ,i * sol(n-i,dp));
            ans=max(res,ans);
        }
        return dp[n]=ans;
    }
    int integerBreak(int n) {
        vector<int>dp(n+1,-1);
        return sol(n,dp);
    }
};