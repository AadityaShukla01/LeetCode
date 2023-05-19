class Solution {
public:
    int minimumDeletions(string s) {
        stack<char>st;
        int c=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='b')
                st.push(s[i]);
            else if(st.empty()==false && s[i]=='a'){
                    if(st.top()=='b'){
                        c++;
                        st.pop();
                    }
                }
        }
        return c;
    }
};