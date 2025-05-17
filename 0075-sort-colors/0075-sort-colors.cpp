class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int lo = 0, mi = 0, hi = n - 1;

        while (mi <= hi) {
            if (nums[mi] == 0) {
                swap(nums[lo], nums[mi]);
                lo++;
                mi++;
            } else if (nums[mi] == 1)
                mi++;
            else {
                swap(nums[mi], nums[hi]);
                hi--;
            }
        }
    }
};