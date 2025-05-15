class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words,
                                         vector<int>& groups) {
        map<int, string> mp;
        int n = groups.size();
        for (int i = 0; i < n; i++) {
            mp[i] = words[i];
        }

        vector<string> ans;
        bool prev = -1;
        for (int i = 0; i < n; i++) {
            if (i == 0){
                prev = groups[i];
                ans.push_back(mp[i]);
            }
            else {
                if (groups[i] != prev){
                    ans.push_back(mp[i]);
                    prev = groups[i];
                }
            }
        }
        return ans;
    }
};