
class DisjointSet{
public:
    vector<int>size, parent;
    DisjointSet(int n)
    {
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for(int i=1; i<=n; i++) parent[i] = i;
    }

    int findParent(int a)
    {
        if(a == parent[a]) return a;

        return parent[a] = findParent(parent[a]);
    }

    int union_sz(int a, int b)
    {
        int p_a = findParent(a);
        int p_b = findParent(b);

        if(p_a == p_b) return 0;

        if(size[p_a] > size[p_b])
        {
            size[p_a] += size[p_b];
            parent[p_b] = p_a;
        }
        else
        {
            size[p_b] += size[p_a];
            parent[p_a] = p_b;
        }
        return 1;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DisjointSet ds(n);

        for(auto e: edges)
        {
            int a = e[0], b = e[1];

            
            int res = ds.union_sz(a, b);
            if(!res) return e;
        }
        return {-1};
    }
};