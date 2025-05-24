class Solution {
public:
    int maxSubstrings(string word) {
        int n = word.size();
        // Greedy
        int count = 0;
        vector<int> vis(26, -1);
        for (int i = 0; i < n; i++) {
            char c = word[i];
            if (vis[c - 'a'] != -1 && i - vis[c - 'a'] + 1 >= 4) {
                count++;
                for (int j = 0; j < 26; j++)
                    vis[j] = -1;
            } else if(vis[c - 'a'] == -1)
                vis[c - 'a'] = i;
        }
        return count;
    }
};