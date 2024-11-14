class Solution {
public:
    int sol(int mi, vector<int>&q)
    {
        int cnt = 0;
        for(auto el: q)
        {
            if(el % mi)
            {
                cnt += el / mi + 1;
            }
            else cnt += el / mi;
        }
        return cnt;
    }
    int minimizedMaximum(int n, vector<int>& q) {
        int lo = 1;
        int hi = *max_element(q.begin(), q.end());
        int ans = -1;
        while(lo <= hi)
        {
            int mi = lo + (hi - lo)/2;
            int res = sol(mi, q);
            if(res > n)
            {
                lo = mi + 1;
            }
            else {
                ans = mi;
                hi = mi - 1;
            }
        }
        int cnt = 0;
        for(auto el: q)
        {
            if(el % 19)
            {
                cnt += (el / 19) + 1;
            }
            else cnt += el / 19;
        }

        cout << cnt << "\n";
        return ans;
    }
};