class Solution {
public:
    vector<string> stringSequence(string target) {
        string s = "";
        int n = target.size();
        vector<string>ans;
        for(int i=0; i<n; i++)
        {
            s += 'a';
            if(target[i] == 'a')
            {
                ans.push_back(s);
            }
            else
            {
                for(char c='a'; c<=target[i]; c++)
                {
                    s.back() = c;
                    ans.push_back(s);
                }
            }
        }
        return ans;
    }
};