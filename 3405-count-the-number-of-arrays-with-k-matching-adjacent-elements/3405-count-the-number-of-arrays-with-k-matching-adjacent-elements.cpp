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



    int countGoodArrays(int n, int m, int k) {
        vector<long long int> fact(1e5+1), invfact(1e5+1);
        fact[0] = 1;
        for(int i=1; i<=1e5; i++) {fact[i] = (fact[i-1]*i)%mod;}
        invfact[1e5] = modpow(1e5, mod-2);
        for(int i=1e5-1; i>=0; i--) {invfact[i] = (invfact[i+1]*(i+1))%mod;}

        // sticks = no of different adj pairs = total - no of same = (n-1)-k;
        long long int sticks = (n-1)-k;
        long long int beggars = sticks+1;
        // ways to distribute among sticks+1 beggars = (elements+sticks)c(sticks);
        long long int divide_ways = (((fact[n+sticks]*invfact[sticks])%mod)*invfact[n])%mod;
        cout << invfact[2] << endl;
        long long int different_ways = m;
        for(int i=1; i<beggars; i++)
        {
            different_ways = (different_ways*(m-1))%mod;
        }
        long long int tot = (divide_ways*different_ways)%mod;
        return mod;
    }
};