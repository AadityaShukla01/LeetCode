class Solution {
public:
    bool check(vector<vector<char>>& b, int r, int c) {
        int n = b.size();
        int m = b[0].size();
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (b[i][c] == b[r][c])
                cnt++;
        }

        if (cnt != 1)
            return false;

        cnt = 0;

        for (int i = 0; i < m; i++) {
            if (b[r][i] == b[r][c])
                cnt++;
        }

        if (cnt != 1)
            return false;

        cnt = 0;

        int newR = r / 3;
        int newC = c / 3;

        newR = newR * 3;
        newC = newC * 3;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (b[newR + i][newC + j] == b[r][c])
                    cnt++;
            }
        }

        return cnt == 1;
    }
    bool isValidSudoku(vector<vector<char>>& b) {
        int n = b.size();
        int m = b[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (b[i][j] != '.') {
                    if (!check(b, i, j)) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};