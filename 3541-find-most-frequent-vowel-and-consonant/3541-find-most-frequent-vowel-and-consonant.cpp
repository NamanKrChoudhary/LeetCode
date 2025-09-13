class Solution {
public:
    int maxFreqSum(string s) {
        map<char, long long int> mp;
        for(int i=0; i<s.size(); i++) mp[s[i]]++;
        long long int mv = 0;
        mv = max(mv, mp['a']); mv = max(mv, mp['e']); mv = max(mv, mp['i']); mv = max(mv, mp['o']); mv = max(mv, mp['u']);
        long long int mc = 0;
        for(auto i: mp)
        {
            if(i.first != 'a' && i.first != 'e' && i.first != 'i' && i.first != 'o' && i.first != 'u') mc = max(mc , i.second);
        }
        return mv+mc;
        
    }
};