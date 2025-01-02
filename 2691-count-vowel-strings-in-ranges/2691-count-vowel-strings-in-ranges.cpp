class Solution {
public:
    bool isVowel(char c)
    {
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            return true;
        return false;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int>ans;
        vector<int>pf(n + 1);
        pf[0] = 0;

        for(int i=0; i<n; i++)
        {
            string word = words[i];
            if(isVowel(word[0]) && isVowel(word[word.size() - 1])){
                pf[i + 1] = pf[i] + 1;
            }
            else pf[i + 1] = pf[i];
        }

        for(auto q: queries)
        {
            int s = q[0], e = q[1];

            if(s)
                ans.push_back(pf[e + 1] - pf[s]);
            else 
                ans.push_back(pf[e + 1]);
        }
        return ans;
    }
};