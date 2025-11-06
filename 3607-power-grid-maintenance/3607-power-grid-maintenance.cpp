class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        vector<vector<long long int>> adj(c);
        for(int i=0; i<connections.size(); i++)
        {
            adj[connections[i][0]-1].push_back(connections[i][1]-1);
            adj[connections[i][1]-1].push_back(connections[i][0]-1);
        }
        vector<long long int> grp(c, -1);
        for(int i=0, curr = 1; i<c; i++)
        {
            if(grp[i] == -1)
            {
                grp[i] = curr;
                curr = curr + 1;
                queue<long long int> q;
                q.push(i);
                while(!q.empty())
                {
                    long long int temp = q.front();
                    q.pop();
                    for(int j=0; j<adj[temp].size(); j++) 
                    {
                        if(grp[adj[temp][j]] == -1)
                        {
                            grp[adj[temp][j]] = grp[i];
                            q.push(adj[temp][j]);
                        }
                    }
                }
            }
        }
        map<long long int, set<long long int>> mp;
        for(int i=0; i<grp.size(); i++) mp[grp[i]].insert(i);
        vector<int> req;
        for(int i=0; i<queries.size(); i++)
        {
            if(queries[i][0] == 2)
            {
                mp[grp[queries[i][1]-1]].erase(queries[i][1]-1);
            }
            else
            {
                if(!mp[grp[queries[i][1]-1]].empty())
                {
                    if(mp[grp[queries[i][1]-1]].find(queries[i][1]-1) != mp[grp[queries[i][1]-1]].end()) req.push_back(queries[i][1]);
                    else 
                    {
                        long long int temp = *mp[grp[queries[i][1]-1]].begin();
                        req.push_back(temp+1);
                        //mp[grp[queries[i][1]-1]].insert(queries[i][1]-1);
                    }
                }
                else req.push_back(-1);
            }
        }
        //for(int i=0; i<grp.size(); i++) cout << grp[i] << " "; cout << endl;
        return req;
    }
};