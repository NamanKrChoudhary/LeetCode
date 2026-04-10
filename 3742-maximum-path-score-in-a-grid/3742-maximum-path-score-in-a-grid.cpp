class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        long long int n = grid.size();
        long long int m = grid[0].size();
        long long int (*dp)[200][1001] = new long long int[n][200][1001];
        for(int i=0; i<n; i++) for(int j=0; j<m; j++) for(int l=0; l<=k; l++) dp[i][j][l] = -1;
        //cout << dp[0][1][1] << endl;
        if(grid[0][0] == 0) for(int i=0; i<k+1; i++) dp[0][0][i] = 0;
        else if(grid[0][0] == 1) for(int i=1; i<=k; i++) dp[0][0][i] = 1;
        else for(int i=1; i<=k; i++) dp[0][0][i] = 2;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(i==0 && j==0) continue;
                if(grid[i][j] == 0)
                {
                    if(i>0) dp[i][j][0] = dp[i-1][j][0];
                    if(j>0) dp[i][j][0] = max(dp[i][j-1][0], dp[i][j][0]);
                }
                for(int l=1; l<=k; l++)
                {
                    long long int up = -1, left = -1;
                    if(i>0)
                    {
                        if(grid[i][j] == 0) up = dp[i-1][j][l];
                        else if(grid[i][j] == 1 && dp[i-1][j][l-1] != -1) up = dp[i-1][j][l-1]+1;
                        else if(grid[i][j] == 2 && dp[i-1][j][l-1] != -1) up = dp[i-1][j][l-1]+2;
                    }
                    if(j>0)
                    {
                        if(grid[i][j] == 0) left = dp[i][j-1][l];
                        else if(grid[i][j] == 1 && dp[i][j-1][l-1] != -1) left = dp[i][j-1][l-1] + 1;
                        else if(grid[i][j] == 2 && dp[i][j-1][l-1] != -1) left = dp[i][j-1][l-1]+2;
                    }
                    dp[i][j][l] = max(up, left);
                    // cout << i << " " << j << " " << l << endl;
                    // cout << left << " " << up << endl;
                }
            }
        }
        //cout << dp[0][1][0] << endl;
        long long int req = dp[n-1][m-1][k];
        delete[] dp;
        return req;
    }
};