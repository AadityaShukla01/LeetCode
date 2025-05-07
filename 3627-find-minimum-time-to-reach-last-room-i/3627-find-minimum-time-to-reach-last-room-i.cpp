class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        queue<vector<int>> q;
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 0;
        q.push({0, 0, 0});

        while (q.empty() == false) {
            auto it = q.front();
            q.pop();
            int r = it[0], c = it[1], wt = it[2];

            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, 1, 0, -1};

            for (int i = 0; i < 4; i++) {
                int nr = dx[i] + r;
                int nc = dy[i] + c;

                if (nr >= 0 && nc >= 0 && nr < n && nc < m) {
                    if (wt >= moveTime[nr][nc]) {
                        if (dist[nr][nc] > wt + 1){
                            dist[nr][nc] = wt + 1;
                            q.push({nr, nc, wt + 1});
                        }
                    } else {
                        if (dist[nr][nc] > moveTime[nr][nc] + 1){
                            dist[nr][nc] = moveTime[nr][nc] + 1;
                            q.push({nr, nc, moveTime[nr][nc] + 1});
                        }
                    }
                }
            }
        }
        return dist[n - 1][m - 1];
    }
};