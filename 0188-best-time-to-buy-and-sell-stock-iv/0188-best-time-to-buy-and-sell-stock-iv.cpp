class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<long long int>>> v(prices.size()+1, vector<vector<long long int>>(2, vector<long long int>(k+1)));
        long long int n = prices.size();
        for(int i=0; i<=n; i++) for(int j=0; j<2; j++) v[i][j][k] = 0;
        for(int j=0; j<2; j++) for(int l=0; l<=k; l++) v[n][j][l] = 0;
        for(int i=n-1; i>=0; i--)
        {
            for(int j=0; j<2; j++)
            {
                for(int l=0; l<k; l++)
                {
                    if(j)
                    {
                        v[i][j][l] = max((-prices[i] + v[i+1][0][l]), (0 + v[i+1][1][l]));
                    }
                    else
                    {
                        v[i][j][l] = max((prices[i] + v[i+1][1][l+1]), (0 + v[i+1][0][l]));
                    }
                }
            }
        }
        return v[0][1][0];
    }
};