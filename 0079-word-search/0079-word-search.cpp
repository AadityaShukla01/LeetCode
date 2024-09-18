class Solution {
public:
    bool sol(int r, int c, int ind, int n, int m, vector<vector<char>>& board, string &word)
    {
        if(r < 0 || c < 0 || r >= n || c >= m || board[r][c] != word[ind] || board[r][c] == '#')
            return false;

        if(ind == word.size() - 1) return true;
        char orig = board[r][c];
        board[r][c] = '#';
        bool op1 = sol(r + 1, c, ind + 1, n, m, board, word);
        bool op2 = sol(r - 1, c, ind + 1, n, m, board, word);
        bool op3 = sol(r, c + 1, ind + 1, n, m, board, word);
        bool op4 = sol(r, c - 1, ind + 1, n, m, board, word);
        board[r][c] = orig;

        return op1 || op2 || op3 || op4;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(sol(i, j, 0, n, m, board, word)) return true;
            }
        }    
        return false;
    }
};