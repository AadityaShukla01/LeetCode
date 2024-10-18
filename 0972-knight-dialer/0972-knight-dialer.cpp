class Solution {
public:
    const int mo = 1e9 + 7;
    int vec[5001][10];
    int sol(int i, int n, int digit,  vector<vector<int>> &mp)
    {
        if(i >= n) return 1;

        if(digit == 5) return 0;

        if(vec[i][digit] != -1)
            return vec[i][digit];

        vector<int>v = mp[digit];
        long long ans = 0;
        for(int j=0; j<v.size(); j++)
        {
            long long steps = sol(i + 1, n, v[j], mp) % mo;
            ans = ans %mo  + steps % mo;
            ans %= mo;
        }
        return vec[i][digit] = ans % mo;
    }
    int knightDialer(int n) {
        // cvecied from description
        vector<vector<int>> mp = {
            {4, 6}, {8, 6},    {7, 9}, {4, 8}, {3, 9, 0},
            {},     {0, 1, 7}, {2, 6}, {1, 3}, {2, 4}};

        long long ans = 0;
        memset(vec, -1, sizeof(vec));
        for(int i=0; i<=9; i++)
        {
            ans += sol(1, n, i, mp);
            ans %= mo;
        }
        return ans;
    }
};