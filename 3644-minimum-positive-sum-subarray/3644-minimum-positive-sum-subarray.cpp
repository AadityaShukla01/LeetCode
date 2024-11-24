class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        vector<int>ps(n);
        int sum = 0;
        for(int i=0; i<n; i++)
        {
            sum += nums[i];
            ps[i] = sum;
        }

        int mn = 1e9;
        for(int len=l; len<=r; len++)
        {
            for(int i=0; i<n; i++)
            {
                if(i + len - 1 >= n) break;
                if(i == 0)
                {
                    int sm = ps[len - 1];
                    if(sm > 0)
                        mn = min(mn, sm);
                }
                else{
                    int sm = ps[i + len - 1] - ps[i - 1];
                    if(sm > 0)
                        mn = min(mn, sm);
                }
            }
        }
        return mn != 1e9 ? mn : -1;
    }
};