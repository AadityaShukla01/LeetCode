class Solution {
public:
    int orangesRotting(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();
        vector<vector<int>>dist(n, vector<int>(m, 1e9));
        queue<vector<int>>q;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++){
                if(g[i][j] == 2){
                    dist[i][j] = 0;
                    q.push({i, j, 0});
                }
            }
        }

        while(q.empty() == false){
            auto it = q.front();
            int r = it[0], c = it[1], steps = it[2];
            q.pop();
            
            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, 1, 0, -1};

            for(int i=0; i<4; i++){
                int nr = r + dx[i], nc = c + dy[i];

                if(nr >= 0 && nr < n && nc >= 0 && nc < m){
                    if(g[nr][nc] == 1){
                        if(dist[nr][nc] > dist[r][c] + 1){
                            dist[nr][nc] = dist[r][c] + 1;
                            q.push({nr, nc, steps + 1});
                        }
                    }
                }
            }
        }
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++){
                if(g[i][j] == 1){
                    ans = max(ans, dist[i][j]);
                }
            }
        }
        if(ans == 1e9) return -1;
        return ans;
    }
};