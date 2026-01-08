class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        long long int n = nums1.size(), m = nums2.size();
        vector<vector<long long int>> dp(n, vector<long long int>(m,0));
        vector<long long int> n1(n), n2(m);
        for(int i=0; i<n; i++) n1[i] = nums1[i];
        for(int i=0; i<m; i++) n2[i] = nums2[i];
        dp[0][0] = n1[0]*n2[0];
        for(int i=1; i<n; i++) dp[i][0] = max(dp[i-1][0], static_cast<long long int>(n1[i]*n2[0]));
        for(int i=1; i<m; i++) dp[0][i] = max(dp[0][i-1], static_cast<long long int>(n1[0]*n2[i]));
        for(int i=1; i<n; i++)
        {
            for(int j=1; j<m; j++)
            {
                long long int up = dp[i-1][j], left = dp[i][j-1], both = max(0LL,dp[i-1][j-1]) + (n1[i]*n2[j]);
                // if(i>0) up = dp[i-1][j];
                // if(j>0) left = dp[i][j-1];
                // if(i>0 && j>0) both = both + dp[i-1][j-1];
                dp[i][j] = max(up, max(left, both));
            }
        }
        // for(int i=0; i<n; i++)
        // {
        //     for(int j=0; j<m; j++) cout << dp[i][j] << " "; cout << endl;
        // }
        return dp[n-1][m-1];
    }
};