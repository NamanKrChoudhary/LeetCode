class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        long long int stw = INT_MAX, endw = INT_MIN;
        long long int sth = INT_MAX, endh = INT_MIN;
        long long int n = grid.size(), m = grid[0].size();
        for(long long int i=0; i<n; i++)
        {
            for(long long int j=0; j<m; j++)
            {
                if(grid[i][j] == 1)
                {
                    sth = min(sth, i);
                    endh = max(endh, i);
                    stw = min(stw, j);
                    endw = max(endw, j);
                }
            }
        }
        long long int req = (endw-stw+1)*(endh-sth+1);
        return req;
    }
};