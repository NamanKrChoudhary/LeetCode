class Solution {
public:
    void filler(vector<vector<pair<long long int, long long int>>>& adj, vector<vector<long long int>>& cost)
    {
        for(int node=0; node<adj.size(); node++)
        {
            priority_queue<pair<long long int, long long int>, vector<pair<long long int, long long int>>, greater<pair<long long int, long long int>>> pq;
            pq.push({0, node}); 
            cost[node][node] = 0;
            while(!pq.empty())
            {
                pair<long long int, long long int> curr = pq.top();
                pq.pop();
                long long int currnode = curr.second, currcost = curr.first;
                for(int next = 0; next < adj[currnode].size(); next++)
                {
                    //cout << currcost << " " << currnode << " " << adj[currnode][next].first << endl;
                    long long int nextcost = currcost + adj[currnode][next].first;
                    long long int nextnode = adj[currnode][next].second;
                    if(cost[node][nextnode] > nextcost)
                    {
                        pq.push({nextcost, nextnode});
                        cost[node][nextnode] = nextcost;
                    }
                }
            }
        }
    }
    vector<int> minCost(int n, vector<int>& prices, vector<vector<int>>& roads) {
        vector<vector<pair<long long int, long long int>>> forward(n), backward(n);
        for(int i=0; i<roads.size(); i++)
        {
            forward[roads[i][0]].push_back({roads[i][2], roads[i][1]});
            forward[roads[i][1]].push_back({roads[i][2], roads[i][0]});
            long long int currcost = roads[i][2];
            currcost = currcost*roads[i][3];
            backward[roads[i][0]].push_back({currcost, roads[i][1]});
            backward[roads[i][1]].push_back({currcost, roads[i][0]});
        }
        vector<vector<long long int>> forwardcost(n, vector<long long int>(n, 1e14)) , backwardcost(n, vector<long long int>(n, 1e15));
        filler(forward, forwardcost);
        filler(backward, backwardcost);
        vector<int> req(n);
        for(int i=0; i<n; i++)
        {
            long long int curr = 1e16;
            for(int j=0; j<n; j++)
            {
                long long int currprice = forwardcost[i][j] + backwardcost[i][j] + prices[j];
                curr = min(currprice, curr);
            }
            req[i] = curr;
        }
        return req;
    }
};