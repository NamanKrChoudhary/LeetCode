class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        map<int, vector<int>> mp;
        for(int i=0; i<events.size(); i++) {mp[events[i][0]].push_back(events[i][1]);}
        multiset<long long int> ms;
        long long int cnt = 0;
        for(int i=0; i<1e5+1; i++)
        {
            if(mp.find(i) != mp.end())
            {
                for(auto j: mp[i]){ ms.insert(j);}
            }
            if(!ms.empty())
            {
                int ii = *ms.begin();
                auto it = ms.find(ii);
                ms.erase(it);
                cnt = cnt + 1;
            }
            ms.erase(i);
        }
        return cnt;
    }
};