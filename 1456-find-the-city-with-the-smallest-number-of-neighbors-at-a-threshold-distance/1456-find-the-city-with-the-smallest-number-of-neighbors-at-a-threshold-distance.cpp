class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, 1e9));

        for (int i = 0; i < n; i++) {
            dist[i][i] = 0;
        }

        for (auto e : edges) {
            int a = e[0];
            int b = e[1];
            int wt = e[2];

            dist[a][b] = wt;
            dist[b][a] = wt;
        }

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
                }
            }
        }

        int city = -1;
        int maxCount = 1e9;

        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (dist[i][j] <= distanceThreshold && i != j)
                    cnt++;
            }
            if (cnt <= maxCount) {
                maxCount = min(maxCount, cnt);
                city = i;
            }
        }
        return city;
    }
};