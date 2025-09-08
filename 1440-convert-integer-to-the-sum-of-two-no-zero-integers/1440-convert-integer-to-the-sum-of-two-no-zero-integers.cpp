class Solution {
public:
    bool nonZero(int n){
        while(n){
            int dig = n % 10;
            n /= 10;

            if(!dig) return false;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        for(int i=1; i<n; i++){
            if(nonZero(i) && nonZero(n - i)) return {i, n - i};
        }
        return {};
    }
};