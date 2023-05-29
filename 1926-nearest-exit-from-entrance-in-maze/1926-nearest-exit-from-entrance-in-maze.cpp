class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();

        vector<vector<int>>dist(n,vector<int>(m,1e9));
        queue<vector<int>> q;
        q.push({0,entrance[0],entrance[1]});
        dist[entrance[0]][entrance[1]] = 0;

        while(q.empty() == false){
            int step = q.front()[0];
            int row = q.front()[1];
            int col = q.front()[2];
            q.pop();
            
            int delRow[]={-1,0,1,0};
            int delCol[]={0,1,0,-1};

            for(int i=0;i<4;i++){
                int nRow=delRow[i]+row;
                int nCol=delCol[i]+col;
                if(nRow<n && nRow>=0 && nCol<m && nCol>=0 && maze[nRow][nCol]=='.'){
                    if(dist[nRow][nCol] > 1+step){
                        dist[nRow][nCol]=1+step;
                        q.push({step+1,nRow,nCol});
                    }
                }
            }
        }
        int ans = INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0 || i==n-1) && maze[i][j]=='.'  && dist[i][j] != 0){
                    ans=min(ans,dist[i][j]);
                }
                if((j==0 || j==m-1) && maze[i][j]=='.' && dist[i][j] != 0){
                    ans=min(ans,dist[i][j]);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<dist[i][j]<<" ";
            }
            cout<<endl;
        }
        if(ans==INT_MAX || ans==1e9)
            return -1;
        return ans;
    }
};