class Solution {
public:
    bool check(vector<bool>& vis, vector<bool>& path, vector<bool>& truth, vector<vector<int>>& adj, long long int curr, vector<int>& ans)
    {
        vis[curr] = true;
        path[curr] = true;
        bool checker = true;
        for(int i=0; i<adj[curr].size(); i++)
        {
            if(!vis[adj[curr][i]] && check(vis, path, truth, adj, adj[curr][i], ans) == false) checker = false;
            else if(vis[adj[curr][i]] && path[adj[curr][i]]) checker = false;
            else if(vis[adj[curr][i]] && truth[adj[curr][i]] == false) checker = false;
        }
        if(checker == false) {path[curr] = false; return false;}
        ans.push_back(curr);
        path[curr] = false;
        truth[curr] = true; return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        int n = numCourses; vector<vector<int>> p = prerequisites;
        vector<vector<int>> adj1(n);
        for(int i=0; i<p.size(); i++) {adj[p[i][0]].push_back(p[i][1]); adj1[p[i][1]].push_back(p[i][0]);}
        vector<bool> vis(n,0), path(n,0), truth(n,0);
        bool checker = true;
        vector<int> temp;
        for(int i=0; i<n; i++)
        {
            if(!vis[i]) checker = check(vis, path, truth, adj, i, temp);
            if(checker == false) break;
        }
        vector<int> ans;
        if(checker == false) return ans;
        ans = temp;
        //reverse(ans.begin(), ans.end());
        return ans;
    }
};