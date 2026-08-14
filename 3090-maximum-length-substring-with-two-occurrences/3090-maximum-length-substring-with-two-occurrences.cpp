class Solution {
public:
    int maximumLengthSubstring(string s) {
        //map<char, long long int> mp;
        vector<long long int> mp(26, 0);
        long long int n = s.size();
        long long int req = 1;
        for(long long int i=0, j=0; i<n && j<n; j++)
        {
            mp[s[j]-'a']++;
            while(mp[s[j]-'a'] > 2) 
            {
                mp[s[i]-'a']--;
                i = i+1;
            }
            req = max(req, (j-i+1));
        }
        return req;
    }
};