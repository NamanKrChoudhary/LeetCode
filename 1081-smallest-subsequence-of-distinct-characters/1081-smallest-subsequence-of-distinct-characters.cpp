class Solution {
public:
    string smallestSubsequence(string s) {
        map<char, long long int> mp;
        set<char> ms;
        for(int i=0; i<s.size(); i++) 
        {
            mp[s[i]]++;
            ms.insert(s[i]);
        }
        string req = "";
        long long int st = 0;
        long long int prev = 0;
        long long int len = mp.size();
        for(int i=0; i<len; i++)
        {
            for(auto k: ms)
            {
                long long int check = -1;
                map<char, long long int> temp = mp;
                for(int j=st; j<s.size(); j++)
                {
                    if(s[j] == k && temp.size() == ms.size()) 
                    {
                        check = j; 
                        // cout << check << " " << temp.size() << " " << ms.size() << endl;
                        // for(auto l: temp) cout << l.first << " " << l.second << endl;
                        // for(auto l: ms) cout << l << endl;
                        break;
                    }
                    if(temp.find(s[j]) != temp.end()) temp[s[j]]--;
                    if(temp[s[j]] == 0) temp.erase(s[j]);
                }
                //cout << i << " " << k << " " << check << endl; 
                if(check != -1)
                {
                    req.push_back(k);
                    ms.erase(k);
                    for(int j=st; j<=check; j++)
                    {
                        if(mp.find(s[j]) != mp.end())mp[s[j]]--;
                        if(mp[s[j]] == 0) mp.erase(s[j]);
                    }
                    mp.erase(k);
                    st = check + 1;
                    break;
                }
            }
        }
        return req;
    }
};