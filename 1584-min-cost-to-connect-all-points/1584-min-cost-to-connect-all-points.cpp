class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //creating heap to store minimum weight
    int n=points.size();
    
    vector<int>vis(n,0);
    pq.push({0,0});
    int sum=0;
    while(pq.empty()==false){
        auto it=pq.top();
        int wt=it.first;
        int node=it.second;
        pq.pop();
        if(vis[node]==1) continue; //already present in mst

        vis[node]=1;
        sum+=wt;
        
        for(int i=0;i<n;i++){
            
            if(!vis[i]){
                int dist=abs(points[i][0]-points[node][0])+abs(points[i][1]-points[node][1]);
                pq.push({dist,i});
            }
        }

    }
    return sum;
    }
};