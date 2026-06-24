class Solution {
    // arr[ind][num][inc/dec] - state - index, number currently chosen, 0 = prev less, 1 = prev more;
public:
    const long long int mod = 1e9+7;
    int zigZagArrays(int n, int l, int r) {
        //vector<vector<vector<long long int>>> dp(n, vector<vector<long long int>>(r-l+1, vector<long long int>(2, 0)));
        long long int m = r-l+1;
        long long int dp[n][m][2];
        for(int i=0; i<n; i++) for(int j=0; j<m; j++) for(int k=0; k<2; k++) dp[i][j][k] = 0;
        for(int i=0; i<m; i++) {dp[0][i][0] = 1; dp[0][i][1] = 1;}
        if(n == 1) return r-l+1;
        for(int i=1; i<n; i++)
        {
            for(int j=1; j<m; j++) dp[i-1][j][1] = (dp[i-1][j-1][1] + dp[i-1][j][1])%mod;
            for(int j = m-2; j>=0; j--) dp[i-1][j][0] = (dp[i-1][j+1][0] + dp[i-1][j][0])%mod;
            for(int j=0; j<m; j++)
            {
                if(j>0) dp[i][j][0] = dp[i-1][j-1][1];
                if(j<m-1) dp[i][j][1] = dp[i-1][j+1][0];
            }
        }
        long long int req = 0;
        for(int i=0; i<m; i++) req = (((req + dp[n-1][i][0])%mod) + dp[n-1][i][1])%mod;
        return req;
    }
};