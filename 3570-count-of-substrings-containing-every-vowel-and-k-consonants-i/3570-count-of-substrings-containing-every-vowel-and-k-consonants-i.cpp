class Solution {
public:
    bool isValid(string &s, int k)
    {
        vector<char>v = {'a', 'e', 'i', 'o', 'u'};
        int cnt = 0;
        set<char>set;
        if(s.size() < 5 + k) return false;
        for(auto c: s)
        {
            bool vowel = 0;
            for(auto el: v)
            {
                if(c == el) 
                {
                    vowel = 1;
                    set.insert(el);
                }
            }
            if(!vowel) cnt++;
            if(cnt > k) return false;
        }

        if(cnt == k && set.size() == 5) return true;
        return false;
    }
    int countOfSubstrings(string s, int k) {
        int cnt = 0;
        int n = s.size();
        for(int i=0; i<n; i++)
        {
            for(int j=i; j<n; j++)
            {
                string t = s.substr(i, j - i + 1);
                if(isValid(t, k))
                    cnt++;
            }
        }
        return cnt;
    }
};