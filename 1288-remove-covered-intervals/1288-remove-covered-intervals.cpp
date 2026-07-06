class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        map<pair<long long int, long long int>, long long int> mp;
        for(int i=0; i<intervals.size(); i++) mp[{intervals[i][0], intervals[i][1]}]++;
        vector<pair<long long int, long long int>> arr;
        for(auto i: mp)
        {
            arr.push_back({i.first.first, 1LL});
            arr.push_back({i.first.second, (-1)*(i.first.first)});
        }
        sort(arr.begin(), arr.end());
        multiset<long long int> ms;
        long long int cnt1 = 0, cnt2 = 0;
        for(int i=0; i<arr.size(); i++)
        {
            if(arr[i].second == 1) ms.insert(arr[i].first);
            else 
            {
                long long int currstart = (-1)*(arr[i].second);
                if(ms.count(currstart) > 1) cnt1 = cnt1 + 1;
                else if(*ms.begin() < currstart) 
                {
                    //cout << arr[i].first << " " << arr[i].second << " " << *ms.begin() << " " << currstart << endl;
                    cnt2 = cnt2 + 1;
                }
                //cout << currstart << endl;
                auto it = ms.find(currstart);
                ms.erase(it);
            }
        }
        //cout << cnt1 << " " << cnt2 << endl;
        return mp.size() - cnt1 - cnt2;
    }
};