class Solution {
public:
    int minFlips(int a, int b, int c) {
        int count=0;
        while( a || b || c){
            //to check for every bit
            int an = a&1;
            int bn = b&1;
            int cn = c&1;
            if(an==1 && bn==1 && cn==0)
                count+=2;
            if(an==0 && bn==1 && cn==0)
                count++;
            if(an==1 && bn==0 && cn==0)
                count++;
            if(an==0 && bn==0 && cn == 1)
                count++;
            //right shift the numbers
            a>>=1;
            b>>=1;
            c>>=1;
        }
        return count;
    }
};