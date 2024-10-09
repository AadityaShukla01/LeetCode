class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size();
        vector<int>a;

        for(int i=0; i<n; i++)
        {
            int j = i;
            int len = 0;
            while(j < n && s[j] == s[i])
            {
                len++;
                j++;
            }
            i = j - 1;
            a.push_back(len);
        }
        int cnt = 0;

        for(int i=0; i<a.size()-1; i++)
        {
            int mn = min(a[i], a[i + 1]);
            cnt += mn;
        }
        return cnt;
    }
};