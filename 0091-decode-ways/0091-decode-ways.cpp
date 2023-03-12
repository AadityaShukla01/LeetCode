class Solution {
public:
    
    int sol( string s, int i, vector<int> &dp){
        int n=s.size();

        if(i==s.size()) return 1;

        if(s[i]=='0') return 0;

        if(dp[i]!=-1) return dp[i];
        
        //we get 1 we can move one step & 2 step because 1 & 19 both are possible else if 2 we can only till 26
        if( i<n-1 && ( s[i]=='1' ||(s[i]=='2' && s[i+1]<'7'))) return dp[i]=sol (s,i+2,dp)  + sol(s,i+1,dp);
        // for number like 9,7,8,6,5,4,3
        return dp[i]=sol(s,i+1,dp);
        
        
    }
    int numDecodings(string s) {
        vector<int>dp(s.size(),-1);

        return sol(s,0,dp);
        
    }
};