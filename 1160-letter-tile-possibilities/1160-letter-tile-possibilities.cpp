class Solution {
public:
    // took help
    int cnt;
    void sol(int i, int n, map<char, int>& mp) {
        cnt++;
        if (i >= n)
            return;
        
        for (auto v : mp) { // choice
            // take
            if (v.second != 0) { // check
                mp[v.first]--;
                sol(i + 1, n, mp);
                mp[v.first]++;
            }
        }
    }
    int numTilePossibilities(string tiles) {
        int n = tiles.size();
        map<char, int> mp;
        for (auto c : tiles)
            mp[c]++;
        cnt = 0;
        sol(0, n, mp);

        return cnt - 1; // for empty string
    }
};