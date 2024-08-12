class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();

        int i = 0, j = 1;
        bool flag = true;
        vector<int>ans(n*m);
        int iter = 0;
        int tot = 0;
        while(tot < m + n - 1){
            if(flag){
                if(i < n){
                    int ii = i;
                    int jj = 0;
                    while(ii >=0  && jj < m){
                        ans[iter++] = mat[ii][jj];
                        ii--;
                        jj++;
                    }
                    i++;
                }
                else{
                    int ii = n - 1;
                    int jj = j;
                    while(ii >=0  && jj < m){
                        ans[iter++] = mat[ii][jj];
                        ii--;
                        jj++;
                    }
                    j++;
                }
            }
            else{
                if(i < n){
                    int ii = i;
                    int jj = 0;
                    vector<int>t;
                    while(ii >=0  && jj < m){
                        t.push_back(mat[ii][jj]);
                        ii--;
                        jj++;
                    }
                    reverse(t.begin(), t.end());
                    for(int it=0; it<t.size(); it++){
                        ans[iter++] = t[it];
                    }
                    i++;
                }
                else{
                    int ii = n - 1;
                    int jj = j;
                    vector<int>t;
                    while(ii >=0  && jj < m){
                        t.push_back(mat[ii][jj]);
                        ii--;
                        jj++;
                    }
                    reverse(t.begin(), t.end());
                    for(int it=0; it<t.size(); it++){
                        ans[iter++] = t[it];
                    }
                    j++;
                }
            }
            flag = !flag;
            tot++;
        }
        return ans;
    }
};