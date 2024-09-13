class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();

        vector<int>prefXor(n + 1, 0);

        int xorr = 0;

        for(int i=1; i<=n; i++)
        {
            prefXor[i] = prefXor[i - 1] ^ arr[i - 1];
        }
        vector<int>ans(queries.size());
        int i = 0;
        for(auto q: queries)
        {
            int l = q[0], r = q[1];

            ans[i++] = prefXor[r + 1] ^ prefXor[l];
        }
        return ans;
    }
};