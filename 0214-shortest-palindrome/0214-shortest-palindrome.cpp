class Solution {
public:
    vector<int>LPS;
    void calculateLPS(string s){
        int n = s.size();
        LPS.resize(n);

        int i = 1;
        int len = 0;
        while(i < n){
            if(s[i] == s[len]){
                LPS[i] = len + 1;
                len++;
                i++;
            }
            else{
                if(len > 0)
                    len = LPS[len - 1];
                else{
                    LPS[i] = 0;
                    i++;
                }
            }
        }
    }
    string shortestPalindrome(string s) {
        //now this is a good question and a really good application os KMP
        //we will use LPS array to solve this question
        //now lets syay we have a string s
        //the longest palindromic substring in s starting from 0 is till i
        //now if we reverse string from i to n and append it at start we will obtain palindromic sequence

        //to get the longest palindromic sustring we append s + # + ulta(s) so now our most commmon/longest prefix will also be our longest aplindromic susbstring starting at i
        string temp = s;
        if(s.size() == 0) return "";
        reverse(s.begin(), s.end());
        string newString = temp + "#" + s;
        calculateLPS(newString);

        int len_of_longest_palindrom_starting = LPS[newString.size() - 1];
        cout<<len_of_longest_palindrom_starting<<'\n';
        // cout<<newString<<'\n';
        string toAdd = temp.substr(len_of_longest_palindrom_starting);
        reverse(toAdd.begin(), toAdd.end());
        return toAdd + temp;
    }
};