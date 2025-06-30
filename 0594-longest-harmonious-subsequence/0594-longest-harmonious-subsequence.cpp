class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int, int> mp;
        for (auto el : nums)
            mp[el]++;
        int mx = 0;

        for (auto el : mp) {
            int mnn = el.first - 1;
            int mxx = el.first + 1;

            if (mp.find(mnn) != mp.end()) {
                mx = max(mx, mp[mnn] + el.second);
            }

            if (mp.find(mxx) != mp.end()) {
                mx = max(mx, mp[mxx] + el.second);
            }
        }

        return mx;
    }
};