class Solution {
public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        vector<int> row = {-1, 0, 1, 0};
        vector<int> col = {0, -1, 0, 1};
        // steps, price, row, col;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, grid[start[0]][start[1]], start[0], start[1]});
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        vis[start[0]][start[1]] = true;
        vector<vector<int>> req;
        while(!pq.empty())
        {
            vector<int> curr = pq.top();
            pq.pop();
            if(curr[1] >= pricing[0] && curr[1] <= pricing[1]) req.push_back({curr[2], curr[3]});
            if(req.size() == k) break;
            for(int i=0; i<4; i++)
            {
                int nexti = curr[2]+row[i], nextj = curr[3]+col[i];
                if(nexti >= 0 && nextj >= 0 && nexti < n && nextj < m && !vis[nexti][nextj] && grid[nexti][nextj] > 0)
                {
                    vis[nexti][nextj] = true;
                    pq.push({curr[0]+1, grid[nexti][nextj], nexti, nextj});
                }
            }
        }
        return req;
    }
};