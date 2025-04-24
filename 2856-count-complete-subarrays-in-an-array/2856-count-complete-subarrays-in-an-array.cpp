class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int total_distinct_elements = 0;
        int n = nums.size();
        map<int, int>mp;

        for(auto el: nums) mp[el]++;
        total_distinct_elements = mp.size();
        mp.clear();
        int cnt = 0;
        int i = 0, j = 0;

        while(i < n && j < n)
        {
            mp[nums[i]]++;

            if(mp.size() == total_distinct_elements){
                while(mp.size() == total_distinct_elements){
                    cnt += n - i;
                    mp[nums[j]]--;
                    if(mp[nums[j]] == 0) mp.erase(nums[j]);
                    j++;
                }
            }
            i++;
        }
        return cnt;
    }
};