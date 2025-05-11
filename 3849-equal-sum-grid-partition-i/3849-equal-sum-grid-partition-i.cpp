class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();
        vector<long long> rowSum(n, 0), colSum(m, 0);
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                sum += g[i][j];

            rowSum[i] = sum;
        }

        for (int i = 0; i < n; i++) {
            if (rowSum[i] == rowSum[n - 1] - rowSum[i])
                return true;
        }

        sum = 0;

        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++)
                sum += g[i][j];

            colSum[j] = sum;
        }

        for (int i = 0; i < m; i++) {
            if (colSum[i] == colSum[m - 1] - colSum[i])
                return true;
        }
        return false;
    }
};