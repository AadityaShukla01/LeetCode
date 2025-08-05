class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = baskets.size();
        vector<int> vis(n, 0);
        int i = 0, j = 0, cnt = 0;

        while (i < n) {
            if (j < n &&  fruits[i] <= baskets[j] && !vis[j]) {
                i++;
                vis[j] = 1;
                j = 0;
            } else if (j >= n) {
                j = 0;
                i++;
                cnt++;
            }
            else
                j++;
        }
        return cnt;
    }
};