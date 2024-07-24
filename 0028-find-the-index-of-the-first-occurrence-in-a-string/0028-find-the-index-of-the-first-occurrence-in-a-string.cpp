class Solution {
public:
    int strStr(string s, string t) {
        int ans = -1;
        for(int i=0;i<s.size();i++){
            string temp = s.substr(i, t.size());
            if(temp == t)
                return i;
        }
        return -1;
    }
};