class Solution {
public:
    string sortVowels(string s) {
        set<char> vow = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        vector<char> ns(s.size(), '#');
        vector<char> v;
        long long int n = s.size();
        for(int i=0; i<n; i++)
        {
            if(vow.find(s[i]) != vow.end()) v.push_back(s[i]);
            else ns[i] = s[i];
        }
        sort(v.begin(), v.end());
        long long int curri = 0;
        for(int i=0; i<s.size(); i++)
        {
            if(ns[i] == '#') ns[i] = v[curri++];
        }
        string p = "";
        for(int i=0; i<n; i++) p.push_back(ns[i]);
        return p;
    }
};