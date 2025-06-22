class Solution {
public:
    bool checkPrimeFrequency(vector<int>& nums) {
        vector<int> isPrime(101, 1);
        isPrime[1] = 0;
        for (int j = 2; j < 101; j++) {
            for (int i = 2; i < j; i++) {
                if (j % i == 0)
                    isPrime[j] = 0;
            }
        }

        map<int, int> mp;
        for (auto it : nums)
            mp[it]++;

        for (auto it : mp) {
            if (isPrime[it.second])
                return true;
        }
        return false;
    }
};