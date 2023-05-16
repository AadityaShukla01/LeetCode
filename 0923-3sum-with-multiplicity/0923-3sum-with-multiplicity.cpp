class Solution {
public:
    int threeSumMulti(vector<int>& nums, int target) {
        int c=0;
        int i=0;
        sort(nums.begin(),nums.end());
        int mod=1e9+7;
        unordered_map<int,int>map;
        for(int i=0;i<nums.size();i++){
            c = c%mod + map[target-nums[i]]%mod;

            for(int j=0;j<i;j++)
                map[nums[i]+nums[j]]++;
        }
        return c;
    }
};