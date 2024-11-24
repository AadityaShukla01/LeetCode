class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& mat) {
        long long sum = 0;
        int n = mat.size(), m = mat[0].size();
        int cnt = 0;
        int mn = INT_MAX;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(mat[i][j] < 0) cnt++;
                mn = min(mn, abs(mat[i][j]));
                sum += abs(mat[i][j]);
            }
        }
        if(cnt % 2) return sum -= 2*mn;
        return sum;
    }
};