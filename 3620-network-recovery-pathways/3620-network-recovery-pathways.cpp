class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        // cost, node.
        long long int n = online.size();
        vector<vector<pair<long long int, long long int>>> adj(n);
        for(int i=0; i<edges.size(); i++) adj[edges[i][0]].push_back({edges[i][2], edges[i][1]});
        long long int st = 0, end = 1e9;
        long long int req = -1;
        while(st <= end)
        {
            long long int mid = st + ((end-st)/2);
            vector<long long int> vis(n, 1e15);
            priority_queue<pair<long long int, long long int>, vector<pair<long long int, long long int>>, greater<pair<long long int, long long int>>> pq;
            pq.push({0,0});
            vis[0] = 0;
            bool possible = false;
            while(!pq.empty())
            {
                pair<long long int, long long int> curr = pq.top();
                pq.pop();
                long long int currcost = curr.first;
                long long int currnode = curr.second;
                if(currnode == n-1) possible = true;
                if(vis[currnode] < currcost) continue;
                for(int i=0; i<adj[currnode].size(); i++)
                {
                    long long int nextnode = adj[currnode][i].second;
                    long long int nodecost = adj[currnode][i].first;
                    long long int nextcost = currcost + nodecost;
                    if(vis[nextnode] > nextcost && nextcost <= k && online[nextnode] == true && nodecost >= mid)
                    {
                        vis[nextnode] = nextcost;
                        pq.push({nextcost, nextnode});
                    }
                }
            }
            if(possible) {req = mid; st = mid+1;}
            else end = mid-1;
        }
        return req;
    }
};