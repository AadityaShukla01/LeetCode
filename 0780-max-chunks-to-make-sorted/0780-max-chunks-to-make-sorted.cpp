class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int cnt = 0;
        int n = arr.size();

        int mx = 0;

        for(int i=0; i<n; i++)
        {
            mx = max(mx, arr[i]);
            if(mx == i) cnt++;
        }
        return cnt;
    }
};