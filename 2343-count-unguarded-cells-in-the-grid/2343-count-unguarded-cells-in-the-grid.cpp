class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        int len1 = guards.size();
        int len2 = walls.size();

        vector<vector<int>>v(m, vector<int>(n, 0));

        for(auto it: walls)
        {
            v[it[0]][it[1]] = 3;
        }

        queue<vector<int>>q;

        for(auto it: guards)
        {
            q.push({it[0], it[1], 0});
        }

        while(q.empty() == false)
        {
            auto it = q.front();
            int r = it[0], c = it[1];
            int dir = it[2];

            q.pop();

            if(r >= m || r < 0 || c < 0 || c >= n)
                continue;

            if(dir && v[r][c] == dir) continue;
            if(v[r][c] == 4) continue;
            if(v[r][c] == 3) continue;

            if(dir == 0){
                v[r][c] = 4;
            }
            else v[r][c] = dir;

            if(dir == 0)
            {
                q.push({r + 1, c, 1});
                q.push({r - 1, c, -1});
                q.push({r, c + 1, 2});
                q.push({r, c - 1, -2});
            }
            else if(dir == 1)
            {
                q.push({r + 1, c, 1});
            }
            else if(dir == -1)
            {
                q.push({r - 1, c, -1});
            }
            else if(dir == 2)
            {
                q.push({r, c + 1, 2});
            }
            else if(dir == -2)
            {
                q.push({r, c - 1, -2});
            }
        }

        int cnt = 0;

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(v[i][j] == 0) {
                    cout << i << " " << j <<"\n";
                    cnt++;
                }
            }
        }
        return cnt;
    }
};