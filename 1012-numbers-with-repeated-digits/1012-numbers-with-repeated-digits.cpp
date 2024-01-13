class Solution {
public:
    int dp[11][1 << 10][2][2];
    int sol(string &R, int n, int mask,bool zero, bool tyt){
        if(n == 0) return 1;

        if(dp[n][mask][zero][tyt] != -1)
            return dp[n][mask][zero][tyt];

        int ans = 0;
        int upperBound = tyt ? (R[R.size() - n] - '0') : 9;
        for(int i=0; i<=upperBound; i++){
            if(i == 0){
                if(zero){
                    ans += sol(R, n-1, mask, zero, tyt & (upperBound == i));
                }
                else{
                    if(!(mask & (1 << i)))
                        ans += sol(R, n-1, mask | (1 << i), zero, tyt & (upperBound == i));
                }
            }
            else{
                if(!(mask & (1 << i)))
                    ans += sol(R, n-1, mask | (1 << i), false, tyt & (upperBound == i));
            }
        }
        return dp[n][mask][zero][tyt] =ans;
    }
    int numDupDigitsAtMostN(int n) {
        string R1 = to_string(n);
        int len1 = R1.size();

        string R2 = to_string(1);
        int len2 = R2.size();

        memset(dp, -1, sizeof(dp));
        int ryt = sol(R1, len1, 0, true, true);

        memset(dp, -1, sizeof(dp));
        int left = sol(R2, len2, 0, true, true);

        // cout<<left<<endl;
        return n - (ryt - left + 1);
    }
};