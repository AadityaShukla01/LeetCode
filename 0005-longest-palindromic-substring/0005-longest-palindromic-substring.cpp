class Solution {
public:
    string longestPalindrome(string s) {
        // brute force is O(n^3)
        // this approach is O(n^2) & space O(1)
        int n = s.size();

        int maxLen = -1;
        int start = -1;

        for (int i = 0; i < n; i++) {
            int ryt = i;
            // for cases like abccba
            while (ryt < n && s[ryt] == s[i])
                ryt++;

            int left = i - 1;

            // keep extending palindrome
            while (left >= 0 && ryt < n && s[left] == s[ryt]) {
                left--;
                ryt++;
            }

            if (ryt - left - 1 > maxLen) {
                maxLen = ryt - left - 1;
                start = left + 1;
            }
        }
        return s.substr(start, maxLen);
    }
};