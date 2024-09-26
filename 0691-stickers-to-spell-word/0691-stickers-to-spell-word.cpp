class Solution {
public:
    int dp[1 << 15];
    int sol(int n, vector<vector<int>> &freq, string &target, int mask){
        int m = target.size();
        if(mask == ((1 << m) - 1))
            return 0;

        if(dp[mask] != -1)
            return dp[mask];

        int ans = 1e9;

        for(int i=0; i<n; i++){

            vector<int>count = freq[i];
            int newMask = mask;

            for(int j=0; j<m; j++){
                if((mask & (1 << j)) == 0 && count[target[j] - 'a']){
                    count[target[j] - 'a']--;
                    newMask = (newMask | (1 << j));
                }
            }

            if(newMask != mask){
                ans = min(ans, 1 + sol(n, freq, target, mask | newMask));
            }
        }
        return dp[mask] = ans;
    }
    int minStickers(vector<string>& sticker, string target) {
        int n = sticker.size();
        vector<vector<int>>freq(n);
        for(int i=0; i<n; i++){
            vector<int>f(26, 0);

            for(auto it: sticker[i])
                f[it - 'a']++;

            freq[i] = f;
        }
        int mask = 0;
        memset(dp, -1, sizeof(dp));
        int a = sol(n, freq, target, mask);
        if(a == 1e9) return -1;
        return a;
    }
};