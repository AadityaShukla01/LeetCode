class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        unordered_map<int, unordered_set<int>>row, col;
        unordered_map<int, pair<int, int>>location;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                row[i].insert(mat[i][j]);
                col[j].insert(mat[i][j]);
                location[mat[i][j]] = {i, j};
            }
        }

        for(int i=0; i<n*m; i++)
        {
            int r = location[arr[i]].first;
            int c = location[arr[i]].second;
            row[r].erase(arr[i]);
            col[c].erase(arr[i]);
            if(row[r].empty()) return i;
            if(col[c].empty()) return i;
        }
        return n*m - 1;
    }
};