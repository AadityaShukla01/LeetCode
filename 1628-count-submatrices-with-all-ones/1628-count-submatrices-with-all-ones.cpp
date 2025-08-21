class Solution {
public:
    int sol(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int c = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                c++;
                // counting all possible rectangles we can make
                count += c;
            } else
                c = 0;
        }
        return count;
    }
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            vector<int> t(m, 1);
            for (int j = i; j < n; j++) {
                for (int l = 0; l < m; l++) {
                    t[l] = t[l] & mat[j][l];
                }
                count += sol(t);
            }
        }
        return count;
    }
};