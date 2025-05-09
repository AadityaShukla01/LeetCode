class myComp{
    public:
        bool operator()(const vector<int>&a, const vector<int>&b){
            if(a[2] > b[2]) return true;
            return false;
        }
};

class Solution {
public:
    typedef vector<int> V;
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        priority_queue<V, vector<V>, myComp> q;
        q.push({0, 0, 0, 0});

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 0;

        while (q.empty() == false) {
            auto it = q.top();
            q.pop();
            int r = it[0], c = it[1], wt = it[2], prev = it[3];
            if(r == n - 1 && c == m - 1) return wt;
            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, 1, 0, -1};

            for (int i = 0; i < 4; i++) {
                int nr = dx[i] + r;
                int nc = dy[i] + c;

                if (nr >= 0 && nc >= 0 && nr < n && nc < m) {
                    int d = (prev == 1) ? 2 : 1;

                    if (wt >= moveTime[nr][nc]) {
                        if (dist[nr][nc] > wt + d) {
                            dist[nr][nc] = wt + d;
                            q.push({nr, nc, dist[nr][nc], !prev});
                        }
                    } else {
                        if (dist[nr][nc] > moveTime[nr][nc] + d) {
                            dist[nr][nc] = moveTime[nr][nc] + d;
                            q.push({nr, nc, dist[nr][nc], !prev});
                        }
                    }
                }
            }
        }
        return dist[n - 1][m - 1];
    }
};