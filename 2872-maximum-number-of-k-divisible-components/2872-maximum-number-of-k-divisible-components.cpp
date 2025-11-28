#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int comp = 0;

    long long dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& values, int k) {
        long long total = values[node];   
        for (int neighbor : adj[node]) {
            if (neighbor != parent) {
                total += dfs(neighbor, node, adj, values, k);
            }
        }

        if (total % k == 0) {
            comp += 1;
            return 0;
        }
        return total % k;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adj(n);
        comp = 0;

        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(0, -1, adj, values, k);
        return comp;
    }
};