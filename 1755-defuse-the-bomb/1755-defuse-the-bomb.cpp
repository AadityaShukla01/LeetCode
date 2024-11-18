
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int j = 0;
        int n = code.size();
        int sum = 0;

        k = k % n;
        vector<int> ans(n,0);
        if (k > 0) {
            for (int i = 0; i < k; i++)
                sum += code[i];
            j = k;
            for (int i = 0; i < n; i++) {
                sum -= code[i];
                sum += code[j];
                j++;
                j %= n;
                ans[i] = sum;
            }
            return ans;
        } else if (k == 0) {
            return ans;
        } else {
            int sum = 0;
            for (int i = n - 1; i >= n + k; i--) {
                sum += code[i];
            }
            j = n + k;
            ans[0] = sum;
            for(int i=1; i<n; i++)
            {
                sum -= code[j];
                sum += code[i - 1];
                j++;
                j %= n;
                ans[i] = sum;
            }
            return ans;
        }
    }
};