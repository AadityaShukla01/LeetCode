class Solution {
public:
    bool isPerfectSquare(int num) {
        long long left = 1;
        long long right = num;
        long long ans = 0;
        while(left <= right){
            long long mid = left+ (right-left)/2;
            if(mid * mid >= num){
                ans = mid;
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return(long) ans*ans == num;
    }
};