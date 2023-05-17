class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int min=0;
        int max=(matrix.size() * matrix[0].size()) -1;

        while(min <= max){
            int mid=min+(max-min)/2;

            if(matrix[mid / matrix[0].size()][mid % matrix[0].size()]==target)
                return true;
            else if(matrix[mid / matrix[0].size()][mid % matrix[0].size()]<target)
                min=mid+1;
            else
                max=mid-1;
        }   
        return false;
    }
};