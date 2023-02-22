class Solution {
public:
   int sol(int i ,int j ,string& s1,string& s2,vector<vector<int>>&dp){
        if(i<0 || j<0)
        return 0;

        if(dp[i][j]!=-1)
        return dp[i][j];

        if(s1[i]==s2[j])
        return dp[i][j]= 1+sol(i-1,j-1,s1,s2,dp);

        else
            return dp[i][j]= max(sol(i-1,j,s1,s2,dp),sol(i,j-1,s1,s2,dp));
        // return dp[i][j];
    }
    int minDistance(string s, string t) {
        int m=s.size();
        int n=t.size();
        
        vector<vector<int>>siya(m+1,vector<int>(n+1,-1));
        return m+n-(2*sol(m-1,n-1,s,t,siya));
    }
};