class Solution {
public:
    int sol(int mi, vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> v(n + 1, 0);

        for (int i = 0; i <= mi; i++) {
            int a = queries[i][0], b = queries[i][1];

            v[a] += queries[i][2];
            v[b + 1] -= queries[i][2];
        }

        int curr_sum = 0;

        for (int i = 0; i < n; i++) {
            curr_sum += v[i];

            if (curr_sum < nums[i])
                return false;
        }
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = queries.size();
        int mx = *max_element(nums.begin(), nums.end());
        if(!mx) return 0;
        int lo = 0, hi = n - 1;

        int ans = -1;

        while (lo <= hi) {
            int mi = lo + (hi - lo) / 2;
            if (sol(mi, nums, queries)) {
                ans = mi + 1;
                hi = mi - 1;
            } else
                lo = mi + 1;
        }
        return ans;
    }
};