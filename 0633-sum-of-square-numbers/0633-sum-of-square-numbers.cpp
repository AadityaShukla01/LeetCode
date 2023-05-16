class Solution {
public:
    bool judgeSquareSum(int c) {
        int i=0;
        int j=sqrt(c);
        while(i<=j){
            long ans=(long)(i*i)+(long)(j*j);
            if(ans==c) return true;
            if(ans>c) j--;
            else i++;
        }
        return false;
    }
};