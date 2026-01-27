class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<long long int> minn(n, 1e9);
        priority_queue<pair<long long int, long long int>, vector<pair<long long int, long long int>>, greater<pair<long long int, long long int>>> pq;
        pq.push({0,0});
        minn[0] = 0;
        vector<vector<pair<long long int, long long int>>> adj(n);
        for(int i=0; i<edges.size(); i++) 
        {
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0], edges[i][2]*2});
        }
        while(!pq.empty())
        {
            pair<long long int, long long int> curr = pq.top();
            pq.pop();
            long long int currnode = curr.second;
            long long int currwt = curr.first;
            for(int i=0; i<adj[currnode].size(); i++)
            {
                long long int nextwt = currwt + adj[currnode][i].second;
                long long int nextnode = adj[currnode][i].first;
                if(minn[nextnode] > nextwt) 
                {
                    pq.push({nextwt, nextnode});
                    minn[nextnode] = nextwt;
                }
            }
        }
        if(minn[n-1] == 1e9) return -1;
        return minn[n-1];
    }
};