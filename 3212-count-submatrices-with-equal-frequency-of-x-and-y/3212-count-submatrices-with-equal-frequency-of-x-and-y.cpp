class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        long long int n = grid.size(), m = grid[0].size();
        vector<vector<vector<long long int>>> arr(n, vector<vector<long long int>>(m, vector<long long int>(3)));
        for(int j=0; j<m; j++)
        {
            vector<long long int> temp(3,0);
            for(int i=0; i<n; i++)
            {
                if(grid[i][j] == 'X') temp[0] = temp[0] + 1;
                else if(grid[i][j] == 'Y') temp[1] = temp[1] + 1;
                else temp[2] = temp[2] + 1;
                arr[i][j] = temp;
            }
        }
        long long int req = 0;
        for(int i=0; i<n; i++)
        {
            vector<long long int> temp(3,0);
            for(int j=0; j<m; j++)
            {
                temp[0] = temp[0] + arr[i][j][0];
                temp[1] = temp[1] + arr[i][j][1];
                temp[2] = temp[2] + arr[i][j][2];
                if(temp[0] > 0 && temp[0] == temp[1]) req = req + 1;
            }
        }
        return req;
    }
};