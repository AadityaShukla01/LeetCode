class Solution {
public: 
    bool sol(char a ,char b){
        if(abs(a-b)==32)
            return true;
        return false;
    }
    string makeGood(string s) {
        //why we use stack we use stack because in questions when we need to perform operations like editing/finding duplicates on 
        // consecutive elements
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(st.empty()==false && sol(st.top(),s[i]))
                st.pop();
            else
                st.push(s[i]);
        }
        string res="";
        while(st.empty()==false){
            res+=st.top();
            st.pop();
        }
        string ans=res;
        reverse(ans.begin(),ans.end());
        return ans;
    }
};