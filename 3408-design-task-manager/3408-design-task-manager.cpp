class TaskManager {
public:
    set<pair<long long int, long long int>> pritask;
    map<long long int, long long int> tpri;
    map<long long int, long long int> tuid;
    TaskManager(vector<vector<int>>& tasks) {
        for(int i=0; i<tasks.size(); i++)
        {
            tuid[tasks[i][1]] = tasks[i][0];
            tpri[tasks[i][1]] = tasks[i][2];
            pritask.insert({tasks[i][2],tasks[i][1]});
        }
    }
    
    void add(int userId, int taskId, int priority) {
        tuid[taskId] = userId;
        tpri[taskId] = priority;
        pritask.insert({priority, taskId});
    }
    
    void edit(int taskId, int newPriority) {
        auto it = pritask.find({tpri[taskId], taskId});
        pritask.erase(it);
        tpri[taskId] = newPriority;
        pritask.insert({newPriority, taskId});
    }
    
    void rmv(int taskId) {
        auto it = pritask.find({tpri[taskId], taskId});
        pritask.erase(it);
        tpri.erase(taskId);
        tuid.erase(taskId);
    }
    
    int execTop() {
        if(pritask.empty()) return -1;
        pair<long long int, long long int> curr = *pritask.rbegin();
        long long int uid = tuid[curr.second];
        pritask.erase(curr);
        tpri.erase(curr.second);
        tuid.erase(curr.second);
        return uid;
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