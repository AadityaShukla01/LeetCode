class Solution {
public:
    int dp[1001][1001];
    int sol(int i, int j, vector<int>& nums){
        if(i>j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = -1e9;
        for(int k=i;k<=j;k++){
            int steps = nums[i-1]*nums[j+1]*nums[k] + sol(k+1,j,nums)+sol(i,k-1,nums);
            ans=max(ans,steps);
        }
        return dp[i][j] =  ans;
    }
    int maxCoins(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int N = nums.size();
        nums.push_back(1);
        // reverse(nums.begin(),nums.end());
        nums.insert(nums.begin(),1);
        return sol(1,N,nums);
    }
};