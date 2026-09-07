class Solution {
public:
    int distinctSubseqII(string s) {
        const long long int mod = 1e9+7;
        long long int n = s.size();
        vector<vector<long long int>> dp(n, vector<long long int>(26, 0));
        vector<long long int> suf(26,0);
        long long int sum = 0;
        for(int i=n-1; i>=0; i--)
        {
            for(int j=0; j<26; j++)
            {
                if(s[i] == ('a'+j)) 
                {
                    dp[i][j] = (sum + 1)%mod;
                    sum = (sum-suf[j]+mod)%mod;
                    sum = (sum + dp[i][j])%mod;
                    suf[j] = dp[i][j];
                }
                else dp[i][j] = suf[j];
            }
        }
        long long int req = 0;
        for(int i=0; i<26; i++) req = (req + dp[0][i])%mod;
        return req;
    }
};