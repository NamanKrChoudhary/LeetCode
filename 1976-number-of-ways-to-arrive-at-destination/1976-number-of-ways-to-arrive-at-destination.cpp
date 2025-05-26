class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const long long int mod = 1e9+7;
        const long long int one = 1;
        vector<vector<pair<long long int, long long int>>> adj(n);
        for(int i=0; i<roads.size(); i++)
        {
            adj[roads[i][0]].push_back({roads[i][2], roads[i][1]});
            adj[roads[i][1]].push_back({roads[i][2], roads[i][0]});
        }
        set<pair<long long int, long long int>> s;
        vector<long long int> time(n), count(n);
        for(int i=0; i<n; i++) {time[i] = LLONG_MAX; count[i] = 0;}
        time[0] = 0; count[0] = 1;
        s.insert({0, 0});
        while(!s.empty())
        {
            pair<long long int, long long int> temp = *s.begin();
            long long int node = temp.second, nodetime = temp.first;
            s.erase(temp);
            for(int i=0; i<adj[node].size(); i++)
            {
                long long int curr = adj[node][i].second;
                long long int currtime = nodetime+adj[node][i].first;
                if(currtime == time[curr])
                {
                    count[curr] = (count[curr]+count[node])%(mod);
                }
                else if(currtime < time[curr])
                {
                    if(time[curr] != LLONG_MAX) s.erase({time[curr], curr});
                    time[curr] = currtime;
                    count[curr] = max(count[node],one);
                    s.insert({currtime, curr});
                }
            }
        }
        return count[n-1];
    }
};