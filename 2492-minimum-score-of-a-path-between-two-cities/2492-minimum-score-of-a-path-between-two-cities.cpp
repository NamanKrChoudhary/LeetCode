class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<bool> vis(n, false);
        queue<long long int> q;
        vector<vector<pair<long long int, long long int>>> adj(n);
        for(int i=0; i<roads.size(); i++)
        {
            adj[roads[i][0]-1].push_back({roads[i][1]-1, roads[i][2]});
            adj[roads[i][1]-1].push_back({roads[i][0]-1, roads[i][2]});
        }
        q.push(0);
        vis[0] = true;
        long long int minn = 1e15;
        while(!q.empty())
        {
            long long int curr = q.front();
            q.pop();
            for(int i=0; i<adj[curr].size(); i++)
            {
                if(!vis[adj[curr][i].first]) 
                {
                    q.push(adj[curr][i].first);
                    vis[adj[curr][i].first] = true;
                }
                minn = min(minn, adj[curr][i].second);
            }
        }
        return minn;
    }
};