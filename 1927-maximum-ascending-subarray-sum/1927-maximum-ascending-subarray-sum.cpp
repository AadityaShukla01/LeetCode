class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int mx = 0;
        int pre = nums[0];
        sum = pre;
        mx = pre;

        for(int i=1; i<n; i++)
        {
            if(nums[i] > pre)
            {
                sum += nums[i];
            }
            else if(nums[i] <= pre)
            {
                sum = nums[i];
            }
            pre = nums[i];
            mx = max(mx, sum);
        }
        return mx;
    }
};