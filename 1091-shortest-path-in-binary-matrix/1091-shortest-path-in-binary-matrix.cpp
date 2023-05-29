class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[0][0] = 0;

        queue<vector<int>> q;
        q.push({0,0,0});
        //distance row col

        if(grid[0][0] != 0)
            return -1;

        while(q.empty()==false){
            int distance = q.front()[0];
            int row = q.front()[1];
            int col = q.front()[2];
            q.pop();
        // help in travelling 4 directions only
            // int delCol[] = {-1,0,1,0};
            // int delRow[] = {0,1,0,-1};

            for(int i =-1; i<=1; i++){
                
                for(int j= -1; j<=1; j++){
                    int nRow = i + row;
                    int nCol = j + col;

                    if(nRow<n && nRow>=0 && nCol>=0 && nCol<m && grid[nRow][nCol] == 0){
                        if(dist[nRow][nCol] > distance + 1){
                            q.push({distance+1, nRow, nCol});
                            dist[nRow][nCol] = distance + 1;
                        }
                    }
                }
            }
        }
        if(dist[n-1][m-1] == 1e9)
            return -1;

        return dist[n-1][m-1]+1;
    }
};