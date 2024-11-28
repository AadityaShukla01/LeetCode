class Solution {
public:
    int minimumObstacles(vector<vector<int>>& g) {

        int n = g.size();
        int m = g[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = (g[0][0]) ? 1 : 0;
        queue<vector<int>> q;
        q.push({0, 0});

        while (q.empty() == false) {
            auto it = q.front();
            q.pop();

            int r = it[0];
            int c = it[1];

            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, 1, 0, -1};

            for (int i = 0; i < 4; i++) {
                int nr = dx[i] + r;
                int nc = dy[i] + c;

                if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                    if (g[nr][nc] == 1) {
                        if (dist[nr][nc] > dist[r][c] + 1) {
                            dist[nr][nc] = dist[r][c] + 1;
                            q.push({nr, nc});
                        }
                    } else {
                        if (dist[nr][nc] > dist[r][c]) {
                            dist[nr][nc] = dist[r][c];
                            q.push({nr, nc});
                        }
                    }
                }
            }
        }

        return dist[n - 1][m - 1];
    }
};