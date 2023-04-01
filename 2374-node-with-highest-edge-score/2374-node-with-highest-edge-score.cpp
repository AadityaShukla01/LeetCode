class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int sum=0;
        map<int,long long>map;
        for(int i=0;i<edges.size();i++){
            map[edges[i]]=map[edges[i]]+i;
        }
        int maxi=0;
        long long maxSum=0;
        // sort(map.begin(),map.end());
        for(auto it:map){
            if(it.second>maxSum){
                maxSum=it.second;
                maxi=it.first;
            }
        }
        return maxi;
    }
};