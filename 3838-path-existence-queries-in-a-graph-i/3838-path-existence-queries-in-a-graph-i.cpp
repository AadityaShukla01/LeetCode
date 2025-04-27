class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        int len = queries.size();
        vector<bool>ans(len, false);

        int componentId = 0;
        map<int, int>parent;
        parent[0] = componentId;
        for(int i=1; i<n; i++){
            if(nums[i] - nums[i - 1] > maxDiff){
                parent[i] = ++componentId;
            }
            else parent[i] = componentId;
        }
        for(int i=0; i<len; i++){
            if(parent[queries[i][0]] == parent[queries[i][1]]) ans[i] = true;
        }
        return ans;
    }
};