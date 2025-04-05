class Solution {
public:
    void dfs(vector<vector<bool>>& vis, vector<vector<char>>& grid, int curri, int currj)
    {
        vis[curri][currj] = true;
        if(curri<grid.size()-1 && grid[curri+1][currj] == '1' && !vis[curri+1][currj]) dfs(vis, grid, curri+1, currj);
        if(currj<grid[0].size()-1 && grid[curri][currj+1] == '1' && !vis[curri][currj+1]) dfs(vis, grid, curri, currj+1);
        if(curri>0 && grid[curri-1][currj] == '1' && !vis[curri-1][currj]) dfs(vis, grid, curri-1, currj);
        if(currj>0 && grid[curri][currj-1] == '1' && !vis[curri][currj-1]) dfs(vis, grid, curri, currj-1);
        return;
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(); int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m));
        int count = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(!vis[i][j] && grid[i][j] == '1')
                {
                    dfs(vis, grid, i, j);
                    count = count + 1;
                }
            }
        }
        return count;
    }
};