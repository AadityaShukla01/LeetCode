class Solution {
public:
     vector<int> sol(string& word, string& pref) {
        string s = pref + "$" + word;
        int n = s.size();
        vector<int> Z(n);
        Z[0] = 0;

        int left = 0;
        int ryt = 0;

        for (int k = 1; k < n; k++) {
            if (k > ryt) {
                // no substring starting before i so we begin comparision from 0
                left = k;
                ryt = k;
                while (ryt < n && s[ryt] == s[ryt - left]) {
                    ryt++;
                }
                Z[k] = ryt - left;
                ryt--;
            } else {
                int k1 = k - left;
                if (Z[k1] < ryt - k + 1) {
                    Z[k] = Z[k1];
                } else {
                    left = k;

                    while (ryt < n && s[ryt] == s[ryt - left])
                        ryt++;

                    Z[k] = ryt - left;
                    ryt--;
                }
            }
        }
        return Z;
    }
    int strStr(string haystack, string needle) {
        vector<int>Z = sol(haystack, needle);
        for(int i=0; i<Z.size(); i++){
            if(Z[i] == needle.size()) return i - needle.size() - 1;
        }
        return -1;
    }
};