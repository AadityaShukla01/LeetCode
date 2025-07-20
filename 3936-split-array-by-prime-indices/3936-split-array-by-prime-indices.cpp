class Solution {
public:
    long long splitArray(vector<int>& nums) {
        long long sumA = 0, sumB = 0;
        int n = nums.size();

        vector<int> prime(n, 1);
        prime[0] = 0;
        if(n > 1)
            prime[1] = 0;
        for (int i = 2; i * i < n; i++) {
            if (!prime[i])
                continue;
            for (int j = i * i; j < n; j += i) {
                prime[j] = 0;
            }
        }

        for(int i=0; i<n; i++){
            if(prime[i]) sumA += nums[i];
            else sumB += nums[i];
        }

        return abs(sumA - sumB);
    }
};