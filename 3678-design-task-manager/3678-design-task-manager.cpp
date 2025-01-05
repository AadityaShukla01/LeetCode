class TaskManager {
public:
    map<int, int>tU;
    typedef pair<int, int>P;
    priority_queue<P>pq;
    map<int, int>tP;
    TaskManager(vector<vector<int>>& tasks) {
        for(auto task: tasks)
        {
            int userId = task[0];
            int taskId = task[1];
            int priority = task[2];

            pq.push({priority, taskId});

            tP[taskId] = priority;
            tU[taskId] = userId;
        }
    }
    
    void add(int userId, int taskId, int priority) {
        tU[taskId] = userId;
        tP[taskId] = priority;
        pq.push({priority, taskId});
    }
    
    void edit(int taskId, int newPriority) {
        tP[taskId] = newPriority;
        pq.push({newPriority, taskId});
    }
    
    void rmv(int taskId) {
        tP.erase(taskId);
        tU.erase(taskId);
    }
    
    int execTop() {
        while(pq.empty() == false)
        {
            auto it = pq.top();
            pq.pop();
            

            if(tP.find(it.second) == tP.end())
                continue;

            if(tP[it.second] != it.first) 
                continue;
                
            int a = tU[it.second];

            tP.erase(it.second);
            tU.erase(it.second);

            return a; 
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