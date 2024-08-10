class Solution {
public:
    int count(int m, int n, int mi) {
        int smaller = 0;

        for (int i = 1; i <= n; i++) {
            smaller += min(m, mi / i);
        }
        return smaller;
    }
    int findKthNumber(int m, int n, int k) {
        int lo = 1;
        int hi = m * n;
        int ans = -1;
        while (lo <= hi) {
            int mi = lo + (hi - lo) / 2;

            if (count(m, n, mi) >= k) {
                ans = mi;
                hi = mi - 1;
            } else
                lo = mi + 1;
        }

        return ans;
    }
};