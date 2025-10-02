class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int empty = 0;
        int count = 0;

        while (numBottles > 0) {
            if (empty == numExchange) {
                numExchange++;
                empty = 0;
                numBottles++;
            } else {
                count++;
                numBottles--;
                empty++;
            }
        }
        if (empty == numExchange)
            count++;
        return count;
    }
};