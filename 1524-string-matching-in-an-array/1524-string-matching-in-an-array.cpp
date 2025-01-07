class Solution {
public:
    bool isSubstring(string s, string p)
    {
        for(int i=0; i<p.size(); i++)
        {
            if(p.substr(i, s.size()) == s) return true;
        }
        return false;
    }
    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();
        vector<string>ans;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i == j) continue;
                if(isSubstring(words[i], words[j])){
                    ans.push_back(words[i]);
                    break;
                }
            }
        }
        return ans;
    }
};