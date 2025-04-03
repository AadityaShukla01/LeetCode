class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<long long>rightMax(n);
        long long mx = 0, ans = 0;

        for(int i=n-1; i>=0; i--)
        {
            rightMax[i] = mx;
            mx = max(mx, 1LL * nums[i]);
        }

        mx = 0;

        for(int i=0; i<n; i++)
        {
            long long mxDiff = mx - nums[i];
            long long res = 1LL * mxDiff * rightMax[i];
            ans = max(ans, res);
            mx = max(mx, 1LL * nums[i]);
        }
        return ans;
    }
};