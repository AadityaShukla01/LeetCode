class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();

        if(n > m) return false;
        vector<int>mp1(26, 0), mp2(26, 0);
        for(auto c: s1) mp1[c - 'a']++;

        for(int i=0; i<s1.size(); i++){
            mp2[s2[i] - 'a']++;
        }

        if(mp1 == mp2) return true;

        for(int i=s1.size(); i<s2.size(); i++){
            mp2[s2[i - s1.size()] - 'a']--;
            mp2[s2[i] - 'a']++;

            if(mp1 == mp2) return true;
        }
        return false;
    }
};