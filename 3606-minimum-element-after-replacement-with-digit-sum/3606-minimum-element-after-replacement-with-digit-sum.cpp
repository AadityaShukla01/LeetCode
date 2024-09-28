class Solution {
public:
    int minElement(vector<int>& nums) {
        int mn = INT_MAX;

        for(auto el: nums)
        {
            int sum = 0;
            string s = to_string(el);
            for(auto c: s) sum += (c - '0');
            mn = min(mn, sum);
        }
        return mn;
    }
};