class Solution {
public:
    int countGoodSubstrings(string s) {
        int q=0;
        unordered_set<char>set;

        int j=0;
        int i=0;
        while(i<s.size() && j<s.size()){
            if(set.find(s[i])==set.end()){
                set.insert(s[i]);
                if(set.size()==3)
                q++;
                i++;
            }
             if(set.size()==3 || set.find(s[i])!=set.end()){
                set.erase(s[j]);
                j++;
            }
        }
        return q;
    }
};