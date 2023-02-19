class Solution {
public:
    int sol(int m,int n,vector<vector<int>>& A,vector<vector<int>>& dp){

        if(n<0 || n>=A[0].size())
        return 10001;
        if(m==0)
        return A[0][n];

        if(dp[m][n]!=-1)
        return dp[m][n];

        int down = A[m][n] + sol(m-1,n,A,dp);
        int diagonal = A[m][n]+sol(m-1,n-1,A,dp);
        int diagonalRight = A[m][n] + sol(m-1,n+1,A,dp);

        return dp[m][n]=min(down,min(diagonal,diagonalRight));
    }
    int minFallingPathSum(vector<vector<int>>& A) {
        int m=A.size();
        int n=A[0].size();
        int mini=1e9;
        
        vector<vector<int>>dp(m,vector<int>(n,-1));
        //call function for every column of last row
        for(int j=0;j<n;j++){
            mini=min(mini,sol(m-1,j,A,dp));
        }
        return mini;
    }
};