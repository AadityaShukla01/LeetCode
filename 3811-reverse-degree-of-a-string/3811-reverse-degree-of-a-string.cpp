class Solution {
public:
    int reverseDegree(string s) {
        int reversedDegree = 0;
        int n = s.size();
        for(int i=0; i<n; i++)
        {
            reversedDegree += (26 - (s[i] - 'a')) * (i + 1);
        }
        return reversedDegree;
    }
};