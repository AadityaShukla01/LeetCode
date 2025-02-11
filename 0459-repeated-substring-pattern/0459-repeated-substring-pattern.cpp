class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        vector<int>kmp(n+1);
        int i = 1;
        int len = 0;
        kmp[0] = 0;
        while(i < n){
            if(s[i] == s[len]){
                len++;
                kmp[i] = len;
                i++;
            }
            else{
                if(len != 0)
                    len = kmp[len - 1];
                else{
                    kmp[i] = 0;
                    i++;
                }
            }
        }
        for(auto it: kmp)
            cout<<it<<" ";
        if(kmp[n-1]> 0 && kmp[n-1]%(n - kmp[n-1]) == 0) return true;
        return !true;
    }
};