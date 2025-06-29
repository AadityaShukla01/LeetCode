class Solution {
public:
    vector<string> partitionString(string s) {
        set<string> set;
        string curr = "";
        vector<string> ans;

        int n = s.size();

        for (int i = 0; i < n; i++) {
            curr += s[i];
            if (set.find(curr) == set.end()) {
                ans.push_back(curr);
                set.insert(curr);
                curr = "";
            }
        }
        return ans;
    }
};