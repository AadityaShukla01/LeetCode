//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        
        queue<pair<int,pair<int,int>>>q;
        int n=grid.size();
        int m=grid[0].size();
        
        int delRow[]={-1,0,1,0};
        int delCol[]={0,1,0,-1};
        
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        q.push({0,{source.first,source.second}});
        
        dist[source.first][source.second]=0;
        while(q.empty()==false){
            int distance=q.front().first;
            int row=q.front().second.first;
            int col=q.front().second.second;
            q.pop();
            //for travelling all 4 directions
            for(int i=0;i<4;i++){
                int newRow=delRow[i]+row;
                int newCol=delCol[i]+col;
                
                //check conditon
                
                if(newRow>=0 && newRow<n && newCol>=0 &&newCol<m){
                    //check if current cell is 1
                    if(grid[newRow][newCol]==1){
                        //check if its min distance
                        if(distance+1<dist[newRow][newCol]){
                            dist[newRow][newCol]=distance+1;
                            q.push({dist[newRow][newCol],{newRow,newCol}});
                        }
                        if(newRow==destination.first && newCol==destination.second)
                            return dist[newRow][newCol];
                    }
                }
            }
        }
        if(source.first==destination.first && source.second==destination.second) 
        return 0; 
        return -1;
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

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends