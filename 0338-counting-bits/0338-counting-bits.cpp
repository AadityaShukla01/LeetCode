class Solution {
public:
    int sol(int n,vector<int>&dp){
        if(n==0) return 0;
        if(n==1) return 1;

        if(dp[n]!=-1) return dp[n];

        if(n % 2==0 )
            return dp[n]=sol(n/2,dp);

        else
            return dp[n]=1 +sol(n/2,dp);
    }
    vector<int> countBits(int n) {
        vector<int>dp(n+1,-1);
        vector<int>ans(n+1);
        
        for(int i=0;i<=n;i++){
            ans[i]=sol(i,dp);
        }
        return ans;
    }
};