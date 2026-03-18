class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        long long int n = grid.size(), m = grid[0].size();
        vector<vector<long long int>> arr(n, vector<long long int>(m,0));
        for(int j=0; j<m; j++)
        {
            long long int temp = 0;
            for(int i=0; i<n; i++)
            {
                temp = temp + grid[i][j];
                arr[i][j] = temp;
            }
        }
        long long int req = 0;
        for(int i=0; i<n; i++)
        {
            long long int temp = 0;
            for(int j=0; j<m; j++)
            {
                if(temp+arr[i][j] <= k)
                {
                    temp = temp + arr[i][j];
                    if(j == m-1) req = req + m;
                }
                else 
                {
                    req = req + j;
                    break;
                }
            }
        }
        return req;
    }
};