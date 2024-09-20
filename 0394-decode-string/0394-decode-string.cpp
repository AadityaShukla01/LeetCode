class Solution {
public:
    string decodeString(string s) {
        int n = s.size();
        stack<char>st;

        for(int i=0; i<n; i++)
        {
            if(s[i] == ']')
            {
                string str = "";
                while(st.empty() == false && st.top() != '[')
                {
                    str += st.top();
                    st.pop();
                }

                st.pop();

                string num = "";
                while(st.empty() == false && isdigit(st.top())){
                    num += st.top();
                    st.pop();
                }

                reverse(num.begin(), num.end());

                int number = stoi(num);
                reverse(str.begin(), str.end());
                while(number--)
                {
                    for(int j=0; j<str.size(); j++) st.push(str[j]);
                }
            }
            else
            {
                st.push(s[i]);
            }
        }

        string ans = "";
        while(st.empty() == false)
        {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};