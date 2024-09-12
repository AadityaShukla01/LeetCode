class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        int n = arr.size();
        vector<long long> ans(n);
        unordered_map<int, vector<int>> indexes;
        for (int i = 0; i < n; i++) {
            indexes[arr[i]].push_back(i);
        }
        for (auto ind : indexes) {
            vector<int> t = ind.second;

            long long rytSum = 0;
            for (auto el : t)
                rytSum += el;
            long long leftSum = 0;
            for (int i = 0; i < t.size(); i++) {
                leftSum += t[i];
                rytSum -= t[i];

                ans[t[i]] = 1LL*(i + 1) * t[i] - leftSum + rytSum - 1LL*t[i] * (t.size() - i - 1);
            }
        }
        return ans;
    }
};