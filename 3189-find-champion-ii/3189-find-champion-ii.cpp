class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int>in(n);

        for(auto &e: edges)
        {
            int a = e[0], b = e[1];

            in[b]++;
        }

        int cnt = 0;
        for(int i=0; i<n; i++)
        {
            if(in[i] == 0) cnt++;
        }

        if(cnt > 1 || cnt == 0) return -1;

        for(int i=0; i<n; i++)
        {
            if(!in[i]) return i;
        }
        return -1;
    }
};