class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        long long int n = stoneValue.size();
        vector<long long int> pref(n,0); pref[0] = stoneValue[0];
        for(int i=1; i<n; i++) pref[i] = pref[i-1] + stoneValue[i];
        vector<vector<long long int>> dp(n, vector<long long int>(n, 0));
        for(int sz = 2; sz <=n; sz++)
        {
            for(int i=0, j=sz-1; i<n && j<n; i=i+1, j = j+1)
            {
                long long int totsum = pref[j]-pref[i]+stoneValue[i];
                long long int midsum = totsum/2;
                if(totsum%2 == 1) midsum = midsum + 1;
                for(int k=i; k<j; k++)
                {
                    long long int currsum = pref[k]-pref[i]+stoneValue[i];
                    if(currsum < midsum)
                    {
                        dp[i][j] = max(dp[i][j], dp[i][k]+(currsum));
                    }
                    else if(currsum > midsum)
                    {
                        dp[i][j] = max(dp[i][j], dp[k+1][j]+(totsum-currsum));
                    }
                    else if(totsum%2 == 0)
                    {
                        dp[i][j] = max(dp[i][j], dp[i][k]+(currsum));
                        dp[i][j] = max(dp[i][j], dp[k+1][j]+(totsum-currsum));
                    }
                    else dp[i][j] = max(dp[i][j], dp[k+1][j]+(totsum-currsum));
                }
            }
        } 
        // for(int i=0; i<n; i++) cout << pref[i] << " "; cout << endl; cout << endl;
        // for(int i=0; i<n; i++)
        // {
        //     for(int j=0; j<n; j++) cout << dp[i][j] << " "; cout << endl;
        // }
        return dp[0][n-1];

        // 223
        // 0 2 + 199,, 4 9 + 211
        // 354
        // 4 7 + 64,, 9 9 + 96
    }
};