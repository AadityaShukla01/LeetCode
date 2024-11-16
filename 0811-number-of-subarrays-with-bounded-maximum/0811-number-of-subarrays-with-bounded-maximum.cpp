class Solution {
public:
    int sol(vector<int>&nums, int num)
    {
        int i = 0, j = 0;
        int n = nums.size();
        map<int, int>mp;
        multiset<int>ms;
        int cnt = 0;
        while(i < n)
        {
            mp[nums[i]]++;
            ms.insert(nums[i]);

            while(ms.empty() == false && *ms.rbegin() > num)
            {
                mp[nums[j]]--;
                if(mp[nums[j]] == 0)
                {
                    mp.erase(nums[j]);
                    ms.erase(nums[j]);
                }
                j++;
            }

            cnt += (i - j + 1);

            i++;
        }
        return cnt;
    }
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        return sol(nums, right) - sol(nums, left - 1);
    }
};