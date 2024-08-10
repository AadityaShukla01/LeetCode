class Solution {
public:
    int count(vector<vector<int>>& matrix, int mi){
        int smaller = 0;
        int n = matrix.size();
        for(int i=0; i<n; i++){
            int ub = upper_bound(matrix[i].begin(), matrix[i].end(), mi) - matrix[i].begin();

            smaller += ub;
        }

        return smaller;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();

        int lo = matrix[0][0];

        int hi = matrix[n - 1][m - 1];

        int ans = -1;
        while(lo <= hi){
            int mi = lo + (hi - lo)/2;

            if(count(matrix, mi) >= k){
                ans = mi;
                hi = mi - 1;
            }
            else lo = mi + 1;
        }

        return ans;
    }
};