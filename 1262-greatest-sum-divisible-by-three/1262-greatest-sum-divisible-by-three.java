class Solution {
    public static int sol(int i, int rem, int n, int[] nums, int[][] dp) {
        if (i >= n) {
            if (rem == 0)
                return 0;
            return -100000007;
        }

        if (dp[i][rem] != -1)
            return dp[i][rem];

        int p = sol(i + 1, (rem + nums[i]) % 3, n, nums, dp) + nums[i];
        int np = sol(i + 1, rem, n, nums, dp);

        return dp[i][rem] = Math.max(p, np);
    }

    public int maxSumDivThree(int[] nums) {
        int n = nums.length;
        int[][] dp = new int[n][3];

        for (int i = 0; i < n; i++) {
            Arrays.fill(dp[i], -1);
        }

        return sol(0, 0, n, nums, dp);
    }
}