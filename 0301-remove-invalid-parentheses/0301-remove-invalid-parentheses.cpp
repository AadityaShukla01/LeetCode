class Solution {
public:
    set<string>a;
    vector<string>ans;
    void sol(int i, int n, string &s, int &open, string &temp)
    {
        if(i >= n) {
            if(open == 0){
                a.insert(temp);
            }
            return;
        }

        sol(i + 1, n, s, open, temp);

        if(s[i] == '(')
        {
            temp += s[i];
            open++;
            sol(i + 1, n, s, open, temp);
            temp.pop_back();
            open--;

        }
        if(s[i] == ')' && open > 0)
        {
            temp += s[i];
            open--;
            sol(i + 1, n, s, open, temp);
            temp.pop_back();
            open++;
        }
        if(s[i] >= 'a' && s[i] <= 'z')
        {
            temp += s[i];
            sol(i + 1, n, s, open, temp);
            temp.pop_back();
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        int n = s.size();
        string temp = "";
        int open = 0;
        sol(0, n, s, open, temp);
        int mx = 0;
        for(auto str: a)
        {
            int sz = str.size();
            mx = max(mx, sz);
        }
        vector<string>res;
        for(auto str: a)
        {
            if(str.size() == mx) res.push_back(str);
        }
        if(!res.size()) return {""};
        return res;
    }
};