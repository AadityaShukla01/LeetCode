class Solution {
public:
    bool sol(vector<vector<int>>& g, int r, int c) {
        
        int ld = g[r][c] + g[r + 1][c + 1] + g[r + 2][c + 2];
        int rd = g[r][c + 2] + g[r + 1][c + 1] + g[r + 2][c];
        
        set<int>s;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(g[r + i][c + j] >= 1 && g[r + i][c + j] <= 9)
                s.insert(g[r + i][c + j]);
            }
        }
        if(s.size() != 9) return false;
        if (ld != 15 || rd != 15)
            return false;
        int cr = 0;
        for (int i = 0; i < 3; i++) {
            int sum = 0;
            for (int j = 0; j < 3; j++) {
                sum += g[r + i][c + j];
            }
            if (sum == 15)
                cr++;
        }
        if (cr != 3)
            return false;
        int cc = 0;
        for (int i = 0; i < 3; i++) {
            int sum = 0;
            for (int j = 0; j < 3; j++) {
                sum += g[r + j][c + i];
            }
            if (sum == 15)
                cc++;
        }
        if (cc != 3)
            return false;

        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& g) {
        int n = g.size();
        int m = g[0].size();

        int count = 0;

        for (int i = 0; i < n - 2; i++) {
            for (int j = 0; j < m - 2; j++) {
                count += sol(g, i, j);
            }
        }
        return count;
    }
};