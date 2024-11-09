class Solution {
public:
    long long minEnd(int n, int x) {

        long long ans = x;
        long long p = 0;
        long long t = 1LL *x;
        for(int i=0; i<62; i++)
        {   
            long long temp = (1LL << i);
            if((t & temp) == 0)
            {
                int num = n - 1;
                long long temp2 = (1LL << p);
                int div = num / temp2;
                if(div % 2)
                {
                    ans |= (1LL << i);
                }
                p++;
            }
        }
        return ans;
    }
};