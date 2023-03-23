class Solution {
public:
    bool isValid(int rsize,int colsize,int r,int c){
        if(r>=0 && r<rsize && c>=0  && c<colsize) return true;

        return false;
    }
    int sol(vector<vector<int>>& grid,int r,int c){
        if(r==grid.size()) return c;

        if(isValid(grid.size(),grid[0].size(),r,c)){
            if(grid[r][c]==1){
                if(isValid(grid.size(),grid[0].size(),r,c+1) && grid[r][c+1]==1)
                    return sol(grid,r+1,c+1);
            }
            else{
                if(isValid(grid.size(),grid[0].size(),r,c-1) && grid[r][c-1]==-1)
                    return sol(grid,r+1,c-1);
            }
        }
        return -1;

    }
    vector<int> findBall(vector<vector<int>>& grid) {
        //adjacent elements should be same
        int n=grid[0].size();
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            ans[i]=sol(grid,0,i);
        }
        return ans;
    }
};