class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();

        int cnt = n;
        map<int, int>mp;
        for(auto el: nums) mp[el]++;
        int i = 0;
        int op = 0;
        while(mp.size() != cnt)
        {
            op++;
            if(i + 2 >= n) break;
            mp[nums[i]]--;
            mp[nums[i + 1]]--;
            mp[nums[i + 2]]--;

            if(mp[nums[i]] == 0) mp.erase(nums[i]);
            if(mp[nums[i + 1]] == 0) mp.erase(nums[i + 1]);
            if(mp[nums[i + 2]] == 0) mp.erase(nums[i + 2]);

            cnt -= 3;
            i+=3;
        }
        return op;
    }
};