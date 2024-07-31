class Solution {
public:
    void sol(int r, int c, int n, int m, vector<vector<int>>& g,
             vector<vector<int>>& vis) {
        vis[r][c] = 1;

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int nr = dx[i] + r;
            int nc = dy[i] + c;

            if (nr >= 0 && nr < n && nc >= 0 && nc < m && g[nr][nc] == 1 && !vis[nr][nc]) {
                sol(nr, nc, n, m, g, vis);
            }
        }
    }
    int shortestBridge(vector<vector<int>>& g) {
        int n = g.size();
        int m = g[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        bool f = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (g[i][j] == 1 && !f) {
                    sol(i, j, n, m, g, vis);
                    f = 1;
                }
            }
        }
        queue<vector<int>> q;
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j] == 1 && g[i][j] == 1) {
                    q.push({i, j, 0});
                    dist[i][j] = 0;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << vis[i][j] << " ";
            }
            cout << "\n";
         }
        while (q.empty() == false) {
            auto it = q.front();
            int r = it[0];
            int c = it[1];
            int steps = it[2];
            q.pop();

            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, 1, 0, -1};

            for (int j = 0; j < 4; j++) {
                int nr = dx[j] + r;
                int nc = dy[j] + c;

                if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                    if (g[nr][nc] == 0 && dist[nr][nc] > steps + 1) {
                        dist[nr][nc] = steps + 1;
                        q.push({nr, nc, steps + 1});
                    }
                    else if(g[nr][nc] == 1 && dist[nr][nc] > steps){
                        dist[nr][nc] = min(dist[nr][nc], steps);
                    }
                }
            }
        }
        int ans = 1e9;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(dist[i][j] && g[i][j]){
                    ans = min(ans, dist[i][j]);
                }
            }
        }
        return ans;
    }
};