class Solution {
public:
    void dfs(vector<vector<long long int>>& adj, vector<bool>& vis, map<long long int, long long int>& ancestors, vector<long long int>& nosq, vector<long long int>& currsum, long long int curri)
    {
        if(vis[curri]) return;
        vis[curri] = true;
        if(ancestors.find(nosq[curri]) != ancestors.end())currsum[0] = currsum[0] + ancestors[nosq[curri]];
        ancestors[nosq[curri]]++;
        for(int i=0; i<adj[curri].size(); i++)
        {
            dfs(adj, vis, ancestors, nosq, currsum, adj[curri][i]);
        }
        if(ancestors[nosq[curri]] == 1)ancestors.erase(nosq[curri]);
        else ancestors[nosq[curri]] = ancestors[nosq[curri]] - 1;
        return;
    }

    long long sumOfAncestors(int n, vector<vector<int>>& edges, vector<int>& nums) {
        vector<long long int> spf(1e5+1, 0);
        for(long long int i=2; i<=1e5; i++)
        {
            if(spf[i] == 0)
            {
                spf[i] = i;
                for(long long int j=i*i; j<=1e5; j=j+i) spf[j] = i;
            }
        }
        vector<long long int> nosq(n);
        for(int i=0; i<n; i++)
        {
            long long int curr = nums[i];
            map<long long int, long long int> mp;
            while(curr > 1)
            {
                mp[spf[curr]]++;
                curr = curr/spf[curr];
            }
            long long int req = 1;
            for(auto j: mp) if(j.second%2 == 1) req = req*j.first;
            nosq[i] = req;
        }
        vector<vector<long long int>> adj(n);
        for(int i=0; i<edges.size(); i++) 
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        map<long long int, long long int> ancestors;
        vector<long long int> currsum(1,0);
        vector<bool> vis(n, false);
        dfs(adj, vis, ancestors, nosq, currsum, 0);
        return currsum[0];
    }
};