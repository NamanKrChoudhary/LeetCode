class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<long long int>>> v(prices.size()+1, vector<vector<long long int>>(2, vector<long long int>(2)));
        long long int n = prices.size();
        v[n][1][1] = 0; v[n][1][0] = 0; v[n][0][0] = 0; v[n][0][1] = 0;
        for(int i=n-1; i>=0; i--)
        {
            for(int j=0; j<2; j++)
            {
                for(int k=0; k<2; k++)
                {
                    if(j)
                    {
                        v[i][j][k] = max((-prices[i] + v[i+1][0][k]), (0 + v[i+1][1][k]));
                    }
                    else
                    {
                        //if(i <=2) continue;
                        if(k) v[i][j][k] = max((prices[i]), int(v[i+1][j][k]));
                        else v[i][j][k] = max((prices[i] + v[i+1][1][1]), (0 + v[i+1][j][0]));
                    }
                }
            }
        }
        return v[0][1][0];
    }
};