class Solution {
public:
    // int sol(int i ,int j ,string& s1,string& s2,vector<vector<int>>&dp){
    //     if(i<0 || j<0)
    //     return 0;

    //     if(dp[i][j]!=-1)
    //     return dp[i][j];

    //     if(s1[i]==s2[j])
    //     return dp[i][j]= 1+sol(i-1,j-1,s1,s2,dp);

    //     else
    //         return dp[i][j]= max(sol(i-1,j,s1,s2,dp),sol(i,j-1,s1,s2,dp));
    //     // return dp[i][j];
    // }
    int sol(int m ,int n ,string& s1,string& s2,vector<vector<int>>&dp){
        for(int i=0;i<s1.size()+1;i++){
            for(int j=0;j<s2.size()+1;j++){
                if(i==0)
                dp[i][j]=0;
                if(j==0)
                dp[i][j]=0;
            }
        }
        for(int i=1;i<s1.size()+1;i++){
            for(int j=1;j<s2.size()+1;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size(),n=text2.size();
        vector<vector<int>>siya(m+1,vector<int>(n+1,0));
        return sol(m,n,text1,text2,siya);
    }
};