class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int ans = 0;

        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int odd = 0, even = 0;
            unordered_map<int, int> mp;
            for (int j = i; j < n; j++) {
                if (mp.find(nums[j]) == mp.end()) {
                    if (nums[j] % 2)
                        odd++;
                    else
                        even++;
                    mp[nums[j]]++;
                }
                if (odd == even) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};