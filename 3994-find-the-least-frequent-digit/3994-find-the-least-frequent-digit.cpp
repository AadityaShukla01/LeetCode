class Solution {
public:
    int getLeastFrequentDigit(int n) {
        map<int, int> mp;

        while (n) {
            int x = n % 10;
            n /= 10;

            mp[x]++;
        }

        int el = INT_MAX;
        int f = INT_MAX;

        for (auto it : mp) {
            if (it.second < f) {
                f = it.second;
                el = it.first;
            }
        }
        return el;
    }
};