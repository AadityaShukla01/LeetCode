class Solution {
public:
    int getSum(int a, int b) {
        int ans = 0;
        int carry = 0;
        for(int i=0; i<32; i++){
            int seta = a & (1 << i);
            int setb = b & (1 << i);

            if(seta && setb && carry){
                carry = 1;
                ans = ans | (1 << i);
            }
            else if((seta && setb) || (seta && carry) || (setb && carry)){
                carry = 1;
            }
            else if(seta || setb || carry){
                carry = 0;
                ans = ans | (1 << i);
            }
            else{
                carry = 0;
            }
        }
        return ans;
    }
};