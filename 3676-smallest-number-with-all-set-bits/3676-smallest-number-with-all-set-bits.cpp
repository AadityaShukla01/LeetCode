class Solution {
public:
    int smallestNumber(int n) {
        int p =  log2(n) + 1;
        return pow(2, p) - 1;
    }
};