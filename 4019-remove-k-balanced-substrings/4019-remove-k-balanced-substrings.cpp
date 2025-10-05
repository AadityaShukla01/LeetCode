class Solution {
public:
    string removeSubstring(string s, int k) {
        int n = s.size();
        stack<pair<char, int>> st;

        for (int i = 0; i < n; i++) {
            if (st.empty()) {
                st.push({s[i], 1});
                continue;
            }
            if (s[i] == ')') {
                if(k == 1){
                    if(st.top().first == '('){
                        auto it1 = st.top();
                        st.pop();
                        if(it1.second - 1) st.push({it1.first, it1.second - 1});
                    }
                    else{
                        st.push({s[i], st.top().second});
                    }
                }
                else if (st.top().first == s[i]) {
                    auto it1 = st.top();
                    if (st.top().second + 1 == k) {
                        st.pop();
                        if (!st.empty() && st.top().first == '(' &&
                            st.top().second >= k) {
                            if (st.top().second == k)
                                st.pop();
                            else {
                                auto it2 = st.top();
                                st.pop();
                                st.push({it2.first, it2.second - k});
                            }
                        } else {
                                st.push({it1.first, it1.second + 1});
                        }
                    } else {
                        st.pop();
                        st.push({it1.first, it1.second + 1});
                    }
                } else {
                    st.push({s[i], 1});
                }
            } else {
                if (st.top().first == s[i]) {
                    auto it = st.top();
                    st.pop();
                    st.push({s[i], it.second + 1});
                } else {
                    st.push({s[i], 1});
                }
            }
        }

        string ans = "";
        while (st.empty() == false) {
            auto it = st.top();

            st.pop();
            char c = it.first;
            int f = it.second;

            while (f--)
                ans += c;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};