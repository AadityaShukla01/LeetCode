class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        int sum = 0;
        bool flag = false;

        for (auto el : nums) {
            if (!flag)
                sum += el;
            else
                sum -= el;
            flag = !flag;
        }
        return sum;
    }
};