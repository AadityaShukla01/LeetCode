class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& it) {
        sort(it.begin(),it.end());
        vector<vector<int>>res;
        res.push_back(it[0]);
        for(int i=1;i<it.size();i++){
            if(res.back()[1]>=it[i][0]){
                res.back()[1]=max(it[i][1],res.back()[1]);
            }
            else{
                res.push_back(it[i]);
            }
        }
        return res;
    }
};