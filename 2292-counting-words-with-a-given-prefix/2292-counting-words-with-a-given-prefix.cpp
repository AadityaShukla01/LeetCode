class Solution {
public:
    bool prefix(string s, string p)
    {
        if(s.size() < p.size()) return false;
        return s.substr(0, p.size()) == p;
    }
    int prefixCount(vector<string>& words, string pref) {
        int cnt = 0;
        for(auto el: words)
        {
            if(prefix(el, pref))
                cnt++;
        }

        return cnt;
    }
};