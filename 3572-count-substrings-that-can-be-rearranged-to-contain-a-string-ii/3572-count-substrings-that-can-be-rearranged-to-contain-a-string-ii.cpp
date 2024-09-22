class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        long long count = 0;
        unordered_map<char, int>mp;
        for(auto c: word2) mp[c]++;
        int cnt = word2.size();
        int j = 0;
        int n = word1.size();
        for(int i=0; i<n; i++)
        {
            if(mp[word1[i]] > 0) cnt--;
            mp[word1[i]]--;

            if(cnt == 0)
            {
                while(cnt == 0)
                {
                    count += (n - i);
                    mp[word1[j]]++;
                    if(mp[word1[j]] > 0) cnt++;
                    j++;
                }
            }
        }
        return count;
    }
};