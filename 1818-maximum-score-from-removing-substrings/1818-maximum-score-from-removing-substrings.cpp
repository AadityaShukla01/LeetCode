class Solution {
public:
    int sol(string& s, char a, char b) {
        // first remove all of mx character then remove of other one
        int count = 0;
        int n = s.size();
        stack<char> st;

        for (int i = 0; i < n; i++) {
            if (st.empty() == false && st.top() == a && s[i] == b) {
                count++;
                st.pop();
            } else {
                st.push(s[i]);
            }
        }
        // update the string
        s = "";
        while (st.empty() == false) {
            s += st.top();
            st.pop();
        }
        reverse(s.begin(), s.end());
        return count;
    }
    int maximumGain(string s, int x, int y) {
        int mx = 0;
        if (x > y) {
            int cnt1 = sol(s, 'a', 'b');
            int cnt2 = sol(s, 'b', 'a');

            mx = max(mx, cnt1 * x + cnt2 * y);
        } else {
            int cnt1 = sol(s, 'b', 'a');
            int cnt2 = sol(s, 'a', 'b');

            mx = max(mx, cnt1 * y + cnt2 * x);
        }
        return mx;
    }
};