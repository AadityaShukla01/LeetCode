class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n = box.size(), m = box[0].size();
        vector<vector<char>>ans(m, vector<char>(n));
        vector<vector<int>>vis(n, vector<int>(m, 0));

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(box[i][j] == '#')
                {
                    int ti = i, tj = j;
                    int cnt = 0;
                    while(tj < m && box[i][tj] != '*' && !vis[ti][tj])
                    {
                        if(box[ti][tj] == '#'){
                            cnt++;
                            box[ti][tj] = '.';
                        }
                        tj++;
                    }
                    tj--;
                    while(cnt--)
                    {
                        vis[ti][tj] = 1;
                        box[ti][tj] = '#';
                        tj--;
                    }
                }
            }
        }

        for(int i=0; i<n; i++)
        {
            // reverse(box[i].begin(), box[i].end());
            for(int j=0; j<m; j++)
            {
                ans[j][i] = box[i][j]; 
            }
            // reverse(ans[i].begin(), ans[i].end());
        }
        for(int i=0; i<m; i++)
        {
            reverse(ans[i].begin(), ans[i].end());
        }
        return ans;
    }
};