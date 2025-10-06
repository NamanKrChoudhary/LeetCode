class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<int>> vis(n, vector<int>(n, false));
        pq.push({grid[0][0], 0, 0});
        while(!pq.empty())
        {
            vector<int> curr = pq.top();
            pq.pop();
            if(curr[1] == n-1 && curr[2] == n-1) return curr[0];
            vector<int> curr1 = {1, 0, -1, 0}, curr2 = {0, -1, 0, 1};
            for(int i=0; i<4; i++)
            {
                int curri = curr[1]+curr1[i], currj = curr[2]+curr2[i];
                if(curri>=0 && currj>=0 && curri<n && currj<n && vis[curri][currj] == false)
                {
                    vis[curri][currj] = true;
                    pq.push({max(grid[curri][currj], curr[0]), curri, currj});
                }
            }
        }
        return 0;
    }
};