class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int cnt = 0;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int l = j + 1; l < n; l++) {
                    if (abs(arr[i] - arr[j]) <= a &&
                        abs(arr[l] - arr[j]) <= b && abs(arr[i] - arr[l]) <= c)
                        cnt++;
                }
            }
        }
        return cnt;
    }
};