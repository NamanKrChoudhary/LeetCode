class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<bool> vis(graph.size());
        vector<long long int> val(graph.size());
        for(int i=0; i<graph.size(); i++)
        {
            if(!vis[i])
            {
                queue<pair<long long int, long long int>> q;
                q.push({0,i});
                vis[i] = true;
                val[i] = 0;
                while(!q.empty())
                {
                    pair<long long int, long long int> temp = q.front();
                    q.pop();
                    for(int j=0; j<graph[temp.second].size(); j++)
                    {
                        if(vis[graph[temp.second][j]] == true && val[graph[temp.second][j]] == temp.first) return false;
                        else if(vis[graph[temp.second][j]] == false)
                        {
                            vis[graph[temp.second][j]] = true;
                            val[graph[temp.second][j]] = (temp.first+1)%2;
                            q.push({val[graph[temp.second][j]], graph[temp.second][j]});
                        }
                    }
                }
            }
        }
        return true;
    }
};