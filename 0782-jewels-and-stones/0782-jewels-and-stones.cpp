class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        map<char, int>mp;

        for(auto c: jewels) mp[c]++;


        int cnt = 0;

        for(auto c: stones)
        {
            if(mp[c]) cnt++;
        }
        return cnt;
    }
};