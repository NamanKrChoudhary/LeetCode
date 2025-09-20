class Router {
public:
      int bufferlen;
    set<vector<  int>> pktset;
    //deque<vector<int>> dq;
    queue<vector<  int>> q;
    map<  int, deque<int>> destpkt;
    Router(int memoryLimit) {
        bufferlen = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        vector<  int> curr = {source, destination, timestamp};
        if(pktset.find(curr) != pktset.end()) return false;
        if(q.size() >= bufferlen) 
        {
            vector<  int> temp = q.front();
            q.pop();
            //dq.pop_front();
            pktset.erase(temp);
            destpkt[temp[1]].pop_front();
        }
        q.push(curr);
        pktset.insert(curr);
        destpkt[curr[1]].push_back(curr[2]);
        return true;
    }
    
    vector<int> forwardPacket() {
        vector<int> curr;
        if(pktset.empty()) return curr;
        curr = q.front();
        q.pop();
        pktset.erase(curr);
        destpkt[curr[1]].pop_front();
        return curr;
    }
    
    int getCount(int destination, int startTime, int endTime) {
        long long int count = upper_bound(destpkt[destination].begin(), destpkt[destination].end(), endTime) - lower_bound(destpkt[destination].begin(), destpkt[destination].end(), startTime);
        return count;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */