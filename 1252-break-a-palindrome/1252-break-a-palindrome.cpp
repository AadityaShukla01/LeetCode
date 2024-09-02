class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();

        if(n == 1) return "";

        int i = 0, j = n - 1;



        while(palindrome[i] == 'a' && palindrome[j] == 'a'){
            i++;
            j--;
        }
        cout << i << " " << j;
        if(i >= j){
            palindrome[n - 1] = 'b';
        }
        else{
            palindrome[i] = 'a';
        }
        return palindrome;
    }
};