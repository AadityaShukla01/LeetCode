class Solution {
public:
    int n, m;
    void sol(int r, int c, vector<vector<char>>& b, vector<vector<int>>&vis)
    {
        if(r < 0 || c < 0 || r >= n || c >= m || vis[r][c] || b[r][c] == 'X')
            return;

        vis[r][c] = 1;

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};


        for(int i=0; i<4; i++)
        {
            int nr = dx[i] + r;
            int nc = dy[i] + c;

            sol(nr, nc, b, vis);
        }
    }
    void solve(vector<vector<char>>& b) {
        this->n = b.size();
        this->m = b[0].size();

        vector<vector<int>>vis(n, vector<int>(m, 0));

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(i == 0 || j == 0 || j == m - 1 || i == n - 1){
                    if(b[i][j] == 'O' && !vis[i][j])
                    {
                        sol(i, j, b, vis);
                    }
                }
            }
        }

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(b[i][j] == 'O' && !vis[i][j]) b[i][j] = 'X';
            }
        }
        return;
    }
};