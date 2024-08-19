class Solution {
public:
    int minimumJumps(vector<int>& nums, int a, int b, int x) {
        int n = nums.size();
        queue<vector<int>>q;
        set<int>s;
        for(auto el: nums) s.insert(el);
        q.push({0, 0, 0});
        vector<vector<int>>vis(8001, vector<int>(2, 0));
        while(q.empty() == false){
            int pos = q.front()[0];
            int steps = q.front()[1];
            int backwards = q.front()[2];

            q.pop();

            if(pos == x) return steps;

            if(pos >= 8001 || pos < 0) continue;
            if(s.find(pos) != s.end()) continue;
            if(vis[pos][backwards]) continue;


            vis[pos][backwards] = 1;

            int forw = pos + a;
            int back = pos - b;

            q.push({forw, steps + 1, 0});

            if(backwards != 1){
                q.push({back, steps + 1, 1});
            }
        }

        return -1;
    }
};