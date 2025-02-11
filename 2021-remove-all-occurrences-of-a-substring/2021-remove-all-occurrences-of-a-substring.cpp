class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n = s.size(), m = part.size();

        string ans = "";

        for(int i=0; i<n; i++)
        {
            ans += s[i];
            if(ans.size() >= m && ans.substr(ans.size() - m, m) == part)
            {
                int temp = m;
                while(temp--) ans.pop_back();
            }
        }
        return ans;
    }
};