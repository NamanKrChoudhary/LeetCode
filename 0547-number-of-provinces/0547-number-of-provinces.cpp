class Solution {
public:
    void dfs(vector<bool>& vis, vector<int>& ans, vector<vector<int>>& adj, int curr)
    {
        vis[curr] = true;
        //ans.push_back(curr);
        for(auto i: adj[curr])
        {
            if(!vis[i]) dfs(vis, ans, adj, i);
        }
        return ;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(isConnected.size());
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(isConnected[i][j]) adj[i].push_back(j);
            }
        }
        vector<int> ans;
        int count = 0;
        vector<bool> vis(n);
        for(int i=0; i<n; i++)
        {
            if(!vis[i]) {dfs(vis, ans, adj, i); count = count + 1;}
        }
        //ans.shrink_to_fit();
        return count;
    }
};