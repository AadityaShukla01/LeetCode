class Solution {
public:
    long long gridGame(vector<vector<int>>& g) {
        int n = g[0].size();
        vector<long long>row2(n, 0);
        long long sum = 0;
        long long row1 = 0;
        for(int i=0; i<n; i++) row1 += g[0][i];
        for(int i=0; i<n; i++)
        {
            sum += g[1][i];
            row2[i] = sum;
        }
        long long mn = 1e15;
        sum = 0;
        for(int i=0; i<n; i++)
        {
            sum += g[0][i];
            long long case1 = row1 - sum;
            long long case2 = (i > 0) ? row2[i - 1] : 0;

            mn = min(mn, max(case1, case2));
        }

        return mn;
    }
};