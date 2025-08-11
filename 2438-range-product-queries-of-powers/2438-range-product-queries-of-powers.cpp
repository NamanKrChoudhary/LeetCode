class Solution {
public:
    const long long int mod = 1e9+7;
    long long int modpow(long long int a, long long int b)
    {
        long long int res = 1;
        while(b)
        {
            if(b%2 == 1) res = (res*a)%mod;
            a = (a*a)%mod;
            b = b/2;
        }
        return res;
    }
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<long long int> pows;
        long long int currpow = 1;
        long long int temp = n;
        while(temp)
        {
            if(temp%2 == 1) pows.push_back(currpow);
            currpow = currpow*2;
            temp = temp/2;
        }
        sort(pows.begin(), pows.end());
        vector<long long int> pref(pows.size());
        pref[0] = pows[0];
        for(int i=1; i<pows.size(); i++)
        {
            pref[i] = (pref[i-1]*pows[i])%mod;
        }
        vector<long long int> invpref(pows.size());
        invpref[pows.size()-1] = modpow(pref[pows.size()-1], mod-2);
        for(int i=pows.size()-2; i>=0; i--)
        {
            invpref[i] = (invpref[i+1]*pows[i+1])%mod;
        }
        vector<int> answers(queries.size());
        for(int i=0; i<queries.size(); i++)
        {
            if(queries[i][0] > 0)
            {
                long long int temp = (invpref[queries[i][0]-1]*pref[queries[i][1]])%mod;
                answers[i] = temp;
            }
            else answers[i] = pref[queries[i][1]];
        }
        return answers;
    }
};