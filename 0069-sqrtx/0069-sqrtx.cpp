class Solution {
public:
    int mySqrt(int x) {
        int lo = 0;
        int hi = x;
        int ans = -1;
        while(lo <= hi){
            int m = lo + (hi - lo)/2;

            if(1LL * m * m > x){
                hi = m - 1;
            }
            else if(m * m < x) {
                ans = m;
                lo = m + 1;
            }
            else return m;
        }
        return ans;
    }
};