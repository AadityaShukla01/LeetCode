class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int>ans;
        vector<int>r(n);
        for(int i=0; i<n; i++){
            int smallest = *min_element(matrix[i].begin(), matrix[i].end());
            r[i] = smallest;
        }
        vector<int>c(m);
        for(int j=0; j<m; j++){
            int biggest = -1e9;
            for(int i=0; i<n; i++){
                biggest = max(biggest, matrix[i][j]);
            }
            c[j] = biggest;
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(c[j] == r[i]) ans.push_back(r[i]);
            }
        }
        return ans;
    }
};