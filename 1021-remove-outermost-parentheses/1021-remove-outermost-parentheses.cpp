class Solution {
public:
    string removeOuterParentheses(string s) {
       int count=0;
       string res="";
       for(int i=0;i<s.size();i++){
            if(s[i]=='(' && count==0)
            count++; //no inclusion of outer most brackets
            else if(s[i]=='(' && count>0)
            {
                res+=s[i];
                count++;
            }
            else if(s[i]==')' && count==1)
                count--; //no inclusion of ootermost brackets
            else{
                res+=s[i];
                count--;
            }
            
       }
       return res;
    }
};