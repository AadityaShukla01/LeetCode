class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int>ans(n);
        map<int, int>balls, colors;
        for(int i=0; i<n; i++)
        {
            int x = queries[i][0], y = queries[i][1];
            if(balls.find(x) != balls.end()){
                if(colors.find(balls[x]) != colors.end()){
                    colors[balls[x]]--;
                    if(colors[balls[x]] == 0)
                        colors.erase(balls[x]);
                }
            }
            balls[x] = y;
            colors[y]++;

            ans[i] = colors.size();
        }
        return ans;
    }
};