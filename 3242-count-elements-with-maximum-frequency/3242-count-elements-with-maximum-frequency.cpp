class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int, int> mp;
        int ans = 0, mxFreq = 0;
        for (auto el : nums) {
            mp[el]++;
            mxFreq = max(mxFreq, mp[el]);
        }

        for (auto it : mp) {
            if (it.second == mxFreq)
                ans += it.second;
        }
        return ans;
    }
};