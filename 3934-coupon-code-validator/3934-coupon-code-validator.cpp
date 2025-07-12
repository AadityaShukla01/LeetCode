class Solution {
public:
    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {
        map<string, int> businessLines;

        businessLines["electronics"] = 1;
        businessLines["grocery"] = 1;
        businessLines["pharmacy"] = 1;
        businessLines["restaurant"] = 1;

        vector<string> ans;
        vector<vector<string>> v;
        for (int i = 0; i < code.size(); i++) {
            v.push_back({businessLine[i], code[i], to_string(i)});
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size(); i++) {
            if (!isActive[stoi(v[i][2])])
                continue;

            if (!businessLines[v[i][0]])
                continue;
            bool f = 0;
            for (char c : v[i][1]) {
                if (!isalnum(c) && c != '_') {
                    f = 1;
                    break;
                }
            }
            if (v[i][1].size() && !f)
                ans.push_back(v[i][1]);
        }

        return ans;
    }
};