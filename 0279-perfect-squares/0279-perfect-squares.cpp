class Solution {
public:
    int sol(int n,vector<int> & dp){
        //base case
        if(n<0)return 0;
        if(n==0)return 1;
        if(dp[n]!=-1)return dp[n];

        //condition
        int ans = INT_MAX;
        for(int i=1;i<=sqrt(n);i++){
            ans = min(ans,1 + sol(n-i*i,dp));
        }
        return dp[n] = ans;
}
    int numSquares(int n) {
        vector<int>dp(n+1,-1);
        return sol(n,dp)-1;
    }
    
};