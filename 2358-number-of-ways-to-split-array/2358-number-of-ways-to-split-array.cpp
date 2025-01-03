class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long sum = 0;
        int n = nums.size();
        int cnt = 0;
        long long remSum = 0;
        
        for(auto el: nums) remSum += el;

        for(int i=0; i<n-1; i++)
        {
            sum += nums[i];
            remSum -= nums[i];

            if(sum >= remSum) cnt++;
        }
        return cnt;
    }
};