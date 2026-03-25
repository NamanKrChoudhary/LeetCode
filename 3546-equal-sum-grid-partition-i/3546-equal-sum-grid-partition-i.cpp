class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        vector<long long int> colsum(grid[0].size());
        vector<long long int> rowsum(grid.size());
        long long int total = 0;
        for(int i=0; i<grid.size(); i++)
        {
            long long int temp = 0;
            for(int j=0; j<grid[i].size(); j++) {temp = temp + grid[i][j]; total = total + grid[i][j];}
            rowsum[i] = temp;
        }
        for(int j=0; j<grid[0].size(); j++)
        {
            long long int temp = 0;
            for(int i=0; i<grid.size(); i++) temp = temp + grid[i][j];
            colsum[j] = temp;
        }
        long long int cum = 0;
        for(int i=0; i<rowsum.size(); i++)
        {
            cum = cum + rowsum[i];
            if(total-cum == cum) return true;
        }
        cum = 0;
        for(int i=0; i<colsum.size(); i++)
        {
            cum = cum + colsum[i];
            if(total-cum == cum) return true;
        }
        return false;
    }
};