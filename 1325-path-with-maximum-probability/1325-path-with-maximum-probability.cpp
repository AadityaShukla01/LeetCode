class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<int, double>> adj[100001];
        int i = 0;
        vector<double> ans(n, 0);
        for (auto e : edges) {
            int a = e[0], b = e[1];
            adj[a].push_back({b, succProb[i]});
            adj[b].push_back({a, succProb[i]});

            i++;
        }

        priority_queue<pair<double, int>> pq;

        pq.push({1.0, start});

        while (pq.empty() == false) {
            int node = pq.top().second;
            double prob = pq.top().first;
            pq.pop();

            ans[node] = max(ans[node], prob);

            for (auto it : adj[node]) {
                int src = it.first;
                double p = it.second;
                if (ans[src] < p*prob*1.0) {
                    pq.push({1.0 * p * prob, src});
                }
            }
        }

        return ans[end];
    }
};