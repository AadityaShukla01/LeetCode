class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        map<int, vector<int>>mp;
        int n = mat.size(), m = mat[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                mp[i + j].push_back(mat[i][j]);
            }
        }

        vector<int>ans;

        for(int i=0; i<=m+n-2; i++){
            if(i % 2){
                vector<int>v = mp[i];
                for(auto el: v) ans.push_back(el);
            }
            else{
                vector<int>v = mp[i];
                reverse(v.begin(), v.end());
                for(auto el: v) ans.push_back(el);
            }
        }
        return ans;
    }
};