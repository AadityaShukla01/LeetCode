class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        int cnt = 0;
        map<int, pair<int, int>> x, y;

        for (auto b : buildings) {
            if(x[b[0]].first == 0)
                x[b[0]].first = b[1];
            else 
                x[b[0]].first = min(x[b[0]].first, b[1]);

            x[b[0]].second = max(x[b[0]].second, b[1]);

            if(y[b[1]].first == 0)
                y[b[1]].first = b[0];
            else 
                y[b[1]].first = min(y[b[1]].first, b[0]);

            y[b[1]].second = max(y[b[1]].second, b[0]);
        }

        for (auto b : buildings) {
            int xc = b[0];
            int yc = b[1];

            if(yc != x[xc].first && yc != x[xc].second){
                if(xc != y[yc].first && xc != y[yc].second) {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};