class Solution {
public:
    // Good sliding window question
    int maxFreeTime(int eventTime, int k, vector<int>& startTime,
                    vector<int>& endTime) {
        int n = startTime.size(), sum = 0;
        vector<int> gap(n + 1, 0);

        gap[0] = startTime[0];
        gap[n] = eventTime - endTime[n - 1];
        
        for (int i = 1; i < n; i++) {
            gap[i] = startTime[i] - endTime[i - 1];
        }

        for (int i = 0; i <= k; i++) {
            sum += gap[i];
        }

        int mx = sum;

        for (int i = k + 1; i <= n; i++) {
            sum += gap[i];
            sum -= gap[i - (k + 1)];

            mx = max(mx, sum);
        }
        return mx;
    }
};