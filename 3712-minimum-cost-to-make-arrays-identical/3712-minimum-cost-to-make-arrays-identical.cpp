class Solution {
public:
    long long minCost(vector<int>& arr, vector<int>& brr, long long k) {
        int n = arr.size();
        long long ans = 0;
        vector<pair<int, int>>a, b;

        for(int i=0; i<n; i++) a.push_back({arr[i], i});
        for(int i=0; i<n; i++) b.push_back({brr[i], i});
        long long temp = 0;
        for(int i=0; i<n; i++)
        {
            temp += abs(b[i].first - a[i].first);
        }

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        bool f = 0;
        for(int i=0; i<n; i++)
        {
            if(a[i].second != b[i].second) f = 1;
            // cout << b[i].first << " " << a[i].first << endl;
            ans += abs(b[i].first - a[i].first);
        }

        return min(temp, ans + ((f == true) ? k : 0));
    }
};