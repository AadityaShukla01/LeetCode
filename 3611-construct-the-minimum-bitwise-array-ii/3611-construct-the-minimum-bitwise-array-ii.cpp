class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n, -1);

        for(int i=0; i<n; i++)
        {
            int num = nums[i];
            if(num % 2 == 0) continue;
            int op1 = 1e9, op2 = 1e9;
            op1 = num ^ 1;

            if(num & (1 << 1))
            {
                int p;
                for(int i=0; i<32; i++)
                {
                    if(!(num & (1 << i)))
                    {
                        p = i;
                        break;
                    }
                }

                p--;
                op2 = num ^ (1 << p);
            }
            ans[i] = min(op1, op2);
        }
        return ans;
    }
};