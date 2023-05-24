//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int n =grid.size();
        int m =grid[0].size();
        
        queue<pair<int,int>>q;
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[0][j] == 1){
                    q.push({0,j});
                    vis[0][j] = 1;
                }
                if(grid[i][0] == 1){
                    q.push({i,0});
                    vis[i][0] = 1;
                }
                if(grid[n-1][j] == 1){
                    q.push({n-1,j});
                    vis[n-1][j] = 1;
                }
                if(grid[i][m-1] == 1){
                    q.push({i,m-1});
                    vis[i][m-1] = 1;
                }
            }
        }
        
        while(q.empty()==false){
            auto it =q.front();
            int row=it.first;
            int col=it.second;
            q.pop();
            
            int delRow[] ={-1,0,1,0};
            int delCol[] ={0,1,0,-1};
            
            for(int i=0;i<4;i++){
                int nRow=row+delRow[i];
                int nCol=col+delCol[i];
                
                
                if(nRow<n && nCol<m && nRow>=0 && nCol>=0){
                    if(grid[nRow][nCol] == 1 && vis[nRow][nCol] == 0){
                        q.push({nRow,nCol});
                        vis[nRow][nCol] =1;
                    }
                }
            }
        }
        int c=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1 && vis[i][j] == 0)
                    c++;
            }
        }
        return c;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends