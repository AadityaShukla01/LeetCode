class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        map<int, int>mp;
        int pre = nums[0] - k;
        mp[pre]++;
        for(int i=1; i<n; i++)
        {
            if(pre < nums[i]){
                if(nums[i] - (pre + 1) <= k)
                {
                    pre = pre + 1;
                    mp[pre]++;
                }
                else if(mp.find(nums[i] - k) == mp.end())
                {
                    pre = nums[i] - k;
                    mp[pre]++;
                }
                else mp[nums[i]]++;
            }
            else{
                if(pre + 1 - nums[i] <= k)
                {
                    pre = pre + 1;
                    mp[pre]++;
                }
                else mp[nums[i]]++;
            }
        }
        return mp.size();
    }
};