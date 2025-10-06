class Solution {
public:
    int vis[1001][1001];
    // time complexity will be O(n*n*logn)
    // logn for binary search and n*n for dfs
    // questions can also be said as path from 0,0 to n-1 with smallest maximum
    //  smallest , maximum->binary search
    bool sol(int r, int c, int n, int m, vector<vector<int>>& grid, int t) {
        if (r == n - 1 && c == m - 1)
            return true;

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        vis[r][c] = 1;

        for (int i = 0; i < 4; i++) {
            int nr = dx[i] + r;
            int nc = dy[i] + c;

            if (nr >= 0 && nc >= 0 && nr < n && nc < m) {
                if (grid[nr][nc] <= t && vis[nr][nc] == 0) {
                    if (sol(nr, nc, n, m, grid, t))
                        return true;
                }
            }
        }
        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int lo = 0;
        int hi = n * m - 1;
        int ans = 0;
        while (lo <= hi) {
            int mi = (lo + hi) / 2;
            memset(vis, 0, sizeof(vis));
            if (sol(0, 0, n, m, grid, mi) && grid[0][0] <= mi) {
                ans = mi;
                hi = mi - 1;
            } 
            else {
                lo = mi + 1;
            }
        }
        return ans;
    }
};