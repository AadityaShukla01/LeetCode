class Solution {
public:
    
    bool checkInclusion(string s1, string s2) {
        vector<int>map1(26,0);
        vector<int>map2(26,0);

        if(s1.size() > s2.size()) return false;

        for(int i=0;i<s1.size();i++) 
            map1[s1[i]-'a']++;

        for(int i=0;i<s1.size();i++)
            map2[s2[i]-'a']++;

        if(map1==map2) return true;

        for(int i=s1.size();i<s2.size();i++)
        {
            map2[s2[i]-'a']++;
            map2[s2[i-s1.size()]-'a']--;

            if(map1==map2) return true;
        }
        return false;
    }
};