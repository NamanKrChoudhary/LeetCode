class Solution {
public:
    int numberOfSubstrings(string s) {
        long long int n = s.size();
        vector<long long int> prev(n, 0);
        long long int curr = 0;
        for(int i=0; i<n; i++)
        {
            if(s[i] == '0') curr = curr + 1;
            prev[i] = curr;
        }
        vector<vector<long long int>> mp(n+1);
        for(int i=0; i<n; i++) mp[prev[i]].push_back(i);
        long long int reql = sqrt(n) + 1;
        long long int req = 0;
        for(int i=0; i<=reql; i++)
        {
            for(int j=0; j<n; j++)
            {
                long long int nextz = prev[j]+i;
                long long int reqind = j+i+(i*i)-1;
                if(i == 0 && s[j] == '1') reqind = reqind +1;
                if(i == 0 && s[j] == '0') continue;
                if(i>0 && s[j] == '0') nextz = nextz-1;
                //cout << i << " " << j << " " << nextz << " " << reqind << endl;
                if(nextz <= n && !mp[nextz].empty())
                {
                    long long int ind = lower_bound(mp[nextz].begin(), mp[nextz].end(), reqind) - mp[nextz].begin();
                    req = req + (mp[nextz].size() - ind);
                }
                //cout << req << endl;
            }
        }
        return req;
    }
};