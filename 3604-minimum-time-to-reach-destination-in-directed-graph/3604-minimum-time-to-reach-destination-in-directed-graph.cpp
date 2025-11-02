class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
        vector<vector<vector<long long int>>> adj(n);
        for(int i=0; i<edges.size(); i++)
        {
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2], edges[i][3]});
            //adj[edges[i][1]].push_back({edges[i][0], edges[i][2], edges[i][3]});
        }
        vector<long long int> time(n, LLONG_MAX);
        priority_queue<pair<long long int, long long int>, vector<pair<long long int, long long int>>, greater<pair<long long int, long long int>>> s;
        s.push({0,0});
        time[0] = 0;
        while(!s.empty())
        {
            pair<long long int, long long int> curr = s.top();
            long long int currtime = curr.first, currnode = curr.second;
            s.pop();
            for(int i=0; i<adj[currnode].size(); i++)
            {
                long long int nxtnode = adj[currnode][i][0];
                if(currtime <= adj[currnode][i][2])
                {
                    long long int nxttime = max(currtime, adj[currnode][i][1]);
                    if(nxttime < time[nxtnode])
                    {
                        time[nxtnode] = nxttime+1;
                        s.push({nxttime+1, nxtnode});
                    }
                }
            }
        }
        if(time[n-1] == LLONG_MAX) return -1;
        else return time[n-1];
    }
};