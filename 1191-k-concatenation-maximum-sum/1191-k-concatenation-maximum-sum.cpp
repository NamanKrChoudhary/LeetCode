class Solution {
public:
    const long long int mod = 1e9+7;
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        long long int n = arr.size();
        vector<long long int> pref(n);
        pref[0] = arr[0];
        for(int i=1; i<n; i++) pref[i] = pref[i-1] + arr[i];
        long long int maxx = 0;
        long long int i = 0, j = 0;
        while(i<arr.size() && j<arr.size())
        {
            if(j < i) i = j;
            long long int curr = pref[j]-pref[i]+arr[i];
            if(curr < 0)
            {
                j = j+1;
                i = j;
                continue;
            }
            else
            {
                maxx = max(maxx, curr);
                j = j+1;
            }
        }
        if(k == 1)
        {
            return maxx;
        }
        long long int req = 0;
        long long int maxleft = 0, maxright = pref[n-1];
        for(int i=0; i<n; i++)
        {
            maxleft = max(maxleft, pref[i]);
            maxright = max(maxright, pref[n-1]-pref[i]);
        }
        if(pref[n-1] > 0) req = ((((((k-2)*pref[n-1])%mod) + maxleft)%mod) + maxright)%mod;
        else req = max(maxx, maxleft + maxright);
        return req%mod;
    }
};