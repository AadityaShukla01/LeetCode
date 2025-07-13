class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int cnt = 0;
        int n = players.size(), m = trainers.size();


        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int i = 0, j = 0;
        while(i < n && j < m){
            if(trainers[j] >= players[i]){
                i++;
                cnt++;
            }
            j++;
        }
        return cnt;
    }
};