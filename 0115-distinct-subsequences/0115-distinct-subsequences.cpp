class Solution {
private:
    // l1 badi sttring l2 small string
    int om(int i,int j,string &s,string &t,vector<vector<int>>&dp){
        if(j<0)
            return 1;
        if(i<0)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(s[i]==t[j]) { //agar match kere strings
        //ya to pick karo ya mat karo kyonki or bi subseque=ences mil sakti hain
        return dp[i][j]=om(i-1,j-1,s,t,dp)+om(i-1,j,s,t,dp);
        
        }
        //match ni hue to pick mat karo
        return dp[i][j]= om(i-1,j,s,t,dp);
        
    }
    int sol(string &x,string &y,int i,int j,vector<vector<int>>&dp){
       if(j<0)
       return 1;

       if(i<0)
       return 0;

        if(dp[i][j]!=-1)
            return dp[i][j];

       if(x[i]==y[j])
       return dp[i][j]= sol(x,y,i-1,j-1,dp)+sol(x,y,i-1,j,dp);
       else{
           return dp[i][j]= sol(x,y,i-1,j,dp);
       }
      
    }
    public:
    int numDistinct(string &s, string &t) {
       int l=s.size();
        int m=t.size();
        vector<vector<int>>dp(l,vector<int>(m,-1));
        // return om(l-1,m-1,s,t,dp);
        return sol(s,t,l-1,m-1,dp);
        
        
    }
};