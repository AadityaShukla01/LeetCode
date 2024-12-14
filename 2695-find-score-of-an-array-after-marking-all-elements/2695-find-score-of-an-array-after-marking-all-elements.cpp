class Solution {
public:
    typedef pair<int, int>P;
    long long findScore(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        vector<int>vis(n, 0);

        priority_queue<P, vector<P>, greater<P>>pq;

        for(int i=0; i<n; i++){
            pq.push({nums[i], i});
        }

        while(pq.empty() == false)
        {
            auto it = pq.top();
            pq.pop();

            int num = it.first;
            int idx = it.second;

            

            if(!vis[idx])
            {
                ans += num;
                if(idx + 1 < n) vis[idx + 1] = 1;
                if(idx - 1 >= 0) vis[idx - 1] = 1;
                vis[idx] = 1;
            }
        }
        return ans;
    }
};