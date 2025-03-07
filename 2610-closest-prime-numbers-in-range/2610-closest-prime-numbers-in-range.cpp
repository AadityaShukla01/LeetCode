class Solution {
public:
    vector<int>primes; //to store all prime numbers from 1 to n
    void listPrime(int n){
        vector<int>factor(n+1);
        for(int i=0; i<n+1; i++)
            factor[i] = i;
        
        for(long long i=2; i<=n; i++){
            if(factor[i] == i)
                primes.push_back(i);
            
            for(long long l=i*i; l<=n; l+=i){
                factor[l] = i; //mark all nos divisible by prime no i
            }
        }
    }
    // Solution(){
    //     listPrime(1e6);   
    // }
    vector<int> closestPrimes(int left, int right) {
        int first = -1;
        listPrime(1e6);  
        int second = -1;
        int res = 1e9;
        for(int i=0; i<primes.size()-1; i++){
            if(primes[i] >= left && primes[i] <= right && primes[i+1] >= left && primes[i+1] <= right){
                int gap = primes[i+1] - primes[i];
                if(gap < res){
                    first = primes[i];
                    second = primes[i+1];
                    res = gap;
                }
            }
        }
        if(first != -1 && second != -1)
            return {first, second};
        return {-1, -1};
    }
};