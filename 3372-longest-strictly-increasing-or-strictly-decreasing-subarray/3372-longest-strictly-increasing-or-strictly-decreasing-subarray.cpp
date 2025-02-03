class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int inc = 1, dec = 1;
        int mx = 1;
        for(int i=0; i<n-1; i++)
        {
            if(nums[i] < nums[i + 1])
            {
                inc++;
            }
            else inc = 1;

            if(nums[i] > nums[i + 1])
            {
                dec++;
            }
            else dec = 1;

            mx = max({mx, inc, dec});
        }
        return mx;
    }
};