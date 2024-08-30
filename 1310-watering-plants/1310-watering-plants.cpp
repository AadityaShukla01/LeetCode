class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int n = plants.size();
        int cnt = 0;
        int sum = capacity;
        for(int i=0; i<n; i++){
            if(sum >= plants[i]){
                sum -= plants[i];
                cnt++;
            }
            else{
                int pre = i;
                cnt += pre;
                cnt += pre + 1;
                sum = capacity - plants[i];
            }
        }
        return cnt;
    }
};