class Solution {
public:
    int dp[1001][3][1002][4];
    int sol(int i, int n, vector<int>&rating, int dir, int pre, int cnt){
        if(cnt == 3) return 1;
        if(i >= n) return 0;
        if(dp[i][dir][pre + 1][cnt] != -1) return dp[i][dir][pre + 1][cnt];
        int np = sol(i+1, n, rating, dir, pre, cnt);

        int p = 0;
        if(pre == -1){
            p = sol(i+1, n, rating, dir, i, cnt + 1);
        }

        else if(dir == 1){
            if(rating[i] > rating[pre])
                p = sol(i+1, n, rating, dir, i, cnt + 1);
        }
        else if(dir == 2){
            if(rating[i] < rating[pre])
                p = sol(i+1, n, rating, dir, i, cnt + 1);
        }

        return dp[i][dir][pre + 1][cnt] = p + np;
    }
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        memset(dp, -1, sizeof(dp));
        int a1 = sol(0, n, rating, 1, -1, 0);
        memset(dp, -1, sizeof(dp));
        int a2 = sol(0, n, rating, 2, -1, 0);

        return a1 + a2;
    }
};