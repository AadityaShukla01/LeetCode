//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>&vis, vector<pair<int,int>> &ans,int row0, int col0){
        vis[row][col] = 1;
        ans.push_back({row-row0,col-col0});
        
        int n = grid.size();
        int m = grid[0].size();
        
        int delRow[] ={-1,0,1,0};
        int delCol[]= {0,1,0,-1};
        
        for(int i=0;i<4;i++){
            
            int nRow=row + delRow[i];
            int nCol=col + delCol[i];
            
            if(nRow<n && nCol<m && nRow>=0 && nCol>=0){
                if(grid[nRow][nCol] == 1 && vis[nRow][nCol] == 0)
                    dfs(nRow,nCol,grid,vis,ans,row0,col0);
            }
        }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        set<vector<pair<int,int>>>s;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis[i][j] == 0 && grid[i][j] == 1)  {
                vector<pair<int,int>>ans;
                dfs(i,j,grid,vis,ans,i,j);
                s.insert(ans);
                }
            }
        }
        return s.size();
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
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends