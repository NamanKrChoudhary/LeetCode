class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        long long int n = intervals.size();
        map<long long int, vector<long long int>> st, end;
        for(int i=0; i<n; i++)
        {
            st[intervals[i][0]].push_back(intervals[i][1]);
            end[intervals[i][1]].push_back(intervals[i][0]);
        }
        set<pair<long long int, long long int>> currpairs;
        map<pair<long long int, long long int>, long long int> paircnt;
        vector<pair<long long int, long long int>> curr;
        for(auto i: st) curr.push_back({i.first, 1});
        for(auto i: end) curr.push_back({i.first, 2});
        sort(curr.begin(), curr.end());
        vector<long long int> req;
        for(int i=0; i<curr.size(); i++)
        {
            //cout << curr[i].first << " " << curr[i].second << endl;
            if(curr[i].second == 1)
            {
                for(auto j: st[curr[i].first]) currpairs.insert({curr[i].first, j});
            }
            else
            {
                long long int tempcnt = 5;
                for(auto j: end[curr[i].first])
                {
                    tempcnt = min(tempcnt, paircnt[{j, curr[i].first}]);
                }
                //cout << curr[i].first << " " << tempcnt << endl;
                if(tempcnt >= 2) continue;
                else if(tempcnt == 1)
                {
                    //cout << i << " " << curr[i].first << endl;
                    long long int toinsert = curr[i].first;
                    vector<pair<long long int, long long int>> todel;
                    for(auto j: currpairs)
                    {
                        if(toinsert >= j.first && toinsert <= j.second) paircnt[j]++;
                        if(paircnt[j] >= 2) todel.push_back(j);
                    }
                    for(auto j: todel) currpairs.erase(j);
                    req.push_back(toinsert);
                }
                else
                {
                    long long int toinsert1 = curr[i].first-1, toinsert2 = curr[i].first;
                    vector<pair<long long int, long long int>> todel;
                    for(auto j: currpairs)
                    {
                        if(toinsert1 >= j.first && toinsert1 <= j.second) paircnt[j]++;
                        if(toinsert2 >= j.first && toinsert2 <= j.second) paircnt[j]++;
                        if(paircnt[j] >= 2) todel.push_back(j);
                    }
                    for(auto j: todel) currpairs.erase(j);
                    req.push_back(toinsert1);
                    req.push_back(toinsert2);
                }
            }
        }
        //for(auto i: req) cout << i << " "; cout << endl;
        return req.size();
    }
};