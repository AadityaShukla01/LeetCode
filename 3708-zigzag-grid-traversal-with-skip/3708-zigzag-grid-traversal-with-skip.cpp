class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& g) {
        vector<int>ans;
        int n = g.size(), m = g[0].size();
        int i = 0, j = 0;
        int cnt = 0;
        bool flag = true;

        while(i < n){

            if(flag){
                while(j < m){
                    if(cnt % 2 == 0) ans.push_back(g[i][j]);
                    j++;
                    cnt++;
                }
                j = m - 1;
            }
            else{
                while(j >= 0){
                    if(cnt % 2 == 0) ans.push_back(g[i][j]);
                    j--;
                    cnt++;
                }
                j = 0;
            }

            flag = !flag;
            i++;
        }
        return ans;
    }
};