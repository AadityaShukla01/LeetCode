class Solution {
public:
    bool isSymmetric(int a) {
        string aa = to_string(a);
        int n = aa.size();
        if (n % 2)
            return false;

        int len = n / 2;
        int i = 0, j = n - 1;
        int sum1 = 0, sum2 = 0;
        while (i < len) {
            sum1 += aa[i] - '0';
            sum2 += aa[j] - '0';
            i++;
            j--;
        }
        return sum1 == sum2;
    }
    int countSymmetricIntegers(int low, int high) {
        int cnt = 0;

        for (int i = low; i <= high; i++) {
            if (isSymmetric(i))
                cnt++;
        }
        return cnt;
    }
};