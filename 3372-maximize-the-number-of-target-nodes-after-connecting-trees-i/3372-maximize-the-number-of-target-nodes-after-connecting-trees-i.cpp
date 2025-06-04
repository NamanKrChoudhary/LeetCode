class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        vector<vector<long long int>> adj1(edges1.size()+1), adj2(edges2.size()+1);
        for(int i=0; i<edges1.size(); i++) {adj1[edges1[i][0]].push_back(edges1[i][1]); adj1[edges1[i][1]].push_back(edges1[i][0]);}
        for(int i=0; i<edges2.size(); i++) {adj2[edges2[i][0]].push_back(edges2[i][1]); adj2[edges2[i][1]].push_back(edges2[i][0]);}
        long long int maxx = 0;
        for(int i=0; i<adj2.size(); i++)
        {
            queue<long long int>q;
            q.push(i); vector<bool> vis(adj2.size(),0); long long int tot = 1;
            if(k == 1) maxx = max(maxx, tot);
            vis[i] = true; long long int cnt = 1;
            while(!q.empty() && cnt < k)
            {
                cnt = cnt + 1;
                long long int len = q.size();
                for(int k=0; k<len; k++)
                {
                    long long int curr = q.front();
                    q.pop();
                    for(int j=0; j<adj2[curr].size(); j++)
                    {
                        if(!vis[adj2[curr][j]])
                        {
                            vis[adj2[curr][j]] = true;
                            q.push(adj2[curr][j]);
                            tot = tot + 1;
                        }
                    }
                }
                if(cnt == k || (tot == adj2.size() && cnt < k)) {maxx = max(maxx, tot); break;}
            }
        }
        vector<int> ans(adj1.size());
        for(int i=0; i<adj1.size(); i++)
        {
            queue<long long int>q;
            q.push(i); vector<bool> vis(adj1.size(),0); long long int tot = 1;
            if(k == 0) ans[i] = tot;
            vis[i] = true; long long int cnt = 0;
            while(!q.empty())
            {
                cnt = cnt + 1;
                long long int len = q.size();
                for(int k=0; k<len; k++)
                {
                    long long int curr = q.front();
                    q.pop();
                    for(int j=0; j<adj1[curr].size(); j++)
                    {
                        if(!vis[adj1[curr][j]])
                        {
                            vis[adj1[curr][j]] = true;
                            q.push(adj1[curr][j]);
                            tot = tot + 1;
                        }
                    }
                }
                if(cnt == k || (tot == adj1.size() && cnt < k)) { cout << tot << " "; ans[i] = tot; break;}
            }
        }
        for(int i=0; i<adj1.size(); i++) ans[i] = ans[i] + maxx;
        return ans;
    }
};