class Solution {
public:
    vector<int>vis;
    vector<int>subtreeSize;
    vector<int>adj[100001];
    int count;
    int dfs(int node, int par){
        int curr_size = 1;
        for(auto child: adj[node]){
            if(child != par){
                curr_size += dfs(child, node);
            }
        }

        subtreeSize[node] = curr_size;
        return curr_size;
    }
    void calc(int node, int par){
        set<int>s;

        for(auto child: adj[node]){
            if(child != par){
                s.insert(subtreeSize[child]);
            }
        }

        if(s.size() == 0 || s.size() == 1)
            count++;

        for(auto child:adj[node]){
            if(child != par){
                calc(child, node);
            }
        }
    }
    int countGoodNodes(vector<vector<int>>& edges) {
        int n = edges.size();
        count = 0;
        subtreeSize.resize(n + 1, 0);
        for(auto e: edges){
            int a = e[0];
            int b = e[1];

            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        dfs(0, -1);
        calc(0, -1);

        return count;
    }
};