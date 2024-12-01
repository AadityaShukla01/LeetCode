class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int n = nums.size();
        // -6 -3 -2 -1 4
        int sum = 0;
        map<int,  int>mp;
        for(auto el: nums) 
        {
            mp[el]++;
            sum += el;
        }
        int mx = -1e9;
        for(int i=0; i<n; i++)
        {
            int el = nums[i];
            mp[el]--;
            int curr = sum - 2 * el;
            if(mp[curr])
            {
                mx = max(mx, curr);
            }
            mp[el]++;
        }
        return mx;
    }
};