class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<int> arr(obstacleGrid[0].size(),0);
        arr[0]=1;
        for(int i=0; i < obstacleGrid.size(); i++)
        {
            vector<int> curr(obstacleGrid[0].size(),0);
            for(int j=0; j<obstacleGrid[0].size(); j++)
            {
                if(obstacleGrid[i][j] == 1) {curr[j] = -1; continue;}
                int up = 0, left = 0;
                if(arr[j] != -1) up = arr[j];
                if(j>0 && curr[j-1] != -1) left = curr[j-1];
                curr[j] = up + left;
                cout << i << " " << j << " " << up << " " << left << " " << curr[j] << endl;
            }
            arr = curr;
        }
        return arr[obstacleGrid[0].size()-1];
    }
};