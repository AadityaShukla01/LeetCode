class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2,
                                 int k) {
        int n = nums1.size();
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
            v.push_back({nums1[i], i});

        sort(v.begin(), v.end());

        vector<long long> ans(n);
        priority_queue<int, vector<int>, greater<int>> pq;
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            int curr_num = v[i].first;
            int j = i;
            while (j < n && curr_num == v[j].first) {
                ans[v[j].second] = sum;
                j++;
            }

            for (int l = i; l < j; l++) {
                pq.push(nums2[v[l].second]);
                sum += nums2[v[l].second];
                if (pq.size() > k) {
                    sum -= pq.top();
                    pq.pop();
                }
            }
            i = j - 1;
        }
        return ans;
    }
};