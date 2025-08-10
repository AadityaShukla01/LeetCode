class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x,
                                         int y, int k) {
        int x_top = x;
        int x_bottom = x + k - 1;

        int y_left = y;
        int y_right = y + k - 1;

        while (x_top < x_bottom) {
            for (int i = y_left; i <= y_right; i++) {
                swap(grid[x_top][i], grid[x_bottom][i]);
            }
            x_top++;
            x_bottom--;
        }
        return grid;
    }
};