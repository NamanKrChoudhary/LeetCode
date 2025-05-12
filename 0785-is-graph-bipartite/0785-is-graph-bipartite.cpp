class Solution {
public:
    void dfs(vector<bool>& vis, vector<long long int>& val, vector<vector<int>>& adj, long long int curr, vector<bool>& ans)
    {
        for(int i=0; i<adj[curr].size(); i++)
        {
            if(vis[adj[curr][i]] == false)
            {
                vis[adj[curr][i]] = true;
                val[adj[curr][i]] = !val[curr];
                dfs(vis, val, adj, adj[curr][i], ans);
            }
            else
            {
                if(val[curr] == val[adj[curr][i]]) {ans[0] = false; return;}
            }
        }
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<bool> vis(graph.size());
        vector<long long int> val(graph.size());
        vector<bool> ans(1);
        ans[0] = true;
        for(int i=0; i<graph.size(); i++)
        {
            if(!vis[i] && ans[0] == true) dfs(vis, val, graph, i, ans);
        }
        return ans[0];
    }
};