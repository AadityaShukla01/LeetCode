class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int>adj[n];
        vector<int>indegree(n,0);
        for(int i=0;i<n;i++){
            if(leftChild[i] !=-1 ){
                ++indegree[leftChild[i]];
                if(indegree[leftChild[i]]>1) return false;
                adj[i].push_back(leftChild[i]);
            }
        }

        for(int i=0;i<n;i++){
            if(rightChild[i] !=-1 ){
                ++indegree[rightChild[i]];
                if(indegree[rightChild[i]]>1) return false;
                adj[i].push_back(rightChild[i]);
            }
        }
        int root=-1;
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                if(root!=-1){
                    return false;
                }
                q.push(i); // DEGREE 0 means its the root
                root=i;
            }
        }        
        if(root==-1){
            return false;
        }
        int cnt=0;
        while(q.empty()==false){
            int node=q.front();
            q.pop();
            cnt++;
            for(auto it:adj[node]){ 
                indegree[it]--;   
                if(indegree[it]==0)
                    q.push(it);               
            }
        }
        cout<<cnt<<endl;
        return cnt==n;
    }
};