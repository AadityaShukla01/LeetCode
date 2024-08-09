class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum = 0;
        map<int, int>mp;
        int n = nums.size();
        int maxLen = 0;
        mp[0] = -1;
        for(int i=0; i<n; i++){
            if(nums[i] == 0) sum += -1;
            else sum += 1;

            if(mp.find(sum) != mp.end()){
                maxLen = max(maxLen, i - mp[sum]);
            }

            if(mp.find(sum) == mp.end())
                mp[sum] = i;
        }
        return maxLen;
    }
};