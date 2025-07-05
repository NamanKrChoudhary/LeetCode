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

    int countKSubsequencesWithMaxBeauty(string s, int k) {
        vector<long long int> fact(2*(1e5 + 1));
        fact[0] = 1;
        for(int i=1; i<=2*1e5; i++) fact[i] = (fact[i-1]*i)%mod;
        vector<long long int> invfact(2*(1e5+1));
        invfact[(2*1e5)] = modpow(fact[2*1e5], mod-2);
        for(int i=2*1e5 - 1; i>=0; i--) invfact[i] = (invfact[i+1]*(i+1))%mod;
        map<char, long long int> mp;
        for(int i=0; i<s.size(); i++) mp[s[i]]++;
        if(mp.size() < k) return 0;
        vector<long long int> arr;
        for(auto i: mp) arr.push_back(i.second);
        sort(arr.rbegin(), arr.rend());
        long long int cnt = 0;
        long long int prev = arr[0];
        long long int tot = 0;
        long long int ways = 1;
        for(int i=0; i<arr.size(); i++)
        {
            if(arr[i] == prev) cnt = cnt + 1;
            else
            {
                ways = ((ways*modpow(prev, cnt)))%mod;
                prev = arr[i];
                if(tot+cnt >= k) break;
                tot = tot + cnt;
                cnt = 1;
            }
        }
        long long int req = k-tot;
        ways = (((((((fact[cnt]*invfact[req])%mod)*invfact[cnt-req])%mod)*modpow(prev, req))%mod)*ways)%mod;
        return ways;
    }
};