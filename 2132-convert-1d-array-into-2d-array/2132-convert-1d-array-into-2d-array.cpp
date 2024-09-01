class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int len = original.size();
        if(m * n != len) return {};
        vector<vector<int>>ans(m, vector<int>(n));
        int l = 0;
        for(int i=0; i<len; i+=n)
        {
            int j = i;
            while(j < i + n){
                ans[l][j - i] = original[j];
                j++;
            }
            l++;
        }
        return ans;
    }
};