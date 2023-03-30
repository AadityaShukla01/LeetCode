class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>matrix(n,vector<int>(n,INT_MAX));

        for(int i=0;i<n;i++){
            matrix[i][i]=0;
        }
        for(auto it:edges){
            int a=it[0];
            int b=it[1];
            int c=it[2];

            matrix[a][b]=c;
            matrix[b][a]=c;
        }
        for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                    if(matrix[i][k]==INT_MAX || matrix[k][j]==INT_MAX) continue;
                    matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);
                }
            }
        }
        int temp=n;
        int count=0;
        for(int i=0;i<n;i++){
            int q=0;
            for(int j=0;j<n;j++){
                if(matrix[i][j]<=distanceThreshold) q++;
            }
            if(temp>=q){
                temp=q;
                count=i;
            }
        }
        return count;
    }
};