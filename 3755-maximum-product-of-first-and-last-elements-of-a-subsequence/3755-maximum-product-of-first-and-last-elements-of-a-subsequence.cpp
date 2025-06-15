class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        long long ans = -1e16;
        int n = nums.size();
        vector<int> mx(n, -1e9), mn(n, 1e9);
        long long mnn = 1e16, mxx = -1e16;
        for (int i = 0; i < n; i++) {
            if (i - m + 1 >= 0) {
                int mnEl = mn[i - m + 1];
                int mxEl = mx[i - m + 1];
                // cout << mnEl << " " << mxEl << " " << nums[i] << endl;
                ans = max({ans, 1LL * mnEl * nums[i], 1LL * mxEl * nums[i]});
            }
            mnn = min(mnn, 1LL*nums[i]);
            mxx = max(mxx, 1LL*nums[i]);
            mn[i] = mnn;
            mx[i] = mxx;
        }
        if (m == 1) {
            return max(1LL * mnn * mnn, 1LL * mxx * mxx);
        }
        return ans;
    }
};