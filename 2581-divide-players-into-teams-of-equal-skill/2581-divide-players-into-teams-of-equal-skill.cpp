class Solution {
public:
    long long dividePlayers(vector<int>& nums) {
        long long ans = 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = 0, j = n - 1;
        long long sum = nums[0] + nums[n - 1];
        while(i < j)
        {
            if(nums[i] + nums[j] == sum)
            {
                ans += 1LL * nums[i] * nums[j];
                i++;
                j--;
            }
            else return -1;
        }
        return ans;
    }
};