class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;
        string res = goal + goal;
        int m = res.size();
        int n = s.size();
        int i = 0;
        int j = 0;
        for(int i=0; i<res.size() - s.size(); i++){
            if(res.substr(i, s.size()) == s) return true;
        }
        return false;
    }
};