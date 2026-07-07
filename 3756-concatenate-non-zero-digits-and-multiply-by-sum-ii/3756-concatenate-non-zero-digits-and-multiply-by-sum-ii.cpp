class Solution {
public:
    const long long int mod = 1e9+7;

    long long int modexp(long long int a, long long int b)
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

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        long long int n = s.size();
        vector<int> digs(n+1,0);
        for(int i=1; i<=n; i++) digs[i] = s[i-1]-'0';
        vector<int> valid(n+1,0);
        for(int i=1; i<=n; i++) if(digs[i]>0) valid[i] = 1;
        for(int i=1; i<=n; i++) valid[i] = valid[i] + valid[i-1];
        vector<long long int> modnums(n+1,0);
        modnums[1] = digs[1];
        for(int i=2; i<=n; i++) 
        {
            if(digs[i] > 0) modnums[i] = ((modnums[i-1]*10)%mod) + digs[i];
            else modnums[i] = modnums[i-1];
        }
        vector<long long int> sum(n+1, 0);
        for(int i=1; i<=n; i++) sum[i] = (sum[i-1] + digs[i])%mod;
        vector<int> req;
        for(int i=0; i<queries.size(); i++)
        {
            long long int left = queries[i][0], right = queries[i][1] + 1;
            long long int digno = valid[right]-valid[left];
            long long int prev = (modnums[left]*modexp(10, digno))%mod;
            long long int currx = (modnums[right]-prev+mod)%mod;
            long long int currsum = (sum[right]-sum[left]+mod)%mod;
            long long int curr = (currx*currsum)%mod;
            //cout << digno << " " << prev << endl;
            req.push_back(curr);
        }
        return req;
    }
};