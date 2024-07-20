class Solution {
public:
    string addStrings(string num1, string num2) {
        int carry = 0;
        int sum = 0;
        string res = "";

        int i = num1.size() - 1;
        int j = num2.size() - 1;

        while (i >= 0 || j >= 0) {
            int a = 0;
            int b = 0;
            if (i >= 0)
                a = num1[i] - '0';
            if (j >= 0)
                b = num2[j] - '0';

            sum = a + b + carry;
            carry = sum / 10;
            sum = sum % 10;

            res += to_string(sum);
            i--;
            j--;
        }
        if (carry)
            res += to_string(carry);
        reverse(res.begin(), res.end());
        return res;
    }
};