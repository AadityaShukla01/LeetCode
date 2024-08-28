class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n = triplets.size();
        sort(triplets.begin(), triplets.end());

        int mx1 = 0, mx2 = 0, mx3 = 0;

        for(int i=0; i<n; i++){
            if(triplets[i][0] <= target[0] && triplets[i][1] <= target[1] && triplets[i][2] <= target[2]){
                mx1 = max(mx1, triplets[i][0]);
                mx2 = max(mx2, triplets[i][1]);
                mx3 = max(mx3, triplets[i][2]);
            }
        } 

        return mx1 == target[0] && mx2 == target[1] && mx3 == target[2];
    }
};