class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string>ans;
        stringstream ss1(s1);
        stringstream ss2(s2);
        string str;
        map<string, vector<int>>mp;
        while(getline(ss1, str, ' '))
        {
            mp[str].push_back(1);
        }

        while(getline(ss2, str, ' '))
        {
            mp[str].push_back(2);
        }

        for(auto it: mp)
        {
            if(it.second.size() == 1) ans.push_back(it.first);
        }
        return ans;
    }
};