class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        long long int n = piles.size();
        vector<vector<vector<pair<long long int,long long int>>>> dp(n, vector<vector<pair<long long int, long long int>>>(n, vector<pair<long long int, long long int>>(2,{0,0})));
        for(int i=0; i<n; i++) {dp[i][i][0] = {piles[i], 0}; dp[i][i][1] = {0, piles[i]};}
        for(int sz = 2; sz<=n; sz++)
        {
            for(int i=0, j=sz-1; i<n && j<n; i=i+1, j=j+1)
            {
                if(dp[i+1][j][1].first + piles[i] > dp[i][j-1][1].first + piles[j])
                {
                    dp[i][j][0].first = dp[i+1][j][1].first + piles[i];
                    dp[i][j][0].second = dp[i+1][j][1].second;
                }
                else 
                {
                    dp[i][j][0].first = dp[i][j-1][1].first + piles[j];
                    dp[i][j][0].second = dp[i][j-1][1].second;
                }
                if(dp[i+1][j][0].second + piles[i] > dp[i][j-1][0].second + piles[j])
                {
                    dp[i][j][1].second = dp[i+1][j][0].second + piles[i];
                    dp[i][j][1].first = dp[i+1][j][0].first;
                }
                else
                {
                    dp[i][j][1].second = dp[i][j-1][0].second + piles[j];
                    dp[i][j][1].first = dp[i][j-1][0].first;
                }
            }
        }
        if(dp[0][n-1][0].first >= dp[0][n-1][0].second) return true;
        return false;
    }
};