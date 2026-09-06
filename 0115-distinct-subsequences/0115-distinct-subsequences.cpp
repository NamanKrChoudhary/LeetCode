class Solution {
public:
    int numDistinct(string s, string t) {
        long long int n = t.size(), m = s.size();
        vector<vector<unsigned long long int>> dp(n, vector<unsigned long long int>(m, 0));
        if(s[m-1] == t[n-1]) dp[n-1][m-1] = 1;
        for(int i=n-1; i>=0; i--)
        {
            for(int j=m-1; j>=0; j--)
            {
                if(i == n-1 && j == m-1) continue;
                if(t[i] == s[j])
                {
                    if(i < n-1 && j < m-1) dp[i][j] += dp[i+1][j+1] + dp[i][j+1];
                    else if(j < m-1) dp[i][j] += 1 + dp[i][j+1];
                }
                else
                {
                    if(j < m-1) dp[i][j] += dp[i][j+1];
                }
            }
        }
        // for(int i=0; i<n; i++)
        // {
        //     for(int j=0; j<m; j++) cout << dp[i][j] << " "; cout << endl;
        // }
        return dp[0][0];
    }
};