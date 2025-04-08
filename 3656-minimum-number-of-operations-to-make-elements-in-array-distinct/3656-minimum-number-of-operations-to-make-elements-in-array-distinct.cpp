class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        map<int, int> mp;
        for (auto el : nums)
            mp[el]++;

        int size = mp.size();
        int i = 0, op = 0;
        if(size == n) return op;
        while (i < n) {
            op++;

            mp[nums[i]]--;
            if (mp[nums[i]] == 0)
                size--;

            if (i + 1 < n) {
                mp[nums[i + 1]]--;
                if (mp[nums[i + 1]] == 0)
                    size--;
            }
            if (i + 2 < n) {
                mp[nums[i + 2]]--;
                if (mp[nums[i + 2]] == 0)
                    size--;
            }
            i += 3;

            if (size == n - i)
                return op;
        }
        return op;
    }
};