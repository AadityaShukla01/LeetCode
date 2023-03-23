class Solution {
public:
    string removeOuterParentheses(string s) {
       int count=0;
       string ans="";
       for(int i=0;i<s.size();i++){
           if(s[i]=='(' && count==0) count++;
           else if(s[i]=='(' && count){
               ans+=s[i];
               count++;
           }
           else if(s[i]==')' && count==1) count--;
           else if(s[i]==')' && count>1)  {
               ans+=s[i];
               count--;
           }
       }
       return ans;
    }
};