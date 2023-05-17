class Solution {
public:
    int mySqrt(int x) {
       if(x==0) return 0;
       int i=1;
       int j=x;
       int m=0;
       while(i<=j){
           m=(i)+(j-i)/2;
           if(m == x/m)
                return m;
           else if(m < x/m)
                i=m+1;
           else 
                j=m-1;
       }
       return j;
    }
};