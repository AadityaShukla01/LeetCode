class Solution {
public:
    long long maxScore(vector<int>& nums) {
        int n = nums.size();

        long long mx = -1e18;
        long long gcd = -1;
        long long ngcd = -1, nlcm = -1;
        for(int i=0; i<n; i++)
        {
            if(ngcd == -1)
            {
                ngcd = nums[i];
                nlcm = nums[i];
            }
            else
            {
                ngcd = __gcd(ngcd, 1LL * nums[i]);
                nlcm = 1LL * (nlcm * nums[i]) / (__gcd(nlcm, 1LL * nums[i]));
            }
            long long lcm = -1;
            for(int j=0; j<n; j++)
            {
                if(i != j)
                {
                    if(lcm == -1) {
                        lcm = nums[j];
                        gcd = nums[j];
                    }
                    else{
                        gcd = __gcd(1LL * nums[j], gcd);
                        lcm = 1LL * lcm * (nums[j]) / __gcd(1LL * nums[j], lcm);
                    }
                }
            }
            
            // cout << lcm * gcd << "\n";
            mx = max(mx, 1LL * lcm * gcd);
        }

        // cout << gcd << " " << num << "\n";
        return max(mx, 1LL * ngcd * nlcm);
    }
};