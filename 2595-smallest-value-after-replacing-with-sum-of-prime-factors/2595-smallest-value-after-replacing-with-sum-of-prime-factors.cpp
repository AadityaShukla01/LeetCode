class Solution {
public:
    vector<int> notPrime;
    void calc(int n) {
        notPrime.resize(n + 1, 0);
        for (int i = 2; i <= n; i++) {
            if (notPrime[i])
                continue;
            for (long long j = 1LL*i * i; j <= n; j += i) {
                notPrime[j] = 1;
            }
        }
    }
    int smallestValue(int n) {
        calc(n);
        vector<int> s;
        for (int i = 2; i <= n; i++) {
            if (!notPrime[i])
                s.push_back(i);
        }

        while (notPrime[n]) {
            int i = 0;
            int temp = 0;
            int orig = n;
            while (i < s.size()) {
                if (n % s[i] == 0) {
                    while (n % s[i] == 0) {
                        temp += s[i];
                        n = n / s[i];
                    }
                }
                if(n == 1) break;
                i++;
            }
            if(temp == orig) return orig;
            if(temp) n = temp;
        }
        return n;
    }
};