class Solution {
public:
    bool hasSpecialSubstring(string s, int k) {
        
        int n = s.size();
        for(int i=0; i<n; i++)
        {
            char c = s[i];
            int j = i;
            int len = 0;
            while(j < n && s[j] == c)
            {
                len++;
                j++;
            }
            i = j - 1;
            if(len == k) return true;
        }

        return false;
    }
};