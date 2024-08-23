class Solution {
public:
    bool check(int r, int c, int n, vector<vector<int>>&b){
        int j = c;

        while(j >= 0){
            if(b[r][j]) return false;
            j--;
        }

        j = c;
        int i = r;

        while(j >= 0 && i >= 0){
            if(b[i][j]) return false;
            i--;
            j--;
        }
        
        i = r;
        j = c;

        while(j >= 0 && i < n){
            if(b[i][j]) return false;
            i++;
            j--;
        }

        return true;
    }
    int count;
    void sol(int col, int n, vector<vector<int>>&b){
        if(col == n){
            count++;
            return ;
        }

        for(int i=0; i<n; i++){
            if(check(i, col, n, b)){
                b[i][col] = 1;

                sol(col + 1, n, b);

                b[i][col] = 0;
            }
        }
    }
    int totalNQueens(int n) {
        vector<vector<int>>b(n, vector<int>(n, 0));
        sol(0, n, b);
        return count;
    }
};