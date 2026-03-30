class Solution {
public:
    long long beautifulSubstrings(string s, int k) {
        long long int n = s.size();
        long long int vow = 0, con = 0;
        vector<long long int> spf(1001,-1);
        spf[0] = 1, spf[1] = 1;
        for(long long int i=2; i<=1000; i++)
        {
            if(spf[i] == -1)
            {
                spf[i] = i;
                for(long long int j=i*i; j<=1e3; j=j+i) if(spf[j] == -1) spf[j] = i;
            }
        }
        map<long long int, long long int> pf;
        long long int temp = k;
        while(temp > 1)
        {
            pf[spf[temp]]++;
            temp = temp/spf[temp];
            //cout << temp << endl;
        }
        long long int mod = 1;
        for(auto i: pf)
        {
            if(i.second%2 == 1)
            {
                for(int j=0; j<(i.second/2)+1; j++) mod = mod*i.first;
            }
            else for(int j=0; j<(i.second/2); j++) mod = mod*i.first;
            //cout << "here" << endl;
        }
        //cout << mod << endl;
        vector<long long int> prefvow(n), prefcon(n);
        set<char> vows = {'a','e','i','o','u'};
        set<char> cons;
        for(int i=0; i<26; i++)
        {
            if(vows.find('a'+i) == vows.end()) cons.insert('a'+i);
        }
        for(int i=0; i<n; i++)
        {
            if(vows.find(s[i]) != vows.end()) vow = vow+1;
            else con = con + 1;
            prefvow[i] = vow;
            prefcon[i] = con;
        }
        //vector<long long int> diff(n), prod(n);
        map<vector<long long int>, long long int> mp;
        for(int i=0; i<n; i++)
        {
            //cout << prefvow[i] << " " << prefcon[i] << " ";
            //diff[i] = (prefvow[i]-prefcon[i]);
            //prod[i] = ((prefvow[i]%k)*(prefcon[i]%k))%k;
            //cout << diff[i] << " " << prod[i] << endl;
            mp[{prefvow[i]-prefcon[i], prefvow[i]%mod, prefcon[i]%mod}]++;
        }
        mp[{0,0,0}]++;
        long long int req = 0;
        for(auto i: mp)
        {
            if(i.second > 1) req = req + ((i.second*(i.second-1))/2);
            // for(int j=0; j<3; j++) cout << i.first[j] << " "; cout << endl;
            // cout << i.second << endl;
        }
        return req;
    }
};