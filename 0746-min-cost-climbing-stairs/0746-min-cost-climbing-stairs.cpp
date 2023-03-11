class Solution {
public:
    int om(vector<int>&cost,int i,vector<int>&dp){
        if(i==1 || i==0) return cost[i];

        if(dp[i]!=-1) return dp[i];

        int a=om(cost,i-1,dp)+cost[i];
        int b=om(cost,i-2,dp)+cost[i];
        return dp[i]=min(a,b);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+1,-1);
        return min(om(cost,n-1,dp),om(cost,n-2,dp));
    }
    
};