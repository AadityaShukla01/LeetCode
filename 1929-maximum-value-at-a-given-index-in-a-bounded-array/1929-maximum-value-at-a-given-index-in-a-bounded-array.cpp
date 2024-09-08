class Solution {
public:
    bool sol(int mi, int n, int index, int maxSum)
    {
        int i = index - 1;
        long long sum = 0;
        int num = mi - 1;
        long long preLen = index;
        if(preLen >= num)
        {
            sum += 1LL*num*(num + 1)/2;
            sum += (preLen - num);
        }
        else{
            int mn = num - preLen + 1;
            int len = preLen - 1;
            sum += 1LL*mn * (preLen) + (preLen - 1) *(preLen)/2;
        }
        preLen = n - index - 1;
        if(preLen >= num)
        {
            sum += 1LL*num*(num + 1)/2;
            sum += (preLen - num);
        }
        else{
            int mn = num - preLen + 1;
            int len = preLen - 1;
            sum += 1LL* mn * (preLen) + (preLen - 1) *(preLen)/2;
        }
        sum += mi;
        return sum <= maxSum;
    }
    int maxValue(int n, int index, int maxSum) {
        int lo = 1, hi = 1e9;
        int ans = -1;
        while(lo <= hi)
        {
            int mi = lo + (hi - lo)/2;

            if(sol(mi, n, index, maxSum)){
                ans = mi;
                lo = mi + 1;
            }
            else hi = mi - 1;
        }
        return ans;

    }
};