class Solution {
public:
    int maxContainers(int n, int w, int maxWeight) {
        int op1 = maxWeight / w;
        int op2 = n * n;

        return min(op1, op2);
    }
};