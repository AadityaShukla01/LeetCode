class Solution {
public:
    bool isValid(int i,int j,int n,int m){
        if(i>=0 && j>=0 && i<n && j<m) return true;

        return false;
    }
    int sol(int i,int j,int n,int m,vector<vector<int>>& matrix,vector<vector<int>>&dp){
        int maxi=1;

        int up=0;
        int down=0;
        int left=0;
        int right=0;
        if(dp[i][j] !=-1) return dp[i][j];

        //check for all possible paths and chose the maxmimum of aall
        if(isValid(i-1,j,n,m)){
            if(matrix[i][j] > matrix[i-1][j])
                up=1+sol(i-1,j,n,m,matrix,dp);
        }
        if(isValid(i,j-1,n,m)){
            if(matrix[i][j] > matrix[i][j-1])
                left=1+sol(i,j-1,n,m,matrix,dp);
        }
        if(isValid(i+1,j,n,m)){
            if(matrix[i][j] > matrix[i+1][j])
                down=1+sol(i+1,j,n,m,matrix,dp);
        }
        if(isValid(i,j+1,n,m)){
            if(matrix[i][j] > matrix[i][j+1])
                right=1+sol(i,j+1,n,m,matrix,dp);
        }
        //select the path giving maximum sum
        return dp[i][j]=max(up,max(right,max(left,down)));
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int ans=0;
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                //starting point can be any element of matrix so wee use 2 loops
                int res=sol(i,j,n,m,matrix,dp);
                ans=max(ans,res);
            }
        }
        return ans+1;
    }
};