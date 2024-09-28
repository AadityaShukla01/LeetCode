class Solution {
public:
    long long maximumTotalSum(vector<int>& a) {
        sort(a.begin(), a.end(), greater<int>());
        int i = 0;
        int n = a.size();
        long long sum = 0;
        
        int pre = INT_MAX;
        for(int i=0; i<n;)
        {
            int num = a[i];
            if(num >= pre)
            {
                num = pre - 1;
            }
            int p = a[i];
            while(i < n && a[i] == p)
            {
                pre = num;
                a[i] = pre;
                num--;
                i++;
            }
        }

        for(auto el: a) {
            if(el <= 0) return -1;
        }
        for(auto el: a) sum += el;
        return sum;
    }
};