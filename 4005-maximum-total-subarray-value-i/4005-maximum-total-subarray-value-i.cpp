class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return 1LL * (nums[n - 1] - nums[0]) * k;
    }
};