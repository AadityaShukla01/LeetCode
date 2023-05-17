class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int>ans;
        for(int i=0;i<s.size();i++){
            if(s[i] == c)
                ans.push_back(i);
        }
        vector<int>res;
        for(int i=0;i<s.size();i++){
            int mini=INT_MAX;
            for(int j=0;j<ans.size();j++){
                mini=min(mini,abs(i-ans[j]));
            }
            res.push_back(mini);
        }
        return res;
    }
};