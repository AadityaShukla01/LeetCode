class Solution {
public:
    long long mx;
    long long getNum(long long num, long long mult)
    {
        if(num > mx) return 0;
        long long m = 1LL * mult * (mult + 1)/2;
        return 1LL * num * m;
    }
    int fn(long long m, int num, int n)
    {
        long long lo = 1;
        long long hi = 1e6;
        int ans = -1;
        while(lo <= hi)
        {
            long long mi = lo + (hi - lo)/2;

            if(getNum(num, mi) <= 1LL * m)
            {
                ans = mi;
                lo = mi + 1;
            }
            else 
                hi = mi - 1;
        }
        
        return ans;
    }
    bool check(long long mi, int mountainHeight, vector<int>& workerTimes)
    {
        int n = workerTimes.size();
        int cnt = 0;
        for(int i=0; i<n; i++)
        {
            long long time = fn(mi, workerTimes[i], n);
            if(time == -1) continue;
            cnt += time;
            if(cnt >= mountainHeight) return true;
        }
        return cnt >= mountainHeight;
    }
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        int n = workerTimes.size();
        mx = *max_element(workerTimes.begin(), workerTimes.end());
        long long lo = 0;
        sort(workerTimes.begin(), workerTimes.end());
        long long hi = 1e18;
        long long ans = -1;
        while(lo <= hi)
        {
            long long mi = lo + (hi - lo)/2;

            if(check(mi, mountainHeight, workerTimes))
            {
                ans = mi;
                hi = mi - 1;
            }
            else lo = mi + 1;
        }
        return ans;
    }
};