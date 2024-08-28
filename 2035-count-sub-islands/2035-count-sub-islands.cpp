class Solution {
public:
    void sol(int i, int j, int n, int m, vector<vector<int>>& mat1, vector<vector<int>>& mat2, bool &res){

        if(mat1[i][j] != 1 && mat2[i][j] == 1) res = false;
        
        if(mat2[i][j] == 0) return;

        mat2[i][j] = 0;

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        for(int l=0; l<4; l++){
            int nr = delRow[l] + i;
            int nc = delCol[l] + j;

            if(nr>=0 && nc>=0 && nr < n && nc < m){
                sol(nr, nc, n, m, mat1, mat2, res);
            }
            // else return;
        }
    }
    int countSubIslands(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        int n = mat1.size();
        int m = mat1[0].size();

        int count = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat2[i][j] == 1 && mat1[i][j] == 1){
                    bool res = true;
                    sol(i, j, n, m, mat1, mat2, res);
                    count += (res);
                }
            }
        }
        return count;
    }
};