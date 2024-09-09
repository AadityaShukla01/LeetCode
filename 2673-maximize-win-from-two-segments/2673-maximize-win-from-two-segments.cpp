class Solution {
public:
    int dp[100001][3];
    int sol(int i, int n, int cnt, int k, vector<int>&nums)
    {
        if(cnt == 0) return 0;
        if(i >= n) return 0;
        if(dp[i][cnt] != -1) return dp[i][cnt];
        int index = upper_bound(nums.begin(), nums.end(), nums[i] + k) - nums.begin();

        int len = index - i;

        int p = sol(index, n, cnt - 1, k, nums) + len;
        int np = sol(i + 1, n, cnt, k, nums);

        return dp[i][cnt] = max(p, np);
    }
    int maximizeWin(vector<int>& nums, int k) {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        return sol(0, n, 2, k, nums);
    }
};