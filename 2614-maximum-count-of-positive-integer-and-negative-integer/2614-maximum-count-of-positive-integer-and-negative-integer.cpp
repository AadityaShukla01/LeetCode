class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int lo = 0, hi = n - 1;
        int f = -1, s = n;

        while(lo <= hi)
        {
            int mi = lo + (hi - lo)/2;

            if(nums[mi] < 0)
            {
                f = mi;
                lo = mi + 1;
            }
            else hi = mi - 1;
        }
        lo = 0;
        hi = n - 1;
        while(lo <= hi)
        {
            int mi = lo + (hi - lo)/2;

            if(nums[mi] > 0)
            {
                s = mi;
                hi = mi - 1;
            }
            else lo = mi + 1;
        }
        
        return max(f + 1, n - s);
    }
};