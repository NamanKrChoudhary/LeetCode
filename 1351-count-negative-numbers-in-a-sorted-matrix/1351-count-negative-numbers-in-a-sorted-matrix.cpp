class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        long long int n = grid.size(), m = grid[0].size();
        long long int cnt = 0;
        for(int i=n-1; i>=0; i--)
        {
            for(int j=m-1; j>=0; j--)
            {
                if(grid[i][j] < 0) cnt = cnt + 1;
                else break;
            }
        }
        return cnt;
    }
};