class Solution {
public:

    void dfs(vector<bool>& vis, vector<bool>& path, vector<vector<long long int>>& storage, string& colors, vector<vector<long long int>>& adj, int curr, vector<bool>& check)
    {
        path[curr] = true;
        for(int i=0; i<adj[curr].size(); i++) 
        {
            if(!path[adj[curr][i]] && !vis[adj[curr][i]]) dfs(vis, path, storage, colors, adj, adj[curr][i], check);
            else if(path[adj[curr][i]]) {check[0] = true; return;}
            if(check[0]) return;
        }
        for(int i=0; i<adj[curr].size(); i++)
        {

            if(!path[adj[curr][i]]){
                for(int j=0; j<26; j++)
                {
                    storage[curr][j] = max(storage[curr][j], storage[adj[curr][i]][j]);
                }
            }
        }
        storage[curr][colors[curr]-'a']++;
        vis[curr] = true;
        path[curr] = false;
        return;
    }

    int largestPathValue(string colors, vector<vector<int>>& edges) {
        vector<bool> check(1,0);
        long long int n = colors.size();
        vector<vector<long long int>> storage(n, vector<long long int>(26));
        vector<vector<long long int>> adj(n);
        for(int i=0; i<edges.size(); i++) adj[edges[i][0]].push_back(edges[i][1]);
        vector<bool> vis(n), path(n);
        for(int i=0; i<n; i++)
        {
            if(!vis[i]) dfs(vis, path, storage, colors, adj, i, check);
        }
        long long int a = 0;
        for(int i=0; i<n; i++) for(int j=0; j<26; j++) a = max(a, storage[i][j]);
        if(check[0]) return -1;
        return a;
    }
};