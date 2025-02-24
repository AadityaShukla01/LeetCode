class Solution {
public:
    long long maxSum(vector<vector<int>>& g, vector<int>& limits, int k) {
        int n = g.size(), m = g[0].size();
       
        for (int i = 0; i < n; i++)
            sort(g[i].begin(), g[i].end(), greater<int>());

        priority_queue<int> pq;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (j + 1 <= limits[i])
                    pq.push(g[i][j]);
                else
                    break;
            }
        }

        long long sum = 0;
        while(k--)
        {
            int el = pq.top();
            pq.pop();
            sum += el;
        }
        return sum;
    }
};