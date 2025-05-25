class Solution {
public:
    long long minCuttingCost(int n, int m, int k) {
        long long ans = 0;
        if(n > k){
            while(n > k){
                int pt1 = k, pt2 = n - k;
                ans += 1LL * pt1 * pt2;
                n = pt2;
            }
        }

        if(m > k){
            while(m > k){
                int pt1 = k, pt2 = m - k;
                ans += 1LL * pt1 * pt2;
                m = pt2;
            }
        }

        return ans;
    }
};