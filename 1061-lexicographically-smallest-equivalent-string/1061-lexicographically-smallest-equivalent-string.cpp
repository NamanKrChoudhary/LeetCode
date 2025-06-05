class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        map<char, set<char>> mp;
        for(int i=0; i<s1.size(); i++)
        {
            mp[s1[i]].insert(s2[i]);
            mp[s2[i]].insert(s1[i]);
        }
        map<char, bool> vis;
        long long int cnt = -1;
        for(auto i: mp)
        {
            cnt = cnt + 1;
            if(vis.find(i.first) == vis.end())
            {
                vis[i.first] = true;
                set<char> temp;
                temp.insert(i.first);
                queue<char> q;
                q.push(i.first);
                while(!q.empty())
                {
                    char currchar = q.front();
                    q.pop();
                    for(auto nextchar: mp[currchar])
                    {
                        if(vis.find(nextchar) == vis.end())
                        {
                            vis[nextchar] = true;
                            temp.insert(nextchar);
                            q.push(nextchar);
                        }
                    }
                }
                for(auto ch : temp)
                {
                    mp[ch] = temp;
                }
            }
        }
        string aa = "";
        for(int i=0; i<baseStr.size(); i++)
        {
            if(mp.find(baseStr[i]) == mp.end()) aa.push_back(baseStr[i]);
            else
            {
                set<char> temp = mp[baseStr[i]];
                char currch = *temp.begin();
                aa.push_back(currch);
            }
        }
        return aa;
    }
};