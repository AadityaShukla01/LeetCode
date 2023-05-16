class Solution {
public:
    int countGoodSubstrings(string s) {
        int c=0;
        for(int i=0;i<s.size();i++){
            string res=s.substr(i,3);
            unordered_set<char>set;
            for(int i=0;i<res.size();i++)
                set.insert(res[i]);
            if(set.size()==3)
                c++;
        }
        return c;
    }
};