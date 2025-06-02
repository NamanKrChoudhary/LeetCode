class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        if(node1 == node2) return node1;
        long long int n = edges.size();
        queue<long long int> q1, q2;
        vector<long long int> n1(n, -1), n2(n, -1);
        q1.push(node1);
        long long int cnt = 0;
        n1[node1] = cnt;
        while(!q1.empty())
        {
            long long int curr = q1.front();
            q1.pop();
            cnt = cnt + 1;
            if(edges[curr] == -1 || n1[edges[curr]] != -1) break;
            n1[edges[curr]] = cnt;
            q1.push(edges[curr]);
        }
        cnt = 0;
        n2[node2] = cnt;
        q2.push(node2);
        while(!q2.empty())
        {
            long long int curr = q2.front();
            q2.pop();
            cnt = cnt + 1;
            if(edges[curr] == -1 || n2[edges[curr]] != -1) break;
            n2[edges[curr]] = cnt;
            q2.push(edges[curr]);
        }
        vector<pair<long long int, long long int>> ans;
        pair<long long int, long long int> fin = {1e9, 1e9};
        for(int i=0; i<n; i++)
        {
            if(n1[i] != -1 && n2[i] != -1) 
            {
                ans.push_back({max(n1[i], n2[i]), i});
                if(fin.first > max(n1[i], n2[i])) fin = {max(n1[i], n2[i]), i};
            }
        }
        if(ans.empty()) return -1;
        return fin.second;
    }
};