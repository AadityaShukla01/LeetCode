class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int mn = *min_element(nums.begin(), nums.end());

        if(mn < k) return -1;
        map<int, int>mp;
        for(auto el: nums) mp[el]++;
        if(mn == k) return mp.size() - 1;
        else return mp.size();
    }
};