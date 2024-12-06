class Solution {
public:
    int sol(map<int, int>&mp, int mi, int maxSum, int n)
    {
        int sum = 0;
        int cnt = 0;
        for(int i=1; i<=n; i++)
        {
            if(!mp[i])
            {
                cnt++;
                sum += i;
            }
            if(sum > maxSum)
            {
                return (cnt - 1) >= mi;
            }
        }

        return cnt >= mi;
    }
    int maxCount(vector<int>& banned, int n, int maxSum) {
        map<int, int>mp;
        for(auto el: banned)mp[el]++;

        int lo = 0;
        int hi = n;
        int ans = -1;
        while(lo <= hi)
        {
            int mi = lo + (hi - lo)/2;

            if(sol(mp, mi, maxSum, n))
            {
                ans = mi;
                lo = mi + 1;
            }
            else{
                hi = mi - 1;
            }
        }
        return ans;
    }
};