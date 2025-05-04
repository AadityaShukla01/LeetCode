class Solution {
public:
    int maxProduct(int n) {
        int max_element = -1e9, second_max_element = 1e9;

        while(n){
            int dig = n % 10;
            n /= 10;

            if(dig >= max_element){
                second_max_element = max_element;
                max_element = dig;
            } else{
                second_max_element = max(second_max_element, dig);
            }
        }
        return max_element * second_max_element;
    }
};