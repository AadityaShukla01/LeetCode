class Solution {
public:
    int maximumGroups(vector<int>& a) {
        sort(a.begin(), a.end());
        int n = a.size();
        // 3 5 6 10 12
        long long sum = 0;
        int cnt = 0;
        long long preSum = 0, preLen = 0;
        int len = 0;
        for(int i=0; i<n; i++)
        {
            sum += a[i];
            len++;
            if(len > preLen)
            {
                preLen = len;
                preSum = sum;
                len = 0;
                sum = 0;
                cnt++;
            }
        }
        return cnt;
    }
};