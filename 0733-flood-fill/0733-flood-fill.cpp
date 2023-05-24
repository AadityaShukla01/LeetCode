class Solution {
public:
    void dfs(int row,int col, vector<vector<int>>& image, int preColor , int color){
        image[row][col] = color;

        int delRow[]= {-1,0,1,0};
        int delCol[]= {0,-1,0,1};

        for(int i=0;i<4;i++){
            int nRow=row+delRow[i];
            int nCol=col+delCol[i];

            if(nRow < image.size() && nCol < image[0].size() && nRow >= 0 && nCol >= 0){
                if(image[nRow][nCol] == preColor && image[nRow][nCol] != color){
                    dfs(nRow,nCol,image,image[nRow][nCol],color);
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();


        dfs(sr,sc,image,image[sr][sc],color);

        return image;
    }
};