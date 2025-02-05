class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1 == s2) return true;

        int n = s1.size();
        int fi = -1, si = -1;

        for(int i=0; i<n; i++)
        {
            if(s1[i] != s2[i]){
                if(fi == -1) fi = i;
                else si = i;
            }
        }

        if(fi == -1 || si == -1) return false;

        swap(s1[fi], s1[si]);

        return s1 == s2;
    }
};