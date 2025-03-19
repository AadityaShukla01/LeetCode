class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        // 1001
        // 1110
        int cnt = 0;
        vector<int>f(n, 0);

        for(int i=0; i<n; i++)
        {
            if(nums[i] == 0)
            {
                if(f[i] % 2 == 0)
                {
                    cnt++;
                    if(i + 2 < n)
                    {
                        f[i + 1]++;
                        f[i + 2]++;
                    }
                    else return -1;
                }
            }
            else
            {
                if(f[i] % 2)
                {
                    cnt++;
                    if(i + 2 < n)
                    {
                        f[i + 1]++;
                        f[i + 2]++;
                    }
                    else return -1;
                }
            }
        }
        return cnt;
    }
};