class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();

        queue<vector<int>>q;
        vector<vector<int>>dist(n, vector<int>(m, 1e9));

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(mat[i][j] == 1) 
                {
                    q.push({i, j, 0});
                    dist[i][j] = 0;
                }
            }
        }

        while(q.empty() == false)
        {
            auto it = q.front();
            q.pop();

            int r = it[0], c = it[1], wt = it[2];

            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, 1, 0, -1};

            for(int i=0; i<4; i++)
            {
                int nr = r + dx[i];
                int nc = c + dy[i];

                if(nr >= 0 && nc >= 0 && nr < n && nc < m)
                {
                    if(dist[nr][nc] > wt + 1)
                    {
                        dist[nr][nc] = wt + 1;
                        q.push({nr, nc, wt + 1});
                    }
                }  
            }
        }
        
        return dist;
    }
};