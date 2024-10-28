class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        set<long long>set;
        sort(nums.begin(), nums.end());
        for(auto el: nums) set.insert(el);
        int n = nums.size();
        int mx = -1;
        for(int i=0; i<n; i++)
        {
            long long el = nums[i];
            int len = 0;
            while(set.find(el) != set.end())
            {
                set.erase(el);
                el = 1LL * el * el;
                len++;
            }
            mx = max(mx, len);
        }
        return mx >= 2 ? mx : -1;
    }
};