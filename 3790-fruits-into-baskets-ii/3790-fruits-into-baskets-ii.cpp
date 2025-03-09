class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int cnt = 0;
        int n = fruits.size();
        vector<int>vis(n, 0);

        for(int i=0; i<n; i++)
        {
            bool f = 0;
            for(int j=0; j<n; j++)
            {
                if(!vis[j] && fruits[i] <= baskets[j])
                {
                    vis[j] = 1;
                    f = 1;
                    break;
                }
            }
            if(!f) cnt++;
        }
        return cnt;
    }
};