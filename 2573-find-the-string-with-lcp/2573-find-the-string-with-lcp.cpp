class Solution {
public:
    void dfs(vector<vector<long long int>>& adj, vector<long long int>& vis, long long int curri, long long int cnt)
    {
        vis[curri] = cnt;
        for(int i=0; i<adj[curri].size(); i++)
        {
            if(vis[adj[curri][i]] == -1) dfs(adj, vis, adj[curri][i], cnt);
        }
        return;
    }

    string findTheString(vector<vector<int>>& lcp) {
        long long int n = lcp.size();
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(lcp[i][j] != lcp[j][i]) return "";
                if(lcp[i][j] > min(n-i, n-j)) return "";
                if(i == j && lcp[i][j] != n-i) return "";
            }
        }
        for(int j=0; j<n; j++)
        {
            for(int i=0, k=j; k<n; i++, k++)
            {
                if(lcp[i][k] > 0 && i<n-1 && k<n-1 && lcp[i][k]-1 != lcp[i+1][k+1]) return "";
            }
        }
        map<long long int, vector<long long int>> start, end;
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                if(lcp[i][j] > 0)
                {
                    start[i].push_back(j-i);
                    end[i+lcp[i][j]-1].push_back(j-i);
                }
            }
        }
        map<long long int, long long int> curr;
        for(int i=1; i<n; i++) curr[i] = 0;
        vector<vector<long long int>> adj(n);
        for(int i=0; i<n; i++)
        {
            for(int ind = 0; ind<start[i].size(); ind++)
            {
                curr[start[i][ind]]++;
            }
            for(int j=1; i+j<n; j++)
            {
                if(curr[j] > 0)
                {
                    adj[i].push_back(i+j);
                    adj[i+j].push_back(i);
                }
            }
            for(int ind=0; ind<end[i].size(); ind++)
            {
                curr[end[i][ind]]--;
            }
        }
        vector<long long int> vis(n, -1);
        long long int cnt = 0;
        for(int i=0; i<n; i++)
        {
            if(vis[i] == -1)
            {
                dfs(adj, vis, i, cnt);
                cnt = cnt + 1;
            }
        }
        string req = "";
        for(int i=0; i<n; i++)
        {
            if(vis[i] > 25) return "";
            req.push_back('a'+vis[i]);
        }
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                if(req[i] == req[j] && lcp[i][j] == 0) return "";
            }
        }
        return req;
    }
};