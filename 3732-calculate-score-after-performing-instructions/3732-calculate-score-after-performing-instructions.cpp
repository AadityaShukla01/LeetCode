class Solution {
public:
    long long calculateScore(vector<string>& instructions, vector<int>& values) {
        long long score = 0;
        int n = instructions.size();
        vector<int>vis(n, 0);
        int i = 0;
        while(true)
        {
            if(i < 0) break;
            if(i >= n) break;
            if(vis[i]) break;
            if(instructions[i] == "add"){
                vis[i] = 1;
                score += values[i];
                i++;
            }
            else{
                vis[i] = 1;
                i += values[i];                
            }
        }
        return score;
    }
};