class Solution {
public:
    int totalMoney(int n) {
        int curr = 1;
        int ans = 0;
        int i = 1;
        while (i <= n) {
            if (i % 7 == 1) {
                curr = i / 7 + 1;
            }
            ans += curr;
            curr++;
            i++;
        }
        return ans;
    }
};