class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int ans = 1e9;
        int n = tops.size();
        for(int i=1; i<=6; i++){
            int top = 0, bottom = 0;
            for(int j=0; j<tops.size(); j++){
                if(tops[j] != i && bottoms[j] != i){
                    top = 1e9, bottom = 1e9;
                    break;
                }
                if(tops[j] != i) top++;
                if(bottoms[j] != i) bottom++;
            }
            ans = min(ans, min(top, bottom));
        }
        return ans == 1e9 ? -1 : ans;
    }
};