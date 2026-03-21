class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for(int i=x, l =x+k-1; i<l; i++,l--)
        {
            for(int j=y; j<y+k; j++)
            {
                int temp = grid[i][j];
                grid[i][j] = grid[l][j];
                grid[l][j] = temp;
            }
        }
        return grid;
    }
};