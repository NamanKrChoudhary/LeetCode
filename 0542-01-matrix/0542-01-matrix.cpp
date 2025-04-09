class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> vis(n, vector<int>(m));
        queue<pair<int, int>> q;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(mat[i][j] == 0) 
                {
                    vis[i][j] = 0;
                    q.push({i,j});
                }
                else 
                {
                    vis[i][j] = -1;
                }
            }
        }
        int l = 0;
        while(!q.empty())
        {
            l++;
            int len = q.size();
            for(int i=0; i<len; i++)
            {
                pair<int, int> curr = q.front();
                q.pop();
                if(curr.first>0 && vis[curr.first-1][curr.second] == -1 && mat[curr.first-1][curr.second] == 1)
                {
                    vis[curr.first-1][curr.second] = l;
                    q.push({curr.first-1, curr.second});
                }
                if(curr.second>0 && vis[curr.first][curr.second-1] == -1 && mat[curr.first][curr.second-1] == 1)
                {
                    vis[curr.first][curr.second-1] = l;
                    q.push({curr.first, curr.second-1});
                }
                if(curr.first<n-1 && vis[curr.first+1][curr.second] == -1 && mat[curr.first+1][curr.second] == 1)
                {
                    vis[curr.first+1][curr.second] = l;
                    q.push({curr.first+1, curr.second});
                }
                if(curr.second<m-1 && vis[curr.first][curr.second+1] == -1 && mat[curr.first][curr.second+1] == 1)
                {
                    vis[curr.first][curr.second+1] = l;
                    q.push({curr.first, curr.second+1});
                }
            }
        }
        return vis;
    }
};