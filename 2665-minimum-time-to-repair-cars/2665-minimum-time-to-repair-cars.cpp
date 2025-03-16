class Solution {
public:
    // took help
    bool sol(long long mi, vector<int>&ranks, int cars)
    {
        long long cnt = 0;

        for(auto r : ranks)
        {
            cnt += sqrt(mi / r);
        }

        return cnt >= cars;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        long long lo = 0, hi = 1e14;
        long long ans = -1;
        while(lo <= hi)
        {
            long long mi = lo + (hi - lo)/2;

            if(sol(mi, ranks, cars))
            {
                ans = mi;
                hi = mi - 1;
            }
            else lo = mi + 1;
        }
        return ans;
    }
};