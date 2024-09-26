class Solution {
public:
    bool canPlaceFlowers(vector<int>& a, int op) {
        int n = a.size();
        int i = 0;
        int cnt = 0;
        while(i < n && a[i] == 0) i++;
        cnt += i/2;
        if(i == n)
        {
            int m;
            if(n % 2) m = n/2 + 1;
            else m = n/2;

            return m >= op;
        }
        int j = n - 1;
        while(j >= i && a[j] == 0) j--;

        cnt += (n - j - 1)/2;
        // cout << i << " " << j << "\n";
        while(i < j)
        {
            if(a[i] == 0)
            {
                int len = 0;
                while(i < j && a[i] == 0)
                {
                    len++;
                    i++;
                }
                // cout << len << "\n";
                if(len % 2 == 0) cnt += (len)/2 - 1;
                else cnt += len/2;
            }
            i++;
        }
        // cout << cnt << "\n";
        // ping pong
        return cnt >= op;
    }
};