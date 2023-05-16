class Solution {
public:
    bool sol(char c){
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'|| c=='A' || c=='E' || c=='I' || c=='O' || c=='U')
            return true;
        return false;
    }
    string reverseVowels(string s) {
        int i=0;
        int j=s.size()-1;
        while(i<j){
            if(sol(s[i]) && sol(s[j])){
                swap(s[i],s[j]);
                i++;
                j--;
            }
            else if(sol(s[i]))
                j--;
            else if(sol(s[j]))
                i++;
            else{
                i++;
                j--;
            }
        }
        return s;
    }
};