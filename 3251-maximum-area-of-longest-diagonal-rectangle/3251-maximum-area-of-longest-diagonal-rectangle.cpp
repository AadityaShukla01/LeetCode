class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int mxArea = 0, mxDiagonal = 0;

        for (auto d : dimensions) {
            int l = d[0], w = d[1];
            int diagonal = l * l + w * w;
            if (diagonal > mxDiagonal) {
                mxArea = l * w;
                mxDiagonal = diagonal;
            } else if (diagonal == mxDiagonal) {
                mxArea = max(mxArea, l * w);
            }
        }
        return mxArea;
    }
};