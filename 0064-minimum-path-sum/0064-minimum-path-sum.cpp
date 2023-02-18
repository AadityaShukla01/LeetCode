class Solution {
public:
    int sol(vector<vector<int>>& ques,int i ,int j,vector<vector<int>>& dp){
        if(i==0 && j==0)
        return ques[0][0];

        if(i<0 || j<0)
        return 1e6;

        if(dp[i][j]!=-1)
            return dp[i][j];

        int down=sol(ques,i-1,j,dp)+ques[i][j];
        int right=sol(ques,i,j-1,dp)+ques[i][j];

        return dp[i][j]=min(down,right);
    }
    int minPathSum(vector<vector<int>>& ques) {
        int m=ques.size();
        int n=ques[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
       return sol(ques,m-1,n-1,dp); 
    }
};