class Solution {
public:
    vector<int> adj[100001];
    vector<int> getDist(int src, vector<int>& vis, int n) {
        queue<pair<int, int>> q;
        q.push({src, 0});
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        while (q.empty() == false) {
            int src = q.front().first;
            int wt = q.front().second;

            q.pop();

            vis[src] = 1;

            for (auto el : adj[src]) {
                if (!vis[el]) {
                    dist[el] = wt + 1;
                    q.push({el, wt + 1});
                }
            }
        }
        return dist;
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        for (int i = 0; i < n; i++) {
            if(edges[i] == -1) continue;
            adj[i].push_back(edges[i]);
        }
        int mn = INT_MAX, ans = -1;
        vector<int> vis1(n, 0), vis2(n, 0);
        vector<int> dist1 = getDist(node1, vis1, n);
        vector<int> dist2 = getDist(node2, vis2, n);

        for (int i = 0; i < n; i++) {
            int val = max(dist1[i], dist2[i]);
            if(val < mn){
                mn = val;
                ans = i;
            }
        }
        return ans;
    }
};