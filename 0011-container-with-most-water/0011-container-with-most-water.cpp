class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i = 0;
        int j = n - 1;
        int maxArea = 0;

        while(i < j){
            if(height[i] < height[j]){
                //min taking is common is such problesm time complexity is O(N)
                int area = min(height[i], height[j]) * (j - i);
                maxArea = max(maxArea, area);
                i++;
            }
            else{
                int area = min(height[i], height[j]) * (j - i);
                maxArea = max(maxArea, area);
                j--;
            }
        }
        return maxArea;
    }
};