class Solution {
public:
    string makeFancyString(string s) {
        int n = s.size();
        string ans = "";
        int i = 0;
        while(i < n){
            int len = 0;
            char curr = s[i];
            while(i < n && curr == s[i]){
                len++;
                i++;
            }

            int sz = min(len, 2);
            while(sz--) ans += curr;
        }
        return ans;
    }
};