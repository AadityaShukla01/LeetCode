class TaskManager {
public:
    map<int, int>taskUserMap;
    map<int, int>taskPriorityMap;
    priority_queue<pair<int, int>>pq;
    TaskManager(vector<vector<int>>& tasks) {
        for(auto t: tasks){
            pq.push({t[2], t[1]});
            taskUserMap[t[1]] = t[0];
            taskPriorityMap[t[1]] = t[2];
        }
    }
    
    void add(int userId, int taskId, int priority) {
        taskUserMap[taskId] = userId;
        taskPriorityMap[taskId] = priority;
        pq.push({priority, taskId});
    }
    
    void edit(int taskId, int newPriority) {
        taskPriorityMap[taskId] = newPriority;
        pq.push({newPriority, taskId});
    }
    
    void rmv(int taskId) {
        taskUserMap.erase(taskId);
        taskPriorityMap.erase(taskId);
    }
    
    int execTop() {
        while(pq.empty() == false){
            auto it = pq.top();
            int priority = it.first;
            int taskId = it.second;
            cout << taskId << " " << priority << endl; 
            if(taskPriorityMap.find(taskId) != taskPriorityMap.end() &&
             taskPriorityMap[taskId] == priority) {
                pq.pop();

                int res = taskUserMap[taskId];
                taskUserMap.erase(taskId);
                taskPriorityMap.erase(taskId);
                return res;
            }
            else pq.pop();
        }
        return -1;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */