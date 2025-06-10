class Solution {
public:
    int maxDifference(string s) {
        map<char, long long int> mp;
        for(int i=0; i<s.size(); i++) mp[s[i]]++;
        long long int odd = -1, even = -1;
        for(auto i: mp)
        {
            if(i.second%2 == 1)
            {
                if(odd == -1) odd = i.second;
                else odd = max(odd, i.second);
            }
            else
            {
                if(even == -1) even = i.second;
                else even = min(even, i.second);
            }
        }
        return odd - even;
    }
};