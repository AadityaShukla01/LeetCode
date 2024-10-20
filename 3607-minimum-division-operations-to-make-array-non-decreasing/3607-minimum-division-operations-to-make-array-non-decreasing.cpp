class Solution {
public:
    int getDivisor(int num)
    {
        int mx = -1;
        for(int j=2; j*j <= num; j++)
        {
            if(num %j == 0)
            {
                int a = j;
                int b = num / j;
                mx = max({mx, a, b});
                break;
            }
        }
        if(mx == -1) return 1e9;
        return mx;
    }
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int pre = nums[n - 1];
        int cnt = 0;
        for(int i=n-1; i>=0; i--)
        {
            if(nums[i] <= pre)
            {
                pre = nums[i];
            }
            else
            {
                int div = getDivisor(nums[i]);
                if(div == 1e9) return -1;
                if(nums[i]/div > pre) return -1;
                pre = nums[i] / div;
                cnt++;
            }
        }
        
        return cnt;
    }
};