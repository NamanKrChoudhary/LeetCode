class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if(k == 0) return 1;
        if(n < k) return 0;
        else if(n >= k-1+maxPts) return 1;
        vector<long double> curr(n+1), prev(n+1);
        curr[0] = 1; prev[0] = 1;
        // double firstpt = 1.0/maxPts;
        // curr[0] = (firstpt); prev[0] = (firstpt);
        for(int i=1; i<=k; i++)
        {
            if(i-maxPts <= 0)
            {
                long double temp = prev[i-1];
                //temp = temp + 1;
                temp = temp/maxPts;
                curr[i] = (temp);
                prev[i] = (temp+prev[i-1]);
            }
            else
            {
                long double temp = (prev[i-1] - prev[i-maxPts] + curr[i-maxPts]);
                temp = temp/maxPts;
                curr[i] = (temp);
                prev[i] = (temp+prev[i-1]);
            }
        }
        for(int i=k+1; i<=n; i++)
        {
            if(i-maxPts <= 0)
            {
                long double temp = prev[k-1];
                temp = temp/maxPts;
                curr[i] = temp;
            }
            else 
            { 
                long double temp = curr[i-maxPts];
                temp = temp + prev[k-1] - prev[i-maxPts];
                temp = temp/maxPts;
                curr[i] = temp;
                //cout << i << " " << temp << endl;
            }
        }
        long double prob = 0;
        //for(int i=0; i<n; i++) cout << curr[i] << " ";  cout << endl;
        for(int i=k; i<=n; i++) prob = prob + curr[i];
        return prob;
    }
};