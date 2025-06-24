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

    long long int ncr(long long int n, long long int r, vector<long long int>& fact, vector<long long int>& invfact)
    {
        return (((fact[n]*invfact[r])%mod)*invfact[n-r])%mod;
    }

    vector<int> waysToFillArray(vector<vector<int>>& queries) {
        vector<long long int> fact(1e5+1), invfact(1e5+1);
        fact[0] = 1;
        for(int i=1; i<=1e5; i++) fact[i] = (fact[i-1]*i)%mod;
        invfact[1e5] = modpow(fact[1e5], mod-2);
        for(int i=1e5-1; i>=0; i--) invfact[i] = (invfact[i+1]*(i+1))%mod;
        vector<int> ways(queries.size());
        for(int i=0; i<queries.size(); i++)
        {
            long long int currk = queries[i][1];
            long long int currn = queries[i][0];
            vector<int> pr;
            long long int tcurrk = currk;
            for(int j=2; j*j<=tcurrk; j++)
            {
                long long int cnt = 0;
                while(currk%j == 0)
                {
                    currk = currk/j;
                    cnt = cnt + 1;
                }
                if(cnt > 0)pr.push_back(cnt);
            }
            if(currk != 1) pr.push_back(1);
            long long int currways = 1;
            for(int j=0; j<pr.size(); j++)
            {
                currways = (currways*ncr(pr[j]+currn-1, currn-1, fact, invfact))%mod;
            }
            ways[i] = currways;
        }
        return ways;
    }
};