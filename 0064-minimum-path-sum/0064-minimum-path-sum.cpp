class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<int> arr(grid[0].size());
        for(int i=0; i<grid.size(); i++)
        {
            vector<int> temp(grid[0].size());
            for(int j=0; j<grid[0].size(); j++)
            {
                int up = -1; int left = -1;
                if(j>0) left = temp[j-1];
                if(i>0) up = arr[j];
                if(left == -1 && up == -1) {temp[j] = grid[i][j]; continue;}
                if(left == -1) {temp[j] = up + grid[i][j]; continue;}
                if(up == -1) {temp[j] = left + grid[i][j]; continue;}
                temp[j] = grid[i][j] + min(up, left);
            }
            arr = temp;
        }
        return arr[grid[0].size()-1];
    }
};