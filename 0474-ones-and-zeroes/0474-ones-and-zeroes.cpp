class Solution {
public:
    // dp[i][j][k] = in an array of length - max elements i could choose with at max j 0s and k 1s;
    // dp[i][j][k] = max(dp[i-1][j][k], dp[i-1][j-(no of 0s)][k-(no of 1s)]+1);
    int findMaxForm(vector<string>& strs, int m, int n) {
        long long int sz = strs.size();
        vector<pair<long long int, long long int>> bits(sz+1, {0,0});
        vector<vector<vector<long long int>>> dp(sz+1, vector<vector<long long int>>(m+1, vector<long long int>(n+1, 0)));
        for(int i=1; i<=sz; i++)
        {
            long long int cnt = 0;
            for(int j=0; j<strs[i-1].size(); j++) if(strs[i-1][j] == '1') cnt = cnt + 1;
            bits[i].first = strs[i-1].size()-cnt; 
            bits[i].second = cnt;
        }
        for(int i=1; i<=sz; i++)
        {
            for(int j=0; j<=m; j++)
            {
                if(bits[i].first <= j)
                {
                    for(int k=0; k<=n; k++)
                    {
                        if(bits[i].second <= k)
                        {
                            dp[i][j][k] = max(dp[i-1][j][k], dp[i-1][j-bits[i].first][k-bits[i].second]+1);
                        }
                        else dp[i][j][k] = dp[i-1][j][k];
                    }
                }
                else for(int k=0; k<=n; k++) dp[i][j][k] = dp[i-1][j][k];
            }
        }
        //for(int i=1; i<=sz; i++) cout << dp[i][m][n] << " "; cout << endl;
        //if(bits[1].first == 3) cout << dp[2][3][5] << " " << dp[1][3][5] << endl;
        return dp[sz][m][n];
    }
};