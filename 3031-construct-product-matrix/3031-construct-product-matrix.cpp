class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                ans.push_back(g[i][j]);
        }

        vector<int> res(n * m, 1);

        long long pro = 1;
        for (int i = 0; i < ans.size(); i++) {
            res[i] = res[i] * pro;
            res[i] %= 12345;
            pro = pro * ans[i];
            pro = pro % 12345;
        }
        pro = 1;
        for (int i = ans.size() - 1; i >= 0; i--) {
            res[i] = res[i] * pro;
            res[i] %= 12345;
            pro = pro * ans[i];
            pro = pro % 12345;
        }

        for (int i = 0; i < n * m; i++) {
            g[i / m][i % m] = res[i];
        }
        return g;
    }
};