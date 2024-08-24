class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.size(), m = b.size();

        int carry = 0;

        string ans = "";
        int i = n - 1, j = m - 1;
        int p = 0, q = 0;
        while(i >= 0 || j >= 0){
            if(i >= 0) 
                p = a[i] - '0';
            else p = 0;

            if(j >= 0)
                q = b[j] - '0';
            else 
                q = 0;

            int sum = (p + q + carry);

            carry = sum/2;

            ans += to_string(sum % 2);

            i--;
            j--;
        }

        if(carry) ans += to_string(carry);

        reverse(ans.begin(), ans.end());
        return ans;
    }
};