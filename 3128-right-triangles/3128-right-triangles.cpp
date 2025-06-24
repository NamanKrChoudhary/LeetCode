class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        long long int n = grid.size();
        long long int ways = 0;
        vector<long long int> row(n), col(grid[0].size());
        for(int i=0; i<n; i++)
        {
            long long int prev = 0;
            for(int j=0; j<grid[i].size(); j++) prev = prev + grid[i][j];
            row[i] = prev;
        }
        for(int j=0; j<grid[0].size(); j++)
        {
            long long int prev = 0;
            for(int i=0; i<n; i++) prev = prev + grid[i][j];
            col[j] = prev;
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<grid[i].size(); j++) if(grid[i][j] == 1) ways = ways + ((row[i]-1)*(col[j]-1));
        }
        return ways;
    }
};