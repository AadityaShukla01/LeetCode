class Solution {
public:
    bool isPalin(string &s)
    {
        int i = 0, j = s.size() - 1;

        while(i <= j)
        {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int longestPalindrome(string s, string t) {
        int mx = 1;
        set<string>ss;
        int n = s.size();
        for(int i=0; i<n; i++)
        {
            for(int j=i; j<n; j++)
            {
                ss.insert(s.substr(i, j - i + 1));
            }
        }

        int m = t.size();
        set<string>st;
        for(int i=0; i<m; i++)
        {
            for(int j=i; j<m; j++)
            {
                st.insert(t.substr(i, j - i + 1));
            }
        }
        st.insert("");
        ss.insert("");
        for(auto it1: ss)
        {
            for(auto it2: st)
            {
                string temp = it1 + it2;
                
                int sz = temp.size();
                if(isPalin(temp)) mx = max(mx, sz);
            }
        }
        return mx;
    }
};