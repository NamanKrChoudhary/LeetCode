class Solution {
public:
    bool check(vector<bool>& vis, vector<bool>& truth, vector<vector<int>>& adj, long long int curr)
    {
        vis[curr] = true;
        //if(adj[curr].size() == 0) {truth[curr] = true; return true;}
        bool checker = true;
        for(int i=0; i<adj[curr].size(); i++)
        {
            if(!vis[adj[curr][i]] && check(vis, truth, adj, adj[curr][i]) == false) { checker = false;}
            else if(vis[adj[curr][i]] && truth[adj[curr][i]] == false) {checker = false;}
        }
        if(checker == false) return false;
        truth[curr] = true;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<bool> vis(graph.size()), truth(graph.size(), 0);
        for(int i=0; i<graph.size(); i++)
        {
            bool checker = false;
            if(!vis[i]) 
            {
                checker = check(vis, truth, graph, i);
            }
        }
        vector<int> ans;
        for(int i=0; i<graph.size(); i++) if(truth[i]) ans.push_back(i);
        return ans;
    }
};