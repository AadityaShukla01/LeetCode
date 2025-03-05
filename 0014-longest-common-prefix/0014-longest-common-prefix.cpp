class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        int n = strs.size();
        sort(strs.begin(), strs.end());

        // most unique string 
        string s = strs[n - 1];
        int mn = 1e9;
        
        string t = strs[0];
        int len = min(t.size(), s.size());
        int j = 0;
        while(j < len && t[j] == s[j]) j++;
        mn = min(mn, j);
        
        return s.substr(0, mn);
    }
};