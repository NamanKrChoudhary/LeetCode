class Solution {
public:
// state = dp[i][j][3] ->
    // dp[i][j][0] = maximum profit when on ith index with j transactions possible remaining and no transaction is in half complete state;
    // dp[i][j][1] = maximum profit when on ith index with j transactions remaining with jth transaction still running with next to sell;
    // dp[i][j][2] = maximum profit when on ith index with j transactions remaining with jth transaction still running with next to buy;
// transition ->
    // dp[i][j][0] = max(dp[i-1][j][0] , -prices[i] + dp[i-1][j][1], prices[i]+dp[i-1][j][2]);
    // dp[i][j][1] = max(dp[i-1][j][1], prices[i] + dp[i-1][j-1][0]);
    // dp[i][j][2] = max(dp[i-1][j][2], -prices[i] + dp[i-1][j-1][0]);
// base case ->
    // dp[0][j][0] = 0;
    // dp[0][j>0][1] = prices[i]
    // dp[0][j>0][2] = -prices[i]
    long long maximumProfit(vector<int>& prices, int k) {
        long long int n = prices.size();
        vector<vector<vector<long long int>>> dp(n, vector<vector<long long int>>(k+1, vector<long long int>(3, 0)));
        dp[0][0][0] = 0;
        for(int i=1; i<=k; i++)
        {
            dp[0][i][0] = 0;
            dp[0][i][1] = prices[0];
            dp[0][i][2] = (-1)*prices[0];
        }
        for(int i=1; i<n; i++)
        {
            for(int j=1; j<=k; j++)
            {
                dp[i][j][0] = max(dp[i-1][j][0], max((-prices[i]+dp[i-1][j][1]), (prices[i]+dp[i-1][j][2])));
                dp[i][j][1] = max(dp[i-1][j][1], (prices[i]+dp[i-1][j-1][0]));
                dp[i][j][2] = max(dp[i-1][j][2], (dp[i-1][j-1][0]-prices[i]));
            }
        }
        //if(n>2 && k >= 2) cout << dp[0][1][2] << endl;
        return dp[n-1][k][0];
    }
};