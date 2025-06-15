class Solution {
public:
    string generateTag(string caption) {
        string ans = "#";
        int n = caption.size();

        stringstream ss(caption);
        string str;

        while (ss >> str) {
            for (int i = 0; i < str.size(); i++) {
                if (isalpha(str[i])) {
                    if (i == 0)
                        ans += toupper(str[i]);
                    else
                        ans += tolower(str[i]);
                }
            }

        }
        ans[1] = tolower(ans[1]);
        return ans.substr(0, 100);
    }
};