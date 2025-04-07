class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> v(n, vector<int>(m));
        for(int i=0; i<n; i++) for(int j=0; j<m; j++) v[i][j] = -1;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] == 2)
                {
                    queue<pair<int, int>> q;
                    q.push({i,j});
                    vector<vector<bool>> check(n, vector<bool>(m));
                        int l = 1;
                        while(!q.empty())
                        {
                            int len = q.size();
                            for(int k=0; k<len; k++)
                            {
                                pair<int, int> curr = q.front();
                                q.pop();
                                if(curr.first<n-1 && !check[curr.first+1][curr.second] && grid[curr.first+1][curr.second] == 1) 
                                {
                                    if(v[curr.first+1][curr.second] == -1) v[curr.first+1][curr.second] = l;
                                    else v[curr.first+1][curr.second] = min(l, v[curr.first+1][curr.second]);
                                    q.push({curr.first+1, curr.second});
                                    check[curr.first+1][curr.second] = true;
                                }
                                if(curr.second<m-1 && !check[curr.first][curr.second+1] && grid[curr.first][curr.second+1] == 1)
                                {
                                    if(v[curr.first][curr.second+1] == -1) v[curr.first][curr.second+1] = l;
                                    else v[curr.first][curr.second+1] = min(l, v[curr.first][curr.second+1]);
                                    q.push({curr.first,curr.second+1});
                                    check[curr.first][curr.second+1] = true;
                                }
                                if(curr.first>0 && !check[curr.first-1][curr.second] && grid[curr.first-1][curr.second] == 1)
                                {
                                    if(v[curr.first-1][curr.second] == -1) v[curr.first-1][curr.second] = l;
                                    else v[curr.first-1][curr.second] = min(l, v[curr.first-1][curr.second]);
                                    q.push({curr.first-1, curr.second});
                                    check[curr.first-1][curr.second] = true;
                                }
                                if(curr.second>0 && !check[curr.first][curr.second-1] && grid[curr.first][curr.second-1] == 1)
                                {
                                    if(v[curr.first][curr.second-1] == -1) v[curr.first][curr.second-1]  = l;
                                    else v[curr.first][curr.second-1] = min(l, v[curr.first][curr.second-1]);
                                    q.push({curr.first,curr.second-1});
                                    check[curr.first][curr.second-1] = true;
                                }
                            }
                            l++;
                        }
                    
                }
            }
        }
        bool check = false;
        for(int i=0; i<n; i++) for(int j=0; j<m; j++) if(grid[i][j] == 1 && v[i][j] == -1) {check = true; break;}
        if(check) return -1;
        int minn = 0;
        for(int i=0; i<n; i++) {for(int j=0; j<m; j++) if(grid[i][j] == 1) minn = max(minn, v[i][j]); }
        return minn;
    }
};