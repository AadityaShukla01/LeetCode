class Solution {
public:
    int subarraySum(vector<int>& nums) {
        int n = nums.size();
        vector<int>ps(n + 1, 0);

        for(int i=1; i<=n; i++)
        {
            ps[i] = ps[i - 1] + nums[i - 1];
        }
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            ans += ps[i + 1] - ps[max(0, i - nums[i])];
        }
        return ans;
    }
};