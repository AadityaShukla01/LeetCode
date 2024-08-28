class Solution {
public:
    void sol(int r, int c, int n, int m, vector<vector<int>>& g1,
             vector<vector<int>>& g2, vector<vector<int>>& vis, bool& ans) {

        if (r < 0 || c < 0 || r >= n || c >= m)
            return;
        if(g2[r][c] == 0) return;

        if (vis[r][c])
            return;

        vis[r][c] = 1;

        if (g1[r][c] == 0) {
            ans = false;
        }

        sol(r + 1, c, n, m, g1, g2, vis, ans);
        sol(r - 1, c, n, m, g1, g2, vis, ans);
        sol(r, c - 1, n, m, g1, g2, vis, ans);
        sol(r, c + 1, n, m, g1, g2, vis, ans);

    }
    int countSubIslands(vector<vector<int>>& g1, vector<vector<int>>& g2) {
        int n = g1.size(), m = g1[0].size();
        int count = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (g2[i][j] && !vis[i][j]) {
                    bool ans = true;
                    sol(i, j, n, m, g1, g2, vis, ans);
                    count += ans;
                }
            }
        }
        return count;
    }
};