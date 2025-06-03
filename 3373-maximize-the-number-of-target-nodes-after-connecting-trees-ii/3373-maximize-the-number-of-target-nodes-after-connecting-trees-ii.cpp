class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        vector<vector<long long int>> adj1(edges1.size()+1), adj2(edges2.size()+1);
        for(int i=0; i<edges1.size(); i++) {adj1[edges1[i][0]].push_back(edges1[i][1]); adj1[edges1[i][1]].push_back(edges1[i][0]);}
        for(int i=0; i<edges2.size(); i++) {adj2[edges2[i][0]].push_back(edges2[i][1]); adj2[edges2[i][1]].push_back(edges2[i][0]);}
        vector<vector<long long int>> lvl1, lvl2;
        vector<bool> vis1(edges1.size()+1, 0), vis2(edges2.size()+1, 0);
        queue<long long int> q;
        q.push(0); long long int cnt = 0;
        vis1[0] = true;
        lvl1.push_back({0});
        while(!q.empty())
        {
            long long int len = q.size();
            vector<long long int> temp;
            for(int i=0; i<len; i++)
            {
                long long int curr = q.front();
                q.pop();
                for(int j=0; j<adj1[curr].size(); j++) if(!vis1[adj1[curr][j]]) {vis1[adj1[curr][j]] = true; temp.push_back(adj1[curr][j]); q.push(adj1[curr][j]);}
            }
            lvl1.push_back(temp);
        }
        queue<long long int> q1;
        q1.push(0); cnt = 0;
        vis2[0] = true; lvl2.push_back({0});
        while(!q1.empty())
        {
            long long int len = q1.size();
            vector<long long int> temp;
            for(int i=0; i<len; i++)
            {
                long long int curr = q1.front();
                q1.pop();
                for(int j=0; j<adj2[curr].size(); j++) if(!vis2[adj2[curr][j]]) {vis2[adj2[curr][j]] = true; temp.push_back(adj2[curr][j]); q1.push(adj2[curr][j]);}
            }
            lvl2.push_back(temp);
        }
        long long int odd1 = 0, eve1 = 0;
        map<long long int, long long int> mp;
        for(int i=0; i<lvl1.size(); i++)
        {
            if(i%2 == 0) eve1 = eve1 + lvl1[i].size();
            else odd1 = odd1 + lvl1[i].size();
            for(int j=0; j<lvl1[i].size(); j++)
            {
                if(i%2 == 0) mp[lvl1[i][j]] = 0;
                else mp[lvl1[i][j]] = 1;
            }
        }
        long long int odd2 = 0, eve2 = 0;
        for(int i=0; i<lvl2.size(); i++)
        {
            if(i%2 == 0) eve2 = eve2 + lvl2[i].size();
            else odd2 = odd2 + lvl2[i].size();
        }
        long long int toadd = max(odd2, eve2);
        vector<int> ans(edges1.size()+1);
        for(int i=0; i<ans.size(); i++)
        {
            if(mp[i] == 0) ans[i] = toadd + eve1;
            else ans[i] = toadd + odd1;
        }
        return ans;
    }
};