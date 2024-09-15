class Solution {
public:
    string simplifyPath(string s) {
        stringstream str(s);
        string word = "";
        stack<string>st;


        while(getline(str, word, '/')){
            if(word == "." || word == "")
                continue;

            if(word != ".."){
                st.push(word);
            }
            else{
                if(st.empty() == false){
                    st.pop();
                }
            }
        }
        if(st.empty())
            return "/";

        string res = "";
        while(st.empty() == false){
            res = "/" + st.top() + res;
            st.pop();
        }
        return res;
    }
};