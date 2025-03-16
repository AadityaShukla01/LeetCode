class Solution {
public:
    int sol(int mi, vector<int>&candies, long long k)
    {
        long long cnt = 0;

        for(auto c: candies){
            cnt += c / mi;
        }
        return cnt >= k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int lo = 1, hi = *max_element(candies.begin(), candies.end());
        int ans = 0;
        while(lo <= hi)
        {
            int mi = lo + (hi - lo)/2;

            if(sol(mi, candies, k))
            {
                ans = mi;
                lo = mi + 1;
            }
            else hi = mi - 1;
        }
        return ans;
    }
};