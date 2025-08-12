class Solution {
public:
    // dp[currn][curri] = the no of ways to make currn with only the powers upto curri index;
    long long int mod = 1e9+7;

    long long int ways(vector<vector<long long int>>& dp, vector<long long int>& pows, long long int currn, long long int curri)
    {
        if(currn == 0) return 1;
        if(currn < 0) return 0;
        else if(curri < 0) return 0;
        if(dp[currn][curri] != -1) return dp[currn][curri];
        long long int way = 0;
        way = (way + ways(dp, pows, currn-pows[curri], curri-1))%mod;
        way = (way + ways(dp, pows, currn, curri-1))%mod;
        return dp[currn][curri] = way;
    }

    int numberOfWays(int n, int x) {
        vector<long long int> pows;
        for(int i=1; i<=n; i++)
        {
            long long int curr = 1;
            for(int j=0; j<x; j++) curr = curr*i;
            if(curr <= n) pows.push_back(curr);
            else break;
        }
        // for(int i=0; i<n; i++)
        // {
        //     for(int j=0; j<pows.size(); j++) cout << pows[i]
        // }
        vector<vector<long long int>> dp(n+1, vector<long long int>(pows.size(),-1));
        return ways(dp, pows, n, pows.size()-1)%mod;
    }
};