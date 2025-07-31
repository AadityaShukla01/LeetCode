class Solution {
public:
    int dp[1001];
    int sol(int n, vector<int>&nums, int target){
        if(target == 0) return 1;
        if(target < 0) return 0;

        if(dp[target] != -1)
            return dp[target];

        int ans = 0;
        for(int j=0; j<n; j++){
            int steps = sol(n, nums, target - nums[j]);
            ans += steps;
        }
        return dp[target] = ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        return sol(n, nums, target);
    }
};