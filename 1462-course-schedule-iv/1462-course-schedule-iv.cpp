class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int n = numCourses;
        vector<int>adj[n];

        vector<vector<int>>mat(n,vector<int>(n,1e9));
        for(auto it : prerequisites){
            mat[it[0]][it[1]] = 1;
        }

        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);
                }
            }
        }
        vector<bool>ans;
        for(auto it : queries){
            int a =it[0];
            int b= it[1];
            if(mat[a][b] != 1e9){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};