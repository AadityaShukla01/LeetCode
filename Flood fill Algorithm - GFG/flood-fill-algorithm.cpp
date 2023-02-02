//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>&ans,vector<vector<int>>& image, int color,int iniColor,int ro[],int co[]){
        ans[i][j]=color;

        for(int l=0;l<4;l++){
            int nrow=i+ro[l];
            int ncol=j+co[l];

            if(nrow>=0 && nrow<image.size() && ncol>=0 && ncol<image[0].size()){
                if(image[nrow][ncol]==iniColor && ans[nrow][ncol]!=color)
                dfs(nrow,ncol,ans,image,color,iniColor,ro,co);
            }
        }
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        int ro[]={-1,0,1,0};
        int co[]={0,1,0,-1};
        int iniColor=image[sr][sc];
        vector<vector<int>>ans=image;
        dfs(sr,sc,ans,image,color,iniColor,ro,co);
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends