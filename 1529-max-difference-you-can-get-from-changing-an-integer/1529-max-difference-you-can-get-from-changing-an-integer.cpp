class Solution {
public:
    int maxDiff(int num) {
        string num1 = "", num2 = "";

        string s = to_string(num);
        int n = s.size();
        string mx = "0", mn = "99999999";
        for (char j = '1'; j <= '9'; j++) {
            for (char k = '0'; k <= '9'; k++) {
                string temp = "";
                for (int i = 0; i < n; i++) {
                    if (s[i] == k) {
                        temp += j;
                    }
                    else temp += s[i];
                }
                mx = max(mx, temp);
            }
        }

        for (char j = '0'; j <= '9'; j++) {
            for (char k = '0'; k <= '9'; k++) {
                string temp = "";
                for (int i = 0; i < n; i++) {
                    if(i == 0 && j == '0' && s[i] == k) {
                        temp = "99999999";
                        break;
                    }
                    if (s[i] == k) {
                        temp += j;
                    }
                    else temp += s[i];
                }
                mn = min(mn, temp);
            }
        }
        
        int n1 = stoi(mn), n2 = stoi(mx);

        return n2 - n1;
    }
};