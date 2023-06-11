class Solution {
public:
    int dp[108][108];
    int sol(int i, vector<vector<int>>& clips, int time,int pre){
        if(pre >= time) return 0;//reached destination
        if(i>=clips.size()) return 1e6;//wrong ans

        if(dp[i][pre] != -1) return dp[i][pre];

        //case to pick any element
        if(clips[i][0] <= pre){
            //we heave 2 cases now to pick it or not
            return dp[i][pre] = min(1+sol(i+1,clips,time,clips[i][1]),sol(i+1,clips,time,pre));
        }

        return dp[i][pre] = sol(i+1,clips,time,pre);
    }
    int videoStitching(vector<vector<int>>& clips, int time) {
        int n = clips.size();
        sort(clips.begin(),clips.end());
        memset(dp,-1,sizeof(dp));
        int ans = sol(0,clips,time,0);
        if(ans == 1e6) return -1;
        return ans;
    }
};