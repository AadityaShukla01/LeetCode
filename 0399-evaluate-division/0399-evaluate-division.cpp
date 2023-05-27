class Solution {
public:
    void dfs(string src,string dst,unordered_set<string> &visited,
    unordered_map<string,vector<pair<string,double>>> &adj,double product, double &ans){
        //check if its visited or not
        if(visited.find(src) != visited.end())
            return;

        visited.insert(src);

        if(src  == dst){
            ans = product;
            return ;
        }

        for(auto it : adj[src]){
            string node = it.first;
            double val = it.second;

            dfs(node,dst,visited,adj,product*val,ans);

        }
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<string,double>>>adj;
        //create a graph
        for(int i=0;i<equations.size();i++){
            string a = equations[i][0];
            string b = equations[i][1];

            double val =values[i];
            adj[a].push_back({b , val});
            adj[b].push_back({a , 1.0/val});
        }
        vector<double>res;
        for(int i=0;i<queries.size();i++){
            double ans =-1;
            double product = 1;
            unordered_set<string> visited; // since our input is tring we chose set
            string a= queries[i][0];
            string b= queries[i][1];
            
            if(adj.find(a) != adj.end())
                dfs(a,b,visited,adj,product,ans);
            res.push_back(ans);
        }
        return res;
    }
};