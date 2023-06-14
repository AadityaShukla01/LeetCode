class Solution {
public:
    int dp[1001][1001]; // TC IS 0(N^2) brute force without memoisation was 0(n^3)
    bool isPalin(int i,int j,string &s){
        while(i<j){
            if(dp[i][j] != -1) return dp[i][j];
            if(s[i] != s[j])
                return dp[i][j] = false;
            i++;
            j--;
        }
        return dp[i][j] = true;
    }
    int sol(int n, string &s){
        int ans = 0;
        //generate all possible substrings & check if they are palindrome or not
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++)
                ans+=isPalin(i,j,s);
        }
        return ans;
    }
    int countSubstrings(string &s) {
        int n = s.size();
        memset(dp,-1,sizeof(dp));
        return sol(n,s);
    }
};