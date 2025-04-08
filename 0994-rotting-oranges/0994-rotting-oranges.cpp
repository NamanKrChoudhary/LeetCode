class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m));
        for(int i=0; i<n; i++) for(int j=0; j<m; j++) vis[i][j] = -1;
        queue<pair<int,int>> q;
        for(int i=0; i<n; i++) for(int j=0; j<m; j++) if(grid[i][j] == 2) q.push({i,j});
        long long int l = 0;
        while(!q.empty())
        {
            l++;
            int len = q.size();
            for(int i=0; i<len; i++)
            {
                pair<int, int> curr = q.front();
                q.pop();
                if(curr.first>0 && vis[curr.first-1][curr.second] == -1 && grid[curr.first-1][curr.second] == 1)
                {
                    vis[curr.first-1][curr.second] = l;
                    q.push({curr.first-1, curr.second});
                }
                if(curr.second>0 && vis[curr.first][curr.second-1] == -1 && grid[curr.first][curr.second-1] == 1)
                {
                    vis[curr.first][curr.second-1] = l;
                    q.push({curr.first, curr.second-1});
                }
                if(curr.first<n-1 && vis[curr.first+1][curr.second] == -1 && grid[curr.first+1][curr.second] == 1)
                {
                    vis[curr.first+1][curr.second] = l;
                    q.push({curr.first+1, curr.second});
                }
                if(curr.second<m-1 && vis[curr.first][curr.second+1] == -1 && grid[curr.first][curr.second+1] == 1)
                {
                    vis[curr.first][curr.second+1] = l;
                    q.push({curr.first, curr.second+1});
                }
            }
        }
        int maxx = 0;
        bool check = false;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] == 1)
                {
                    if(vis[i][j] == -1) {check = true; break;}
                    else maxx = max(maxx, vis[i][j]);
                }
            }
            if(check) break;
        }
        if(check) return -1;
        else return maxx;
    }
};