class Solution {
public:
    //topo sort ka question hain
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>vis(numCourses);
        vector<int> adj[numCourses];
	   for(auto it:prerequisites){
	       adj[it[1]].push_back(it[0]);
	       
	   }
        vector<int>ans;
        queue<int>q;
        vector<int>indegree(numCourses);
        for(int i =0;i<numCourses;i++){
            for(auto it:adj[i])
                indegree[it]++;
        }
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0)
                q.push(i);
        }
        while(q.empty()==false){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0)
                    q.push(it);
            }
        }
        return ans.size()==numCourses;
    }
};