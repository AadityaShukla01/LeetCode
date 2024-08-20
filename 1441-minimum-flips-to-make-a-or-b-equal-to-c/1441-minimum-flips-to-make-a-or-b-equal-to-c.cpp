class Solution {
public:
    int minFlips(int a, int b, int c) {
        int cnt = 0;

        for(int i=0; i<=30; i++){
            int d1 = a & (1 << i);
            int d2 = b & (1 << i);
            int d3 = c & (1 << i);

          

            if((d1 || d2) && d3) continue;
            if(!d1 && !d2 && !d3) continue;
            if((d1 || d2) && !d3){
                if(d1 && d2) cnt += 2;
                else cnt += 1;
            }

            if((!d1 && !d2) && d3){
                cnt += 1;
            }
        }
        return cnt;
    }
};