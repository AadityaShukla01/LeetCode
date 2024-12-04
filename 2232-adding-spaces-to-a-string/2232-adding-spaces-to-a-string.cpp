class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans = "";
        int pre = 0;
        spaces.push_back(s.size());
        for(auto space: spaces)
        {
            string temp = s.substr(pre, space - pre);
            ans += temp + " ";
            pre = space;
        }
        return ans.substr(0, ans.size() - 1);
    }
};