class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size();
        int pre = 0, cnt = 0;
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
            cnt += min(pre, len);
            pre = len;
        }
        return cnt;
    }
};