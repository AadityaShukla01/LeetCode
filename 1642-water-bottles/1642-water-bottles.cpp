class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int empty = 0;
        int ans = 0;
        while (numBottles > 0) {
            if (empty == numExchange) {
                numBottles++;
                empty = 0;
            }
            numBottles--;
            ans++;
            empty++;
        }
        if(empty == numExchange) ans++;
        return ans;
    }
};