class Solution {
public:
    int sol(int i,string s,unordered_set<string>&set,vector<int>&dp){
        if(i==s.size()) return 1;
        string res="";

        if(dp[i] !=-1) return dp[i];
        
        for(int j=i;j<s.size();j++){
            res+=s[j];   
            if(set.find(res) != set.end()){
                if(sol(j+1,s,set,dp))
                    return dp[i]=1;
        }
    }
        return dp[i]=0;
}
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>set;
        int n=s.size();
        vector<int>dp(n+1,-1);
        for(string it:wordDict)
            set.insert(it);
        return sol(0,s,set,dp);
    }
};