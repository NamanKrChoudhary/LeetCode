class Solution {
public:
    const long long int mod = 1e9+7;
    int countPartitions(vector<int>& nums, int k) {
        // dp[i] = no of ways it is to divide the array of size i such that it follows the given condition.
        // dp[i] = dp[i-1]+dp[i-2]....dp[j] where j = first index where the condition fails for interval [j,i]; 
        // dp[0] = base condition = 1; 
        long long int n = nums.size();
        vector<long long int> dp(nums.size()+1); dp[0] = 1;
        vector<long long int> prefdp(nums.size()+1); prefdp[0] = 1;
        vector<long long int> arr(nums.size()+1);
        for(int i=1; i<=n; i++) arr[i] = nums[i-1];
        set<pair<long long int, long long int>> elements;
        for(int i=1, j=1; i<=n; i++)
        {
            elements.insert({arr[i], i});
            while(!elements.empty() && ((*elements.rbegin()).first) - ((*elements.begin()).first) > k)
            {
                elements.erase({arr[j],j});
                j = j+1;
            }
            dp[i] = (((prefdp[i-1]-prefdp[j-1]+mod)%mod)+dp[j-1])%mod;
            prefdp[i] = (dp[i]+prefdp[i-1])%mod;
        }
        return dp[n];
    }
};