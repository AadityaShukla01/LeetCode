class Solution {
public:
    double dist(int x1, int x2, int y1, int y2)
    {
        double d = 1.0*(x1 - x2)*(x1 - x2) + 1.0*(y1 - y2) * (y1 - y2);


        return sqrt(d);
    }
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = points.size();

        long long cnt = 0;

        for(int i=0; i<n; i++)
        {
            int f_x = points[i][0];
            int f_y = points[i][1];
            map<double, int>mp;
            for(int j=0; j<n; j++)
            {
                if(i == j) continue;
                int s_x = points[j][0];
                int s_y = points[j][1];

                double d = dist(s_x , f_x, f_y, s_y);

                mp[d]++;
            }

            for(auto it: mp){
                // cout << i << " " << it.first << " " << it.second << "\n";
                int f = it.second;
                cnt += f * (f - 1);
            }
        }
        return cnt;
    }
};