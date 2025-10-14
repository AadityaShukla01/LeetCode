class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int prev = 0;
        while (i < n) {
            int cnt = 1;
            while (i + 1 < n && nums[i + 1] > nums[i]) {
                cnt++;
                i++;
            }
            if (cnt >= k && prev >= k) {
                return true;
            }
            if (cnt >= 2 * k)
                return true;
            i++;
            prev = cnt;
        }
        return false;
    }
};