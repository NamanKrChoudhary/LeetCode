class Solution {
public:
    const long long int mod = 1e9+7;
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        // dp[i][j][rem] = state = i,jth cell = no of paths to this cell which result in sum having modk = rem
        // transition - dp[i][j][rem] = (dp[i-1][j][(rem-(grid[i][j]%k)+k)%k]) + (dp[i][j-1][(rem-(grid[i][j]%k)+k)%k]);
        long long int n = grid.size();
        long long int m = grid[0].size();
        vector<vector<vector<long long int>>> dp(n, vector<vector<long long int>>(m, vector<long long int>(k, 0)));
        dp[0][0][grid[0][0]%k] = 1;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                for(int rem = 0; rem<k; rem++)
                {
                    if(i > 0) dp[i][j][rem] = (dp[i][j][rem] + dp[i-1][j][(rem-(grid[i][j]%k)+k)%k])%mod;
                    if(j > 0) dp[i][j][rem] = (dp[i][j][rem] + dp[i][j-1][(rem-(grid[i][j]%k)+k)%k])%mod;
                }
            }
        }
        return dp[n-1][m-1][0];
    }
};