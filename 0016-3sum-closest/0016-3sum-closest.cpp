class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int ans = 0;
        int mn = 1e9;
        for (int i = 0; i < n; i++) {
            int lo = i + 1;
            int hi = n - 1;

            while (lo < hi) {
                if (nums[i] + nums[lo] + nums[hi] < target) {
                    if (target - (nums[i] + nums[lo] + nums[hi]) < mn) {
                        ans = nums[i] + nums[lo] + nums[hi];
                        mn = target - (nums[i] + nums[lo] + nums[hi]);
                    }
                    lo++;
                } 
                else if (nums[i] + nums[lo] + nums[hi] > target) {
                    if ((nums[i] + nums[lo] + nums[hi]) - target < mn) {
                        ans = nums[lo] + nums[hi] + nums[i];
                        mn = (nums[i] + nums[lo] + nums[hi]) - target;
                    }
                    hi--;
                } else {
                    return target;
                }
            }
        }
        return ans;
    }
};