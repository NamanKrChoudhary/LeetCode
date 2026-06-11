class Solution {
public:
    long long int mod = 1e9+7;
    long long int modexp(long long int a, long long int b)
    {
        long long int res = 1;
        while(b)
        {
            if(b%2 == 1) res = (res*a)%mod;
            a = (a*a)%mod;
            b = b/2;
        }
        return res;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        vector<vector<long long int>> adj(edges.size()+1);
        for(long long int i=0; i<edges.size(); i++)
        {
            adj[edges[i][0]-1].push_back(edges[i][1]-1);
            adj[edges[i][1]-1].push_back(edges[i][0]-1);
        }
        vector<bool>vis(adj.size());
        queue<long long int> q; q.push(0); vis[0] = true;
        long long int depth = 0;
        while(!q.empty())
        {
            long long int len = q.size();
            for(long long int i=0; i<len; i++)
            {
                long long int depth = q.front();
                q.pop();
                for(long long int j=0; j<adj[depth].size(); j++)
                {
                    if(!vis[adj[depth][j]])
                    {
                        vis[adj[depth][j]] = true;
                        q.push(adj[depth][j]);
                    }
                }
            }
            if(q.size() > 0) depth = depth + 1;
        }
        vector<long long int> fact(depth+1), invfact(depth+1);
        fact[0] = 1;
        for(int i=1; i<=depth; i++)
        {
            fact[i] = (fact[i-1]*i)%mod;
        }
        invfact[depth] = modexp(fact[depth], mod-2);
        for(int i=depth-1; i>=0; i--)
        {
            invfact[i] = (invfact[i+1]*(i+1))%mod;
        }
        long long int req = 0;
        //cout << depth << endl;
        for(int i=1; i<=depth; i=i+2)
        {
            req = (req + (((fact[depth]*invfact[depth-i])%mod)*invfact[i])%mod)%mod;
        }
        return req;
    }
};