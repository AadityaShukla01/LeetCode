class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }

        int remSum = sum - x;
        unordered_map<int, int> map;
        sum = 0;
        int len = 0;
        //we find max len of subarray having sum as sum - x;
        // this will give us len of subarray with sum x having min len and hence min number of operations
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (map.find(sum - remSum) != map.end()) {
                len = max(len, i - map[sum - remSum]);
            }

            if (map.find(sum) == map.end())
                map[sum] = i;

            if (sum == remSum)
                len = max(len, i + 1);
        }

        if (len == 0 && remSum != 0)
            return -1;
        return n - len;
    }
};