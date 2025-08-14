class Solution {
public:
    string largestGoodInteger(string num) {
        int mx = -1;

        int i = 0;

        while (i < num.size()) {
            char c = num[i];
            int cnt = 0;
            while (i < num.size() && c == num[i]) {
                cnt++;
                i++;
            }

            if (cnt >= 3) {
                mx = max(mx, c - '0');
            }
        }

        return mx == -1 ? "" : to_string(mx) + to_string(mx) + to_string(mx);
    }
};