class Solution {
public:
    int sol(int i,int j,int n,int m,vector<vector<int>>& grid,vector<vector<int>>&dp){
        if(j<0 || j>=m) return 1e9;
        if(i==n-1) return grid[i][j];

        if(dp[i][j] !=-1) return dp[i][j];
        int ans=INT_MAX;
        
        for(int k=0;k<m;k++){
            if(k==j) continue; //should not be in same column
            int res=grid[i][j]+sol(i+1,k,n,m,grid,dp);
            ans=min(ans,res);
        }
        return dp[i][j]=ans;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=INT_MAX;
        vector<vector<int>> dp(grid.size(),vector<int> (grid[0].size(),-1));
        for(int i=0;i<m;i++){
            ans=min(ans,sol(0,i,n,m,grid,dp));
        }
        return ans;
    }
};