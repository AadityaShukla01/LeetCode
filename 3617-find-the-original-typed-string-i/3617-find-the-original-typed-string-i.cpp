class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.size();
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            int j = i;
            int cnt = 0;
            while(j < n && word[j] == word[i])
            {
                j++;
                cnt++;
            }
            i = j - 1;
            ans += (cnt - 1);
        }
        return ans + 1;
    }
};