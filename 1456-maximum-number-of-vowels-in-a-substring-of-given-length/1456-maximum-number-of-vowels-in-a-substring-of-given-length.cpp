class Solution {
public:
    bool sol(char c){
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
            return true;
        return false;
    }
    int maxVowels(string s, int k) {
        int c=0;
        for(int i=0;i<k;i++){
            if(sol(s[i])) c++;
        }
        int ans=0;
        ans=max(ans,c);
        for(int i=k;i<s.size();i++){
            if(sol(s[i])) c++;
            if(sol(s[i-k])) c--;
            ans=max(ans,c);
        }
        return ans;
    }
};