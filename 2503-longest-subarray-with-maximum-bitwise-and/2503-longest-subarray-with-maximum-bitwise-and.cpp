class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int mxLen = 0;

        int mx = *max_element(nums.begin(), nums.end());
        int i = 0;
        while(i < n)
        {
            int pre = i;
            if(nums[i] == mx)
            {
                int j = i;
                int len = 0;
                while(j < n && (nums[j] == nums[i]))
                {
                    len++;
                    j++;
                }
                i = j;
                mxLen = max(mxLen, len);
            }
            
            if(i == pre) i++;
        }
        return mxLen;
    }
};