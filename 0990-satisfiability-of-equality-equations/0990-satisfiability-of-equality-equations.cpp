
class DisjointSet{
    vector<int>rank,parent; 
    public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);

        for(int i=0;i<=n;i++){
         parent[i]=i;
        }
    }
        int parentNode(int n){
            if(n==parent[n]) return n;

            return parent[n]=parentNode(parent[n]);
        }
        void unionByRank(int a,int b){
            int u_a=parentNode(a);
            int u_b=parentNode(b);

            if(u_a==u_b) return;

            if(rank[u_a]>rank[u_b]){
                parent[u_b]=u_a;
            }
            else if(rank[u_b]>rank[u_a]){
                parent[u_a]=u_b;
            }
            else{
                parent[u_a]=u_b;
                rank[u_b]++;
        }
    }
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        int n=equations.size();
        DisjointSet ds(26);

        for(auto e:equations){
            if(e[1] == '='){
                ds.unionByRank(e[0]-'a',e[3]-'a');
            }
        }
        for(auto e:equations){
            if(e[1]=='!'){ 
                if(ds.parentNode(e[0]-'a')==ds.parentNode(e[3]-'a'))
                    return false;
            }
        }
        return true;
    }
};