class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int cnt = 1;
        int mn = INT_MAX;
        for(int i=0; i<n; i++){
            mn = min(mn, nums[i]);
            if(nums[i] - mn > k){
                mn = nums[i];
                cnt++;
            }
        }
        return cnt;
    }
};