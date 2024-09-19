class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int lo = 0;
        int hi = n - 1;

        int first = -1, sec = -1;

        while(lo <= hi)
        {
            int mi = lo + (hi - lo)/2;

            if(nums[mi] == target)
            {
                sec = mi;
                lo = mi + 1;
            }
            else if(nums[mi] > target) hi = mi - 1;
            else lo = mi + 1;
        } 
        lo = 0;
        hi = n - 1;

        while(lo <= hi)
        {
            int mi = lo + (hi - lo)/2;

            if(nums[mi] == target)
            {
                first = mi;
                hi = mi - 1;
            }
            else if(nums[mi] > target) hi = mi - 1;
            else lo = mi + 1;
        } 

        return {first, sec};
    }
};