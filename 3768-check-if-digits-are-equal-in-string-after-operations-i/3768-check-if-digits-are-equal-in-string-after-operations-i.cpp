class Solution {
public:
    bool hasSameDigits(string s) {
        string temp = s;

        while (temp.size() > 2) {
            string res = "";
            for (int i = 0; i < temp.size() - 1; i++) {
                int digit = ((temp[i] - '0') + (temp[i + 1] - '0')) % 10;

                res += to_string(digit);
            }
            temp = res;
        }

        return temp[0] == temp[1];
    }
};