class Solution {
public:
    string to_binary(int n) {
        string res = "";
        while (n) {
            if (n % 2)
                res += "1";
            else
                res += "0";
            n = n / 2;
        }

        reverse(res.begin(), res.end());
        return res;
    }
    int dp[33][2][2][2];
    int sol(string& R, int n, int tyt, int start, int preBit) {
        if (n == 0)
            return 1;
        if(dp[n][tyt][start][preBit] != -1) return dp[n][tyt][start][preBit];
        int ub = tyt ? (R[R.size() - n] - '0') : 1;
        int ans = 0;
        for (int i = 0; i <= ub; i++) {
            if(i == 0){
                if(!start){
                    ans += sol(R, n - 1, tyt & (ub == i), 0, i);
                }
                else{
                    ans += sol(R, n - 1, tyt & (ub == i), start, i);
                }
            }
            else{
                if(!start){
                    ans += sol(R, n - 1, tyt & (ub == i), 1, 1);
                }
                else{
                    if(preBit == i) continue;
                        ans += sol(R, n - 1, tyt & (ub == i), start, i);
                }
            }
        }
        return dp[n][tyt][start][preBit] = ans;
    }
    int findIntegers(int n) {
        string binary = to_binary(n);
        int len = binary.size();
        memset(dp, -1, sizeof(dp));
        return sol(binary, len, 1, 0, 0);
    }
};