class Solution {
public:
    int getSum(int n)
    {
        int sum = 0;
        while(n)
        {
            int dig = n % 10;
            n /= 10;
            sum += dig;
        }
        return sum;
    }
    int countLargestGroup(int n) {
        map<int, int>mp;
        int mx = 0;

        for(int i=1; i<=n; i++)
        {
            int sum = getSum(i);
            mp[sum]++;
            mx = max(mx, mp[sum]);
        }
        int cnt = 0;
        for(auto el: mp){
            if(el.second == mx) cnt++;
        }
        return cnt;
    }
};