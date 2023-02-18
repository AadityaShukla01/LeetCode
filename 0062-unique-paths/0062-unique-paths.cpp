class Solution {
public:
    int sol(int i,int j,vector<vector<int>> &dp){
        if(i==0 && j==0 )
        return 1; 
        if(i<0 || j<0)
        return 0;

        if(dp[i][j]!=-1)
        return dp[i][j];

        int down=sol(i-1,j,dp);
        int right=sol(i,j-1,dp);

        return dp[i][j]=down+right;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        if(m==1 && n==1)
        return 1;

        // initialising first column & row with 1 because only one way to reach
        for(int i = 1; i < m; i++)
            dp[i][0]=1;
        for(int i = 1; i < n; i++)
            dp[0][i]=1;

        for(int i = 1; i < m; i++)
            for(int j = 1; j < n; j++)
                dp[i][j] = dp[i-1][j] + dp[i][j-1];   // sum of unique paths ending at adjacent top and left cells
        return dp[m-1][n-1];         // return unique paths ending at cell (m-1, n-1)
    }
};