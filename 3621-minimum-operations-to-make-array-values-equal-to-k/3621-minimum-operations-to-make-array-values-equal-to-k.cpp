class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        if(nums[0] < k) return -1;

        map<int, int>mp;
        for(auto el: nums) mp[el]++;

        return (nums[0] == k) ? mp.size() - 1: mp.size();
    }
};