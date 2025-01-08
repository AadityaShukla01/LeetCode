class Solution {
public: 
    bool check(string s, string p){
        int n = s.size(), m = p.size();
        if(m < n) return false;
        int i = 0;

        while(i < n){
            if(s[i] != p[i]) return false;
            i++;
        }
        i = n - 1;
        int j = m - 1;
        while(i >= 0){
            if(s[i] != p[j]) return false;
            i--;
            j--;
        }
        return true;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int cnt = 0;
        int n = words.size();
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                if(check(words[i], words[j]))
                    cnt++;
            }
        }
        return cnt;
    }
};