class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n, 0);

        for(int i=0; i<n; i++)
        {
            if(nums[i] > 0)
            {
                int index = (i + nums[i]) % n;
                ans[i] = nums[index];
            }
            else if(nums[i] < 0)
            {
                int index = ((i + nums[i]) % n + n) % n;
                ans[i] = nums[index];
            }
        }
        return ans;
    }
};