class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<long long int>> components;
        map<long long int, long long int> deg;
        vector<vector<long long int>> adj(n);
        for(int i=0; i<edges.size(); i++)
        {
            deg[edges[i][0]]++;
            deg[edges[i][1]]++;
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> vis(n, false);
        for(int i=0; i<n; i++)
        {
            if(vis[i] == false)
            {
                queue<long long int> q;
                q.push(i);
                vis[i] = true;
                vector<long long int> curr;
                curr.push_back(i);
                while(!q.empty())
                {
                    long long int temp = q.front();
                    q.pop();
                    for(int j=0; j<adj[temp].size(); j++)
                    {
                        if(!vis[adj[temp][j]]) {q.push(adj[temp][j]); vis[adj[temp][j]] = true; curr.push_back(adj[temp][j]);}
                    }
                }
                components.push_back(curr);
            }
        }
        //cout << "here" << endl;
        long long int req = 0;
        for(int i=0; i<components.size(); i++)
        {
            bool check = true;
            //cout << components[i].size() << endl;
            for(int j=0; j<components[i].size(); j++)
            {
                //cout << i << " " << j << " " << deg[components[i][j]] << " " << components[i][j] << endl;
                if(deg[components[i][j]] != components[i].size()-1) 
                {
                    check = false;
                    //cout << i << " " << j << " " << components[i][j] << " " << deg[components[i][j]] << " " << check << endl;
                }
            }
            if(check) req = req + 1;
        }
        //for(auto i: deg) cout << i.first << " " << i.second << endl;
        return req;
    }
};