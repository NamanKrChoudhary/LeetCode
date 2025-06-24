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

    int countAnagrams(string s) {
        vector<long long int> fact(1e5+1), invfact(1e5+1);
        fact[0] = 1;
        for(int i = 1; i<=1e5; i++) fact[i] = (fact[i-1]*i)%mod;
        invfact[1e5] = modpow(fact[1e5], mod-2);
        for(int i=1e5-1; i>=0; i--) invfact[i] = (invfact[i+1]*(i+1))%mod;
        vector<string> arr;
        string temp = "";
        for(int i=0; i<s.size(); i++)
        {
            if(s[i] == ' ')
            {
                arr.push_back(temp);
                temp = "";
                continue;
            }
            temp.push_back(s[i]);
        }
        if(!temp.empty()) arr.push_back(temp);
        long long int ways = 1;
        for(int i=0; i<arr.size(); i++)
        {
            map<char, int> mp;
            for(int j=0; j<arr[i].size(); j++) mp[arr[i][j]]++;
            long long int curr = fact[arr[i].size()];
            for(auto j: mp) curr = (curr*invfact[j.second])%mod;
            ways = (ways*curr)%mod;
        }
        return ways;
    }
};