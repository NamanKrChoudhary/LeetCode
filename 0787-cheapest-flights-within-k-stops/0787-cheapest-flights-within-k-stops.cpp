class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<long long int, long long int>>> adj(n);
        for(int i=0; i<flights.size(); i++) adj[flights[i][0]].push_back({flights[i][2] , flights[i][1]});
        // {number, weight, node}
        set<vector<long long int>> s;
        s.insert({0, 0, src});
        vector<long long int> price(n, 1e9), no(n, 1e9);
        price[src] = 0; no[src] = 0;
        while(!s.empty())
        {
            vector<long long int> curr = *s.begin(); s.erase(curr);
            long long int node = curr[2], nodeprice = curr[1], nodeno = curr[0];
            //if(node == dst) return nodeprice; 
            if(nodeno > k) continue;
            for(int i=0; i<adj[node].size(); i++) 
            {
                long long int currnode = adj[node][i].second, currprice = adj[node][i].first;
                if(currprice + nodeprice < price[currnode])
                {
                    //if(price[currnode] != 1e9) s.erase({price[currnode], currnode, no[currnode]});
                    price[currnode] = currprice + nodeprice;
                    no[currnode] = nodeno+1;
                    //cout << node << " " << currnode << " " << price[currnode] << " " << no[currnode] << endl;
                    s.insert({no[currnode], price[currnode], currnode});
                }
            }
        }
        for(int i=0; i<n; i++) if(price[i] == 1e9) price[i] = -1;
        //for(int i=0; i<adj.size(); i++) {for(int j=0; j<adj[i].size(); j++) cout << adj[i][j].second << " "; cout << endl;}
        //for(int i=0; i<n; i++) cout << price[i] << " " << no[i] << endl;
        return price[dst];
    }
};