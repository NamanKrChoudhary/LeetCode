class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        long long int n = prices.size(); 
        vector<vector<long long int>> v(n+1, vector<long long int>(2));
        for(int i=n-1; i>=0; i--)
        {
            for(int j=0; j<2; j++)
            {
                if(j)
                {
                    v[i][j] = max((-prices[i]-fee + v[i+1][0]), (0 + v[i+1][1]));
                }
                else 
                {
                    v[i][j] = max((prices[i] + v[i+1][1]), (0 + v[i+1][0]));
                }
            }
        }
        return v[0][1];
    }
};