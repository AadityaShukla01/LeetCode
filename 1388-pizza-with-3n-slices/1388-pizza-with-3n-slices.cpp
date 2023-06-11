class Solution {
public:
    int dp[501][301];
    int sol(int i,int l, int n, int limit, vector<int>& slices){
        if(limit==0 || i>l) return 0;
        if(dp[i][limit] != -1) return dp[i][limit];

        int pick=0;
        int notPick=0;

        pick=sol(i+2,l,n,limit-1,slices)+slices[i];
        notPick=sol(i+1,l,n,limit,slices);

        return dp[i][limit] = max(pick,notPick);
    }
    int maxSizeSlices(vector<int>& slices) {
        memset(dp,-1,sizeof(dp));
        int n = slices.size();
        int case1=sol(0,n-2,n,n/3,slices);  
        memset(dp,-1,sizeof(dp)); 
        int case2 = sol(1,n-1,n,n/3,slices);
        
        return max({case1,case2});
    }
};