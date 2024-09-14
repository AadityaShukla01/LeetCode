class Solution {
public:
    int dp[51][51][102];
    int sol(int r, int c, int n, int m, vector<vector<int>>& grid, int health){
        if(health <= 0) return false;
        if(r == n- 1 &&c==m-1){
            return health > 0;
        }
        if(dp[r][c][health] != -1) return dp[r][c][health];
        bool ans = false;
        int dx[]={-1, 0,1, 0};
        int dy[]={0,1,0,-1};

        for(int j=0; j<4; j++)
        {
            int nr = r + dx[j];
            int nc = c + dy[j];

            if(nr >= 0 && nc >=0&&nr<n &&nc<m){
                if(grid[nr][nc] == -1) continue;
                if(grid[nr][nc] == 1){
                    grid[nr][nc] = -1;
                    ans |= sol( nr, nc, n,  m, grid, health - 1) ;
                    grid[nr][nc] = 1;
                }
                else{
                    grid[nr][nc] = -1;
                      ans |= sol( nr, nc, n,  m, grid, health) ;
                      grid[nr][nc] = 0;
                }
            }
        }
        return  dp[r][c][health] = ans;
    }
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();   
        if(grid[0][0]) health--;
        memset(dp, -1, sizeof(dp));
        return sol( 0, 0, n, m, grid, health);
    }
};