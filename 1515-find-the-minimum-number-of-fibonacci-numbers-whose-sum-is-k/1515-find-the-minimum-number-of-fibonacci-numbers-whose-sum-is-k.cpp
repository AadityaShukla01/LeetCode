class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        int n = 50;
        vector<long long>fib(n);
        fib[1] = 1;
        fib[2] = 1;
        for(int i=3;  i<n; i++){
            fib[i] = fib[i - 1] + fib[i - 2];
        }
        int count = 0;
        for(int i=n-1; i>=1; i--){
            while(fib[i] <= k){
                k -= fib[i];
                count++;
            }
        }
        return count;
    }
};