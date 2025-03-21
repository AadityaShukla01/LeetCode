class Solution {
public:
    int sol(int i, vector<int>cost,vector<int> &dp,int n){
        if(i>=n)
            return 0;
        if(dp[i] != -1)
            return dp[i];
            
        int step1 = sol(i+1,cost,dp,n)+cost[i];
        int step2 = sol(i+2,cost,dp,n)+cost[i];

        return dp[i] = min(step1,step2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n =cost.size();
        vector<int>dp(n+1,-1);
        return min(sol(0,cost,dp,n),sol(1,cost,dp,n));
    }
};