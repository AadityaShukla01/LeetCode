class Solution {
public:
    int dp[1001][2][2];
    int sol(int i, int n, vector<int>&psum, int fLen, int sLen, bool f, bool s){
        if(i >= n || (f && s)){
            return 0;
        }
        if(dp[i][f][s] != -1) return dp[i][f][s];
        int ans = 0;
        if(i + fLen <= n && !f){
            int sm = 0;
            if(i == 0)
                sm = 0;
            else sm = psum[i - 1]; 

            int steps = sol(i + fLen, n, psum, fLen, sLen, 1, s) + psum[i + fLen - 1] - sm;

            ans = max(ans, steps);
        }

        if(i + sLen <= n && !s){
            int sm = 0;
            if(i == 0)
                sm = 0;
            else sm = psum[i - 1]; 
            int steps = sol(i + sLen, n, psum, fLen, sLen, f, 1) + psum[i + sLen - 1] - sm;

            ans = max(ans, steps);
        }
        int np = sol(i+1, n, psum, fLen, sLen, f, s);

        ans = max(ans, np);
        return dp[i][f][s] = ans;
    }
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n = nums.size();
        vector<int>psum(n, 0);
        int sum = 0;

        for(int i=0; i<n; i++){
            sum += nums[i];
            psum[i] = sum;
        }

        memset(dp, -1, sizeof(dp));


        return sol(0, n, psum, firstLen, secondLen, 0, 0);
    }
};