class Solution {
public:
    // took help!
    int maxEqualRowsAfterFlips(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int mx = 0;
        for(int i=0; i<n; i++)
        {   
            int cnt = 0;
            vector<int>v1 = mat[i];

            vector<int>v3(m);

            for(int j=0; j<m; j++)
                v3[j] = 1 - v1[j];

            for(int j=0; j<n; j++)
            {
                vector<int>v2 = mat[j];
                if(v2 == v1 || v2 == v3)
                    cnt++;
            }
            mx = max(mx, cnt);
        }
        return mx;
    }
};