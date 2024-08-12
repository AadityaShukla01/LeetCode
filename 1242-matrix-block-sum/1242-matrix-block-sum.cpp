class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();

        vector<vector<int>>psum(n + 1, vector<int>(m + 1, 0));

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                psum[i][j] = psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1] + mat[i - 1][j - 1];
            }
        }
       
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int start_r = max(1, i + 1 - k);
                int start_c = max(1, j + 1 - k);
                int en_r = min(n, i + 1 + k);
                int en_c = min(m, j + 1 + k);

                mat[i][j] = psum[en_r][en_c] - psum[en_r][start_c - 1] - psum[start_r - 1][en_c] + psum[start_r - 1][start_c - 1];
            }
        }

        return mat;
    }
};