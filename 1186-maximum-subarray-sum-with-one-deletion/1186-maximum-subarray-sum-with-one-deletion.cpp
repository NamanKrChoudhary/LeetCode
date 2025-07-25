class Solution {
public:
    int maximumSum(vector<int>& arr) {
        if(arr.size() == 1) return arr[0];
        long long int n = arr.size();
        vector<int> prefix(arr.size());
        prefix[0] = arr[0];
        for(int i=1; i<arr.size(); i++) prefix[i] = arr[i] + prefix[i-1];
        int minn = 0, maxx = INT_MIN;
        vector<int> pre(arr.size()), suf(arr.size());
        for(int i=0; i<arr.size(); i++)
        {
            pre[i] = minn;
            if(prefix[i] < minn) minn = prefix[i];
        }
        maxx = prefix[n-1];
        for(int i=n-2; i>=0; i--)
        {
            suf[i] = maxx;
            if(prefix[i] > maxx) maxx = prefix[i];
        }
        maxx = *max_element(arr.begin(), arr.end());
        for(int i=0; i<n-1; i++)
        {
            maxx = max(maxx, (suf[i]-pre[i]-(arr[i])));
            maxx = max(maxx, (suf[i]-pre[i]));
        }
        return maxx;
    }
};