class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<long long int> minn(prices.size());
        long long int n = prices.size();
        long long int prev = LONG_MAX;
        for(int i=0; i<n; i++)
        {
            if(prices[i] < prev) prev = prices[i];
            minn[i] = prices[i]-prev;
        }
        long long int maxx = 0;
        for(int i=0; i<n; i++) maxx = max(maxx, minn[i]);
        return maxx;
    }
};