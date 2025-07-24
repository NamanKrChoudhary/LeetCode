class Solution {
public:
    int dfs(vector<set<int>>& parents, set<int>& currpar, vector<bool>& vis, vector<vector<int>>& adj, vector<int>& val, vector<int>& xors, int currind)
    {
        if(currind >= val.size()) return 0;
        vis[currind] = true;
        int xr = val[currind];
        parents[currind] = currpar;
        currpar.insert(currind);
        for(int i=0; i<adj[currind].size(); i++)
        {
            if(!vis[adj[currind][i]])
            {
                //vis[adj[currind][i]] = true;
                xr = xr ^ dfs(parents, currpar, vis, adj, val, xors, adj[currind][i]);
                //cout << currind << " " << adj[currind][i] << endl;
            }
        }
        xors[currind] = xr;
        currpar.erase(currind);
        return xr;
    }
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        vector<set<int>> parents(nums.size());
        vector<bool> vis(nums.size());
        vector<vector<int>> adj(nums.size());
        vector<int> xors(nums.size());
        set<int> currpar;
        for(int i=0; i<edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        xors[0] = dfs(parents, currpar, vis, adj, nums, xors, 0);
        vector<int> check(3);
        check[0] = xors[0];
        int minn = INT_MAX;
        //for(int i=0; i<nums.size(); i++) cout << xors[i] << " "; cout << endl;
        for(int i=1; i<nums.size(); i++)
        {
            for(int j=i+1; j<nums.size(); j++)
            {
                check[0] = xors[0];
                check[1] = xors[i];
                check[2] = xors[j];
                if(parents[i].count(j))
                {
                    check[0] = check[0]^check[2];
                    check[2] = check[2]^check[1];
                }
                else if(parents[j].count(i))
                {
                    check[0] = check[0]^check[1];
                    check[1] = check[1]^check[2];
                }
                else
                {
                    //cout << i << " " << j << endl;
                    check[0] = (check[0]^check[1])^check[2];
                }
                //cout << i << " " << j << endl;
                sort(check.begin(), check.end());
                //cout << check[0] << " " << check[1] << " " << check[2] << endl;
                minn = min(minn, check[2]-check[0]);
            }
        }
        // for(int i=0; i<parents.size(); i++)
        // {
        //     cout << i << endl;
        //     for(auto j: parents[i]) cout << j << " "; cout << endl;
        // }
        return minn;
    }
};