class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int len = 0;
        int mx = 1;

        int i = 0, j = 0;

        while(i < n)
        {
            if(nums[i] - nums[j] > 2*k)
            {
                while(nums[i] - nums[j] > 2*k)
                {
                    j++;
                }
            }

            mx = max(mx, i - j + 1);
            i++;
        }
        return mx;
    }
};