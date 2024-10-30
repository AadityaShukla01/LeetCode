class Solution {
public:
    int dp[1001][1001][3][2];
    int sol(int i, int n, int pre, vector<int>&nums, int flag, int f1)
    {
        if(i >= n && flag == 2) return 0;

        if(i >= n) return 1e9;

        if(dp[i][pre][flag][f1] != -1)
            return dp[i][pre][flag][f1];

        int ans = 1e9;

        if(flag == 0)
        {
            int op1 = sol(i + 1, n, i, nums, 1, 0) ;
            int op2 = sol(i + 1, n, pre, nums, 0, 1) + 1;

            ans = min({ans, op1, op2});
        }
        else if(flag == 1)
        {
            ans = min(ans, sol(i + 1, n, pre, nums, 1, f1) + 1);
            if(nums[i] > nums[pre])
            {
                ans = min(ans, sol(i + 1, n, i, nums, 1, 1));
            }
            else if(nums[i] < nums[pre] && f1)
            {
                ans = min(ans, sol(i + 1, n, i, nums, 2, f1));
            }
            else{
                ans = min(ans, sol(i + 1, n, pre, nums, 1, f1) + 1);
            }
        }
        else{
            ans = min(ans, sol(i + 1, n, pre, nums, 2, f1) + 1);

            if(nums[i] < nums[pre]){
                ans = min(ans, sol(i + 1, n, i, nums, 2, f1));
            }
            else{
                ans = min(ans, sol(i + 1, n, pre, nums, 2, f1) + 1);
            }
        }
        return dp[i][pre][flag][f1] = ans;
    }
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        return sol(0, n, 0, nums, 0, 0);
    }
};