class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = n;
        int lo = 0;
        int hi = n - 1;

        while(lo <= hi){
            int mi = lo + (hi - lo)/2;

            if(nums[mi] == target) return mi;
            else if(nums[mi] > target){
                ans = mi;
                hi = mi - 1;
            }
            else lo = mi + 1;
        }
        return ans;
    }
};