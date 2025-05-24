class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        long long int n = heights.size(), m = heights[0].size();
        vector<vector<long long int>> effort(n, vector<long long int>(m, 1e9));
        vector<int> r = {-1, 0 , 1, 0}, c = {0, 1, 0, -1};
        effort[0][0] = 0;
        set<vector<long long int>> s;
        s.insert({0, 0, 0});
        while(!s.empty())
        {
            vector<long long int> curr = *s.begin(); s.erase(curr);
            long long int curreffort = curr[0], nodei = curr[1], nodej = curr[2], nodeh = heights[nodei][nodej];
            for(int i=0; i<4; i++)
            {
                long long int curri = nodei+r[i], currj = nodej+c[i];
                if(curri>=0 && currj>=0 && curri<n && currj<m && max(curreffort,abs(nodeh-heights[curri][currj])) < effort[curri][currj])
                {
                    if(effort[curri][currj] != LONG_MAX) s.erase({effort[curri][currj], curri, currj});
                    effort[curri][currj] = max(curreffort, abs(nodeh-heights[curri][currj]));
                    s.insert({effort[curri][currj], curri, currj});
                }
            }
        }
        return effort[n-1][m-1];
    }
};