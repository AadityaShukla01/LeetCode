class Solution {
public:
    int findComplement(int num) {
        int index = -1;
        for(int i=30; i>=0; i--){
            if(num & (1 << i)) {
                index = i;
                break;
            }
        }
        
        int ans = 0;
        for(int i=index; i>=0; i--){
            if(num & (1 << i)) continue;
            else ans = ans | (1 << i);
        }
        return ans;
    }
};