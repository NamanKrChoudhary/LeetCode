class Solution {
public:
    const long long int mod = 1e9+7;

    long long int modpow(long long int a, long long int b)
    {
        long long int res = 1;
        while(b)
        {
            if(b&1) res = (res*a)%mod;
            a = (a*a)%mod;
            b = b/2;
        }
        return res;
    }

    int minMaxSums(vector<int>& nums, int k) {
        vector<long long int> fact(1e5+1), invfact(1e5+1);
        fact[0] = 1;
        for(int i=1; i<=1e5; i++) fact[i] = (fact[i-1]*i)%mod;
        invfact[1e5] = modpow(fact[1e5], mod-2);
        for(int i=1e5-1; i>=0; i--) invfact[i] = (invfact[i+1]*(i+1))%mod;
        long long int n = nums.size();
        vector<int> arr = nums;
        sort(arr.begin(), arr.end());
        long long int ways = 0;
        for(int i=0; i<arr.size(); i++)
        {
            ways = (((2*arr[i])%mod) + ways)%mod;
            for(int j=1; j<=(k-1); j++)
            {
                if(j<=i)
                {
                    ways = (((((((fact[i]*invfact[j])%mod)*invfact[i-j])%mod)*arr[i])%mod) + ways)%mod;
                }
                if(j<=(n-i-1))
                {
                    long long int tot = n-i-1;
                    ways = (((((((fact[tot]*invfact[j])%mod)*invfact[tot-j])%mod)*arr[i])%mod) + ways)%mod;
                }
                if(j>i && j>(n-i-1)) break;
            }
        }
        return ways;
    }
};