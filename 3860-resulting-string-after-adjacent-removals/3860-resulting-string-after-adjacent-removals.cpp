class Solution {
public:
    string resultingString(string s) {
        stack<char> st;
        int n = s.size();
        string ans = "";

        for (int i = 0; i < n; i++) {
            if (st.empty())
                st.push(s[i]);
            else if (abs(st.top() - s[i]) == 1 || 26 - abs(st.top() - s[i]) == 1) {
                st.pop();
            } else
                st.push(s[i]);
        }

        while (st.empty() == false) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};