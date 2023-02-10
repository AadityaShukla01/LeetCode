class Solution {
public:
    vector<vector<int>> generate(int Ram) {
        vector<vector<int>>r(Ram);
        for(int i=0;i<Ram;i++){
            r[i].resize(i+1);
                r[i][i]=1;
                r[i][0]=1;
            for(int j=1;j<i;j++){
                r[i][j]=r[i-1][j]+r[i-1][j-1];
            }
        }
        return r;
    }
};