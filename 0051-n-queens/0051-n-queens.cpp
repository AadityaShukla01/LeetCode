class Solution {
public:

    /*
    Time Complexity : O(N!), Since we have N choices in the first row, then N-1 choices in the second row and so on so the overall complexity become O(N!)
Space Complexity: O(N*N), Just the board and recursive stack space
*/
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
    vector<vector<string>>v;
    void sol(int col, int n, vector<vector<int>>&b){
        if(col == n){
            addSolution(b);
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
    void addSolution(vector<vector<int>>&b){
        vector<string>ans;
        for(int i=0; i<b.size(); i++){
            string res = "";
            for(int j=0; j<b.size(); j++){
                if(b[i][j]) res += "Q";
                else res += ".";
            }   
            ans.push_back(res);
        }

        v.push_back(ans);
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>>b(n, vector<int>(n, 0));
        sol(0, n, b);
        return v;
    }
};