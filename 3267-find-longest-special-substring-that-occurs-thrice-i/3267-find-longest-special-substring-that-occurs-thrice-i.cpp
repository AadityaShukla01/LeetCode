class Solution {
public:
    bool acceptable(string &temp)
    {
        map<char, int>mp;
        for(auto c: temp) mp[c]++;

        return mp.size() == 1;
    }
    int maximumLength(string s) {
        map<string, int>mp;
        int n = s.size();

        

        for(int i=0; i<n; i++)
        {
            for(int j=i; j<n; j++)
            {
                string temp = s.substr(i, j - i + 1);
                if(acceptable(temp))
                    mp[temp]++;
            }
        }

        int mx = -1;
        for(int i=0; i<n; i++)
        {
            for(int j=i; j<n; j++)
            {
                string temp = s.substr(i, j - i + 1);
                if(mp[temp] >= 3)
                {
                    mx = max(mx, j - i + 1);
                }
            }
        }
        return mx;
    }
};