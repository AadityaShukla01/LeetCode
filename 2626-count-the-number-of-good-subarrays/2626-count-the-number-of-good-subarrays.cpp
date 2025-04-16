class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0;

        map<int, int>mp;
        long long cnt = 0;
        long long total = 0;
        while(i < n)
        {
            mp[nums[i]]++;

            int f = mp[nums[i]];
            total += (f - 1);

            if(total >= k)
            {
                while(total >= k)
                {
                    cnt += (n - i);
                    int curr = mp[nums[j]];
                    total -= (curr - 1);
                    mp[nums[j]]--;
                    j++;                    
                }
            }
            i++;
        }
        return cnt;
    }
};