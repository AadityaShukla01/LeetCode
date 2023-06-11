class Solution {
public:
// tc-o(k*n^2)
    double dp[101][101];
    double sol(int n, int k,int curr,vector<int>& nums){
        if(curr>=n || k<0) return 0;
        if(k==0) return INT_MIN;
        if(dp[curr][k] != 0) return dp[curr][k];

        double ans = 0;
        double sum = 0;
        for(int j=curr;j<n;j++){
            sum=sum+nums[j];
            ans=max(ans,(sum/(j-curr+1))+sol(n,k-1,j+1,nums));
        }
        return dp[curr][k] = ans;
    }
    double largestSumOfAverages(vector<int>& nums, int k) {
        int n = nums.size();
        memset(dp,0,sizeof(dp));
        return sol(n,k,0,nums);
    }
};