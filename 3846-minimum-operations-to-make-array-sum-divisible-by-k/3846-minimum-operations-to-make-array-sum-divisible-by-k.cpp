class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sum = 0;
        for(auto el: nums) sum += el;

        return sum % k;
    }
};