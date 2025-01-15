class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int setBits = 0;
        for(int i=0; i<32; i++){
            if(num2 & (1 << i)) setBits++;
        }
        int ans = 0;
        for(int i=31; i>=0; i--){
            if(num1 & (1 << i)){
                if(setBits){
                    setBits--;
                    ans |= (1 << i);
                } 
            }
        }

        int i = 0;
        while(setBits > 0){
            if(num1 & (1 << i)) 
            {   
                i++;
                continue;
            }
            else{
                setBits--;
                ans |= (1 << i);
                i++;
            }
        }
        
        return ans;
    }
};