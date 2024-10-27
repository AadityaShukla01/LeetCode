class Solution {
public:
    int countSquares(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int cnt = 0;

        vector<vector<int>>ans(n, vector<int>(m, 0));

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(mat[i][j] == 1)
                {
                    if(i == 0 || j == 0 || i == n - 1 || j == m - 1)
                        ans[i][j] = 1;
                }
            }
        }

        for(int i=1; i<n; i++)
        {
            for(int j=1; j<m; j++)
            {
                if(mat[i][j] == 1)
                    ans[i][j] = 1 + min({ans[i - 1][j], ans[i][j - 1], ans[i - 1][j - 1]});
            }
        }

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                cnt += ans[i][j];
            }
        }
        return cnt;
    }
};