class Solution {
public:
    bool check(map<char, int>&mp, map<char, int>&newMp)
    {
        
        for(char c='a'; c<='z'; c++)
        {
            if(newMp[c] < mp[c]) return false;
        }
        return true;
    }
    long long validSubstringCount(string word1, string word2) {
        long long count = 0;
        map<char, int>mp;
        for(auto c: word2) mp[c]++;

        map<char, int>newMp;
        int j = 0;
        int n = word1.size();
        for(int i=0; i<n; i++)
        {
            newMp[word1[i]]++;

            if(check(mp, newMp))
            {
                
                while(check(mp, newMp))
                {
                    count += (n - i);
                    newMp[word1[j]]--;
                    j++;
                }
            }
        }
        return count;
    }
};