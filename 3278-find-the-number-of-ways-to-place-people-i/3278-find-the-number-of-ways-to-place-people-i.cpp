class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int c = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int cx = points[i][0];
                int cy = points[i][1];
                int tx = points[j][0];
                int ty = points[j][1];
                if (cx > tx || cy < ty || i == j)
                    continue;
                bool flag = true;
                for (int k = 0; k < n; k++) {
                    if (i == k || k == j)
                        continue;
                    if (points[k][0] >= cx && points[k][0] <= tx &&
                        points[k][1] <= cy && points[k][1] >= ty)
                        flag = false;
                }
                if (flag)
                    c++;
            }
        }
        return c;
    }
};