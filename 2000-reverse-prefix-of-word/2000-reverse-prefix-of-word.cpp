class Solution {
public:
    string reversePrefix(string s, char ch) {
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==ch){
                ans=i;
                break;
            }
        }
        reverse(s.begin(),s.begin()+ans+1);
        return s;
    }
};