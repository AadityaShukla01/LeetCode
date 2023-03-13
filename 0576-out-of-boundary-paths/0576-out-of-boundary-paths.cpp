class Solution {
public:
    long long MOD=1e9+7;
    int dp[51][51][51];
    int sol(int i,int j,int maxMove, int m, int n){
        //base cases for out of bounds
        if(i >= m) return 1;
        if(i < 0) return 1;
        if(j >= n) return 1;
        if(j <0) return 1;

        // if no Move remaining
        if( maxMove<=0 ) return  0;

        //memo  concept
        if(dp[i][j][maxMove]!=-1) return dp[i][j][maxMove];

        int up=sol(i-1,j,maxMove-1,m,n)%MOD;

        int down=sol(i+1,j,maxMove-1,m,n)% MOD;

        int left=sol(i,j-1,maxMove-1,m,n)%MOD;

        int right=sol(i,j+1,maxMove-1,m,n)%MOD;

        return dp[i][j][maxMove]=( up%MOD +left%MOD +down%MOD +right%MOD ) %MOD;
        
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn){
        memset(dp, -1, sizeof(dp));
        return sol(startRow,startColumn,maxMove,m,n);
    }
};