class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n = nums.size();
        map<int, int>mp;
        for(auto el: nums)mp[el]++;

        int sum = *max_element(nums.begin(), nums.end());
        if(sum <= 0) return sum;
        sum = 0;
        for(auto it : mp){
            if(it.first > 0) sum += it.first;
        }
        return sum;
    }
};