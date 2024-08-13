class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) {
        int n = nums.size();
        int lo = 0;
        int hi = n - 1;

        while(lo <= hi){
            int mi = lo + (hi - lo)/2;

            if(mi - 1 >= 0 && mi + 1 < n && nums[mi] >= nums[mi - 1] && nums[mi + 1] <= nums[mi])
                return mi;

            if(mi + 1 < n && nums[mi] < nums[mi + 1]) lo = mi + 1;
            else if(mi  - 1 >= 0 && nums[mi - 1] > nums[mi]) hi = mi - 1;
        }

        return -1;
    }
};