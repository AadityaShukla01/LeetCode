class Solution {
public:
    int minBitFlips(int start, int goal) {
        int count = 0;

        for (int i = 0; i < 32; i++) {
            int bit1 = start & (1 << i);
            int bit2 = goal & (1 << i);

            if (bit1 != bit2)
                count++;
        }
        return count;
    }
};