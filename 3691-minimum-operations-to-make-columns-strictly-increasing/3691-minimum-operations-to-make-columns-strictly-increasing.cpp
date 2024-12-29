class Solution {
public:
    int minimumOperations(vector<vector<int>>& g) {
        int ops = 0;
        int n = g.size(), m = g[0].size();

        for(int i=0; i<m; i++)
        {
            int pre = g[0][i];
            for(int j=1; j<n; j++)
            {
                ops += max(0, (pre + 1) - g[j][i]);
                pre = max(g[j][i], pre + 1);
            }
        }
        return ops;
    }
};