class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        long long int n = grid.size(), m = grid[0].size();
        vector<vector<int>> req(n, vector<int>(m,0));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                long long int currval = grid[i][j];
                long long int next = (i*m)+j+k;
                long long int nexti = (next/m)%n;
                long long int nextj = next%m;
                req[nexti][nextj] = currval;
            }
        }
        return req;
    }
};