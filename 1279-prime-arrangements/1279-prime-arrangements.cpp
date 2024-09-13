class Solution {
public:
    const int mo = 1e9 + 7;
    int factn(int n)
    {
        long long ans = 1;
        for(int i=1; i<=n; i++){
            ans = 1LL * ans * i;
            ans %= mo;
        }

        return ans % mo;
    }
    int countPrimes(int n) {
        int count = 0;
        vector<int> notPrime(n + 1, false);

        for (int i = 2; i <= n; i++) {
            if (notPrime[i])
                continue;

            count++;

            for (int j = i * i; j <= n; j += i) {
                notPrime[j] = true;
            }
        }
        return count;
    }
    int numPrimeArrangements(int n) {
        
        int primes = countPrimes(n), nonPrimes = n - primes;
        long long ans =  1LL *factn(primes) * factn(nonPrimes);
        return ans % mo;
    }
};