class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n = arr.size();
        map<int, vector<int>>m;
        vector<int>vis(n, 0);
        for(int i=0; i<n; i++)
        {
            int r = arr[i] % k;
            if(r < 0) r += k;
            m[r].push_back(i);
        }
        for(int i=0; i<n; i++)
        {
            if(vis[i]) continue;
            cout << i;
            int r = arr[i] % k;
            if(r < 0) r = r + k;

            if(m[r].size() == 0)
                return false;

            vis[i] = 1;


            if(r == 0)
            {

                int pair_idx;
                while(m[r].size() && vis[m[r].back()]) m[r].pop_back();
                if(m[r].size() == 0) return false;
                pair_idx = m[r].back();
                m[r].pop_back();

                vis[pair_idx] = 1;
            }
            else
            {
                int pair_idx;
                while(m[k - r].size() && vis[m[k - r].back()]) m[k - r].pop_back();
                if(m[k - r].size() == 0) return false;
                pair_idx = m[k - r].back();
                m[k - r].pop_back();

                vis[pair_idx] = 1;
            }
        }
        return true;
    }
};