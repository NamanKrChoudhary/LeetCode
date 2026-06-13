class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        map<string, long long int> mp;
        for(int i=0; i<words.size(); i++)
        {
            if(words[i].size() < k) continue;
            string curr = "";
            for(int j=0; j<k; j++) curr.push_back(words[i][j]);
            mp[curr]++; 
        }
        long long int req = 0;
        for(auto i: mp) if(i.second > 1) req = req + 1;
        return req;
    }
};