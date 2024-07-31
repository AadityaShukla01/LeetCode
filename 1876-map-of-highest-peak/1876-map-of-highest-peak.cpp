class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size();
        int m = isWater[0].size();
        vector<vector<int>>vis(n, vector<int>(m, 0));
        queue<vector<int>>q;
        vector<vector<int>>dist(n, vector<int>(m, 1e9));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(isWater[i][j] == 1){
                    q.push({i, j, 0});
                    vis[i][j] = 1;
                    dist[i][j] = 0;
                }
            }
        }
        while(q.empty() == false){
            int r = q.front()[0];
            int c = q.front()[1];
            int num = q.front()[2];

            q.pop();    
            vis[r][c] = 1;
            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, 1, 0, -1};

            for(int i=0; i<4; i++){
                int nr = dx[i] + r;
                int nc = dy[i] + c;

                if(nr >= 0 && nr < n && nc < m && nc >= 0 && !vis[nr][nc] && dist[nr][nc] > num + 1){
                    dist[nr][nc] = min( dist[nr][nc], num + 1);
                    q.push({nr, nc, num + 1});
                }
            }
        }

        return dist;
    }
};