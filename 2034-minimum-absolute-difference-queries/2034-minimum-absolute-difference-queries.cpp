class Solution {
public:
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        map<int, vector<int>> map;
        for (int i = -1; i < n; i++) {
            map[i].resize(101);
        }
        map[0][nums[0]]++;

        for (int i = 1; i < n; i++) {
            map[i] = map[i - 1];
            map[i][nums[i]]++;
        }
        vector<int> ans(queries.size());
        int j = 0;
        for (auto q : queries) {
            int l = q[0];
            int r = q[1];

            vector<int> ryt = map[r];
            vector<int> left = map[l - 1];
            int mn = 1e9;
            for (int i = 1; i < 101; i++) {
                ryt[i] = ryt[i] - left[i];
            }
            int pre = -1;
            for (int i = 1; i < 101; i++) {
                if (ryt[i] > 0 && pre == -1)
                    pre = i;
                else if (ryt[i] > 0) {
                    mn = min(mn, i - pre);
                    pre = i;
                }
            }
            if(mn == 1e9) mn = -1;
            ans[j++] = mn;
        }
        return ans;
    }
};