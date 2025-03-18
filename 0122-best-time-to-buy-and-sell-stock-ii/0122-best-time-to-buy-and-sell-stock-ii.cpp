class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //vector<vector<long long int>> v(prices.size(), vector<long long int>(prices.size()));
        vector<long long int> v(prices.size());
        long long int n = prices.size();
        long long int profit = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(j<i)
                {
                    profit =  max(profit, v[j] + (prices[i]- prices[j]));
                    //v[i][j] = v[j][j] + prices[i]-prices[j];
                }
                else if(j == i)
                {
                    v[j] = profit;
                    //if(j > 0) v[i][j] =  v[j-1][j-1];
                    //v[i][j] = profit;
                }
                //else v[i][j] = profit;
            }
        }
        //for(int i=0; i<n; i++) {for(int j=0; j<n; j++) cout << v[i][j] << " "; cout << endl;}
        return v[prices.size()-1];
    }
};