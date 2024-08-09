class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int>temp;
        int n = digits.size();
        int i = n - 1;

        int carry = 1;
        while(i >= 0){
            int sum = digits[i] + carry;
            temp.push_back(sum % 10);
            carry = sum / 10;
            i--;
        }

        if(carry) temp.push_back(carry);

        reverse(temp.begin(), temp.end());
        return temp;
    }
};