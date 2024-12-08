class Solution {
public:
    int sol(vector<vector<int>>& vis, int x1, int x2, int x3, int x4, int y1,
            int y2, int y3, int y4) {

        int mnx = min({x1, x3, x2, x4});
        int mny = min({y1, y3, y2, y4});

        int mxx = max({x1, x3, x2, x4});
        int mxy = max({y1, y3, y2, y4});

        int area = abs(mnx - mxx) * abs(mxy - mny);

        vis[x1][y1] = 0;
        vis[x2][y2] = 0;
        vis[x3][y3] = 0;
        vis[x4][y4] = 0;

        bool f = 1;

        for (int i = mnx; i <= mxx; i++) {
            for (int j = mny; j <= mxy; j++) {
                
                if (vis[i][j])
                    f = 0;
            }
        }
        vis[x1][y1] = 1;
        vis[x2][y2] = 1;
        vis[x3][y3] = 1;
        vis[x4][y4] = 1;


        return f ? area : -1;
    }
    int maxRectangleArea(vector<vector<int>>& points) {
        int n = points.size();

        vector<vector<int>> vis(101, vector<int>(101, 0));

        int area = -1;

        for (auto p : points) {
            int xc = p[0], yc = p[1];

            vis[xc][yc] = 1;
        }

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int l = j + 1; l < n; l++) {
                    for (int k = l + 1; k < n; k++) {
                        int x1 = points[i][0];
                        int x2 = points[j][0];
                        int x3 = points[l][0];
                        int x4 = points[k][0];

                        int y1 = points[i][1];
                        int y2 = points[j][1];
                        int y3 = points[l][1];
                        int y4 = points[k][1];

                        cout << i << " " << j << " " << l << " " << k << "\n";
                        map<int, int> s1;
                        map<int, int> s2;

                        s1[x1]++;
                        s1[x2]++;
                        s1[x3]++;
                        s1[x4]++;

                        s2[y1]++;
                        s2[y2]++;
                        s2[y3]++;
                        s2[y4]++;

                        if (s1.size() != 2 || s2.size() != 2)
                            continue;

                        int mnx = min({x1, x3, x2, x4});
                        int mxx = max({x1, x3, x2, x4});

                        int mny = min({y1, y3, y2, y4});
                        int mxy = max({y1, y3, y2, y4});

                        if(s1[mnx] != s1[mxx]) continue;
                        if(s2[mny] != s2[mxy]) continue;

                        area =
                            max(area, sol(vis, x1, x2, x3, x4, y1, y2, y3, y4));
                    }
                }
            }
        }
        return area;
    }
};