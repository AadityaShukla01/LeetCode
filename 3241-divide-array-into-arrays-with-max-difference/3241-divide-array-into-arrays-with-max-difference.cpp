class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>>ans;

        int cnt = n / 3;
        int i = 0;
        while(cnt--){
            int len = 3;
            vector<int>v;

            if(nums[i + len - 1] - nums[i] > k) return {};

            while(len--){
                v.push_back(nums[i]);
                i++;
            }
            ans.push_back(v);
        }
        return ans;
    }
};