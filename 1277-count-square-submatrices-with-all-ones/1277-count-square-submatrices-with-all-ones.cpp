class Solution {
public:
   
    int countSquares(vector<vector<int>>& matrix) {
        // dp[i][j] represent no of square matrixes ending at i,j
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        //fill first row & column as it is
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dp[i][0]=matrix[i][0];
                dp[0][j]=matrix[0][j];
            }
        }
        // we take minimum because we need squares not rectangles
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][j]==1){
                    dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
                }
                else dp[i][j]=0;
            }
        }
        int sum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                sum+=dp[i][j];
            }
        }
        return sum;
    }
};