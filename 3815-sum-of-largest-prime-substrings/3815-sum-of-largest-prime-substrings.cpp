class Solution {
public:
    bool checkPrime(string& s) {
        if (s.size() == 0)
            return false;
        long long num = stol(s);
        if (num == 1)
            return false;
        for (long long j = 2; 1LL * j * j <= num; j++) {
            if (num % j == 0)
                return false;
        }
        return true;
    }
    set<long long> set;
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    void sol(int i, int n, string& s) {
        if (i >= n) {
            return;
        }

        for (int j = i; j < n; j++) {
            string temp = s.substr(i, j - i + 1);
            if (checkPrime(temp)) {
                long long num = stol(temp);
                if (set.find(num) == set.end()) {
                    set.insert(num);
                    pq.push(num);
                    if (pq.size() > 3)
                        pq.pop();
                    sol(n, n, s);
                }
            }
        }

        sol(i + 1, n, s);
    }
    long long sumOfLargestPrimes(string s) {
        int n = s.size();
        sol(0, n, s);
        long long ans = 0;
        while (pq.empty() == false) {
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};