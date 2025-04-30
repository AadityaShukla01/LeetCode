class Solution {
public:
    bool checkEven(int num) {
        int count = 0;
        while (num) {
            count++;
            num /= 10;
        }
        return count % 2 == 0;
    }
    int findNumbers(vector<int>& nums) {
        int count = 0;

        for (auto el : nums) {
            count += checkEven(el);
        }
        return count;
    }
};