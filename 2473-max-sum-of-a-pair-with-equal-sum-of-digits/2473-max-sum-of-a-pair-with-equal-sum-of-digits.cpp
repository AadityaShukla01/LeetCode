class Solution {
public:
    int getDigitSum(int num)
    {
        int sum = 0;
        while(num)
        {
            sum += (num % 10);
            num /= 10;
        }

        return sum;
    }
    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        map<int, int>mp;
        int mx = -1;

        for(int i=0; i<n; i++)
        {
            int curr_sum = getDigitSum(nums[i]);
            if(mp.find(curr_sum) != mp.end())
                mx = max(mx, mp[curr_sum] + nums[i]);

            mp[curr_sum] = max(mp[curr_sum], nums[i]);     
        }
        return mx;
    }
};