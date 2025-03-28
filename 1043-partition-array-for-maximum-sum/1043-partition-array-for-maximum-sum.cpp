class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> v(n);
        for(int i=n-1; i>=0; i--)
        {
            int maxx = 0, temp = 0;
            for(int j=i; j<min(i+k, n); j++)
            {
                int curr;
                maxx = max(maxx, arr[j]);
                if(j == n-1) curr = (j-i+1)*maxx;
                else curr = ((j-i+1)*maxx) + v[j+1];
                temp = max(temp, curr);
            }
            v[i] = temp;
        }
        return v[0];
    }
};