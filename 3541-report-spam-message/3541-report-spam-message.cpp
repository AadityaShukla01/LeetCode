class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        map<string, int>mp;
        for(auto w: bannedWords) mp[w]++;

        int cnt = 0;
        for(auto w: message)
        {
            if(mp[w] > 0) cnt++;
        }
        return cnt >= 2;
    }
};