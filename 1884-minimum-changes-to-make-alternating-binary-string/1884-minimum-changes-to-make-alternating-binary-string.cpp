class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int op1 = 0;
        int op2 = 0;

        for(int i=0; i<n; i++){
            if(s[i] == '0' && i % 2 == 0) op1++;
            if(s[i] == '1' && i % 2) op1++;
        }

        for(int i=0; i<n; i++){
            if(s[i] == '1' && i % 2 == 0) op2++;
            if(s[i] == '0' && i % 2) op2++;
        }

        return min(op1, op2);
    }
};