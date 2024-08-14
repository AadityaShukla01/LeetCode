class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        queue<pair<int, int>>q;

        q.push({x, 0});
        map<int, int>mp;
        while(q.empty() == false){
            int num = q.front().first;
            int steps = q.front().second;
            
            q.pop();

            if(mp.find(num) != mp.end()) continue;

            mp[num] = 1;

            if(num == y) return steps;

            if(num % 11 == 0){
                q.push({num/11, steps + 1});
            }

            if(num % 5 == 0){
                q.push({num/5, steps + 1});
            }
            
            q.push({num + 1, steps + 1});
            
            if(num - 1){

                q.push({num  - 1, steps + 1});
            }
        }

        return -1;
    }
};