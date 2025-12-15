class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long int n = prices.size();
        long long int req = 0;
        for(int i=0, j=0; i<n; i++)
        {
            if(j<i) j = i;
            while(j<n-1 && prices[j]-prices[j+1]==1) j++;
            //cout << i << " " << j << endl;
            req = req + (j-i+1);
        }
        return req;
    }
};