class Solution {
public:
    int divBy2(int num)
    {
        if(num % 2 == 0) return num / 2;

        return (num / 2) + 1;
    }
    int dp[101][101][101];
    int sol(int i, int n, vector<int>& nums, int k, int op1, int op2) {
        if (i >= n)
            return 0;
        if(dp[i][op1][op2] != -1)
            return dp[i][op1][op2];
        int ans = 1e9;

        ans = min(ans, sol(i + 1, n, nums, k, op1, op2) + nums[i]);

        if (nums[i] >= k && op2) {
            int opt1 = 1e9;

            if (op1)
                opt1 = sol(i + 1, n, nums, k, op1 - 1, op2 - 1) + divBy2(nums[i] - k);

            int opt2 = sol(i + 1, n, nums, k, op1, op2 - 1) + (nums[i] - k);

            int opt3 = 1e9;

            if (op1 && divBy2(nums[i]) - k >= 0)
                opt3 = sol(i + 1, n, nums, k, op1 - 1, op2 - 1) + divBy2(nums[i]) - k;

            ans = min({ans, opt1, opt2, opt3});
        }

        if (op1) {
            int opt1 = sol(i + 1, n, nums, k, op1 - 1, op2) + divBy2(nums[i]);
            ans = min(ans, opt1);
        }

        return dp[i][op1][op2] = ans;
    }
    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        return sol(0, n, nums, k, op1, op2);
    }
};