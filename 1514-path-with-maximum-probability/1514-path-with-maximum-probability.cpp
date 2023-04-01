// class Solution {
// public:
//     double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
//         vector<double>dist(n,0);
//         priority_queue<pair<double , int>> pq;
//         pq.push({1,start});
//         dist[0]=1;
//         vector<vector<double>>adj[n];
//         int i=0;
//         for(auto it:edges){
//             int a=it[0];
//             int b=it[1];

//             adj[a].push_back({(double)b,succProb[i]});
//             adj[b].push_back({(double)a,succProb[i]});
//             i++;
//         }
//         while(pq.empty()==false){
//             int node=pq.top().second;
//             double w=pq.top().first;
//             pq.pop();

//             if(node==end)
//                 return w;
//             for(auto it:adj[node]){
//                 int n=it[0];
//                 double wt=it[1];
//                 // cout<<wt<<endl;
//                 if(w*wt>dist[n]){
//                     dist[n]=w*wt;
//                     pq.push({dist[n],n});
//                 }
//             }
//         }
//         for(int i=0;i<n;i++)
//             cout<<dist[i]<<endl;
//         return dist[end];
//     }
// };
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        //create adjacency list
        vector<vector<double>>adj[n];
        int i=0;
        for(auto it:edges){
            int a=it[0];
            int b=it[1];

            adj[a].push_back({(double)b,succProb[i]});
            adj[b].push_back({(double)a,succProb[i]});
            i++;
        }

        //create the distance/probability array 
        vector<double> prob(n , 0);

        priority_queue<pair<double , int>> pq;
        pq.push(make_pair(1,start));

        while(!pq.empty()){
            auto front = pq.top();
            double nodeProb = front.first;
            int node = front.second;
            pq.pop();

            if(node == end)
                return nodeProb;

            for(auto i : adj[node]){
                if(nodeProb * i[1] > prob[i[0]]){
                    prob[i[0]] = nodeProb * i[1];
                    pq.push(make_pair(prob[i[0]] , i[0]));
                }
            }
        }
        
        return 0;
    }
};