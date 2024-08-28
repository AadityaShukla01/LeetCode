class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        map<int, long long>mp;
        int n = tasks.size();
        long long time = 0;
        for(int i=0; i<n; i++){
            if(mp.find(tasks[i]) == mp.end()){
                time++;
                mp[tasks[i]] = time + space;
            }
            else{
                if(time > mp[tasks[i]]){
                    time++;
                    mp[tasks[i]] = time + space;
                }
                else{
                    long long t = time;
                    time = mp[tasks[i]] + 1;
                    mp[tasks[i]] = time + space;
                }
            }
        }
        return time;
    }
};