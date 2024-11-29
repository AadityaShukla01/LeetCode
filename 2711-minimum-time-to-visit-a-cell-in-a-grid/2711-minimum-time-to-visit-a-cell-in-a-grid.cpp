class Solution {
public:
    int minimumTime(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();

        vector<vector<int>>dist(n, vector<int>(m, 1e9));

        if(g[0][0]) return -1;

        if(g[0][1] > 1 && g[1][0] > 1) return -1;

        dist[0][0] = 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>q;
        q.push({0, 0, 0});

        while(q.empty() == false)
        {
            int curr = q.top()[0];
            int r = q.top()[1];
            int c = q.top()[2];

            q.pop();

            if(r == n - 1 && c == m - 1)
                return curr;

            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, 1, 0, -1};

            for(int i=0; i<4; i++)
            {
                int nr = r + dx[i];
                int nc = c + dy[i];

                if(nr >= 0 && nr < n && nc >= 0 && nc < m)
                {
                    if(g[nr][nc] <= curr + 1 && dist[nr][nc] > curr + 1)
                    {
                        dist[nr][nc] = curr + 1;
                        q.push({dist[nr][nc], nr, nc});
                    }
                    else if(g[nr][nc] > curr + 1)
                    {
                        int diff = g[nr][nc] - curr;
                        if(diff % 2 == 0)
                        {
                            if(dist[nr][nc] > g[nr][nc] + 1)
                            {
                                dist[nr][nc] = g[nr][nc] + 1;
                                q.push({dist[nr][nc], nr, nc});
                            }
                        }
                        else{
                            if(dist[nr][nc] > g[nr][nc])
                            {
                                dist[nr][nc] = g[nr][nc];
                                q.push({dist[nr][nc], nr, nc});
                            }
                        }
                    }
                }
            }
        }
        // for(int i=0; i<n; i++)
        // {
        //     for(int j=0; j<m; j++)
        //         cout << dist[i][j] << " ";

        //     cout << "\n";
        // }
        return (dist[n - 1][m - 1] == 1e9) ? -1 : dist[n - 1][m - 1];
    }
};