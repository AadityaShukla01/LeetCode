class RangeFreqQuery {
public:
    unordered_map<int, vector<int>> mp;
    RangeFreqQuery(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }
    }

    int query(int left, int right, int value) {
        vector<int>&v = mp[value];
        int lb_l = lower_bound(v.begin(), v.end(), left) - v.begin();
        int lb_r = lower_bound(v.begin(), v.end(), right) - v.begin();

        int cnt = lb_r - lb_l + 1;
        if(lb_r >= v.size() || v[lb_r] > right) cnt--;
        return cnt;
    }
};
