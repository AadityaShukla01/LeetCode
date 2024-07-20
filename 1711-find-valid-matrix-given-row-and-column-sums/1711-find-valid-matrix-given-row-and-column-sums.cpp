class Solution {
public:
    bool condition(vector<int>& rowSum, vector<int>& colSum){
        for(int i=0; i<rowSum.size(); i++){
            if(rowSum[i]) return false;
        }
        for(int i=0; i<colSum.size(); i++){
            if(colSum[i]) return false;
        }
        return true;
    }
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n = rowSum.size();
        int m = colSum.size();
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        while (!condition(rowSum, colSum)) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    int r = rowSum[i];
                    int c = colSum[j];
                    matrix[i][j] += min(r, c);
                    rowSum[i] -= min(r, c);
                    colSum[j] -= min(r, c);
                }
            }
        }
        return matrix;
    }
};