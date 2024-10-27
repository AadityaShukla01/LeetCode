class Solution {
public:
    // checkd solution
    // first form new graph
    // then get subtree size
    // mistake -> 2 will not be ancestor of 4 ancestors of 4 will be 1 & 0
    map<int, set<int>>adj;
    vector<int>ss;
    void findAncestor(int curr_node, int node, string &s, vector<int>&parent)
    {
        if(curr_node == -1) return;

        if(s[node] == s[curr_node])
        {
            adj[parent[node]].erase(node);
            adj[curr_node].insert(node);
            return;
        }

        findAncestor(parent[curr_node], node, s, parent);
    }
    void dfs(int src)
    {
        ss[src] = 1;
        for(auto node: adj[src])
        {
            dfs(node);
            ss[src] += ss[node];
        }
    }
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        ss.resize(n, 0);
        for(int i=0; i<n; i++)
        {
            if(parent[i] == -1) continue;

            adj[parent[i]].insert(i);
        }
        for(int i=0; i<n; i++)
        {
            findAncestor(parent[i], i, s, parent);
        }

        dfs(0);

        return ss;
    }
};