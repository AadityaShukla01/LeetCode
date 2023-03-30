
class DisjointSet{
    private:
    vector<int>rank;
    vector<int>parent;
    public:
    DisjointSet(int n){
        rank.resize(n+1,1);
        parent.resize(n+1);

        for(int i=0;i<=n;i++)
            parent[i]=i;
    }
    int parentNode(int n){
        if(n==parent[n]) return n; //wereached parent

        return parent[n]=parentNode(parent[n]);
    }

    bool unionByRank(int a,int b){
        int u_a=parentNode(a);
        int u_b=parentNode(b);

        if(u_a==u_b) //already connected
            return false;
        
        if(rank[a]>rank[b]){
            parent[u_b]=u_a;
            return true;
        }
        else if(rank[b]>rank[a]){
            parent[u_a]=u_b;
            return true;
        }
        else{
            parent[u_a]=u_b;
            rank[u_a]++;
            return true;
        }
    }

};

class Solution {
public:
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        DisjointSet ds(n);
        for(auto it:edges){
            if(!ds.unionByRank(it[0],it[1])) return {it[0],it[1]};
        }
        return {-1,-1};
    }
};