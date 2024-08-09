class Solution {
public:
    int orangesRotting(vector<vector<int>>& g) {
        int n = g.size();
        int m = g[0].size();

        queue<vector<int>>q;

        vector<vector<int>>vis(n, vector<int>(m, -1));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(g[i][j] == 2){
                    q.push({i, j, 0});
                    vis[i][j] = 0;
                }
            }
        }

        while(q.empty() == false){
            auto tp = q.front();
            q.pop();

            int r = tp[0];
            int c = tp[1];
            int time = tp[2];

            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, 1, 0, -1};

            for(int j=0; j<4; j++){
                int nr = dx[j] + r;
                int nc = dy[j] + c;

                if(nr>=0 && nr<n && nc>=0 && nc < m){
                    if(vis[nr][nc] == -1 && g[nr][nc]){
                        vis[nr][nc] = time + 1;
                        q.push({nr, nc, time + 1});
                    }
                }
            }
        }

        int ans = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis[i][j] == -1 && g[i][j] == 1) return -1;
                if(vis[i][j] == -1) continue;
                ans = max(ans, vis[i][j]);
            }
        }
        return ans;
    }
};