class Solution {
public:
    string clearStars(string s) {
        multiset<char> ch;
        map<char, vector<long long int>> mp;
        string temps = s;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i] == '*') 
            {
                auto curr = ch.begin();
                long long int tochange = mp[*curr][mp[*curr].size()-1];
                mp[*curr].pop_back(); ch.erase(curr);
                temps[tochange] = '$'; temps[i] = '$';

            }
            else {mp[s[i]].push_back(i); ch.insert(s[i]);}
        }
        string fin = "";
        for(int i=0; i<s.size(); i++)
        {
            if(temps[i] != '$') fin.push_back(temps[i]);
        }
        return fin;
    }
};