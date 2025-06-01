class Solution {
public:
    int sol(vector<vector<int>>& g, int r, int c, int k) {
        set<int> set;
        for (int i = r; i < r + k; i++) {
            for (int j = c; j < c + k; j++) {
                set.insert(g[i][j]);
            }
        }

        if(set.size() == 1) return 0;

        int prev = -1e9, mn = 1e9;
        for (auto el : set) {
            mn = min(mn, el - prev);
            prev = el;
        }
        return mn;
    }
    vector<vector<int>> minAbsDiff(vector<vector<int>>& g, int k) {
        int n = g.size(), m = g[0].size();

        vector<vector<int>> ans(n - k + 1, vector<int>(m - k + 1));

        for (int i = 0; i < n - k + 1; i++) {
            for (int j = 0; j < m - k + 1; j++) {
                ans[i][j] = sol(g, i, j, k);
            }
        }
        return ans;
    }
};