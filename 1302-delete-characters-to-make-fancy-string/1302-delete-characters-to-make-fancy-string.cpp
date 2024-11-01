class Solution {
public:
    string makeFancyString(string s) {
        stack<pair<char, int>>st;
        int n = s.size();
        for(int i=0; i<n; i++)
        {
            if(st.empty()){
                st.push({s[i], 1});
            }
            else {
                if(st.top().first == s[i]){
                    if(st.top().second == 2){
                        continue;
                    }
                    else
                    {
                        auto it = st.top();
                        st.pop();

                        st.push({s[i], it.second + 1});

                    } 
                }
                else st.push({s[i], 1});
            }
        }

        string ans = "";
        while(st.empty() == false)
        {
            auto it = st.top();
            st.pop();
            int f = it.second;
            char c = it.first;
            while(f--) ans += c;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};