class Solution {
public:
    bool isPalin(int i, int j, string &s){
        while(i < j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int dp[2001][4];
    bool sol(int i, int n, string &s, int cnt, vector<vector<bool>>&v){
        if(cnt > 3) return false;
        if(i >= n){
            return cnt == 3;
        }
        if(dp[i][cnt] != -1) return dp[i][cnt];
        for(int j=i; j<n; j++){
            
            if(v[i][j]){
                if(sol(j+1, n, s, cnt + 1, v)) return true;
            }
        }
        return dp[i][cnt] = false;
    }
    bool checkPartitioning(string s) {
        int n = s.size();
        vector<vector<bool>>v(n, vector<bool>(n, false));

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(isPalin(i, j, s)) v[i][j] = true;
            }
        }
        // pre process palindromes
        memset(dp, -1, sizeof(dp));
        return sol(0, n, s, 0, v);
    }
};