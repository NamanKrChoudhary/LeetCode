class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long int n = workerTimes.size();
        long long int h = mountainHeight;
        set<pair<long long int, long long int>> nextprice;
        for(int i=0; i<n; i++) nextprice.insert({workerTimes[i], i});
        vector<long long int> nextadd(n); for(int i=0; i<n; i++) nextadd[i] = 2*workerTimes[i];
        long long int maxx = 0;
        for(int i=h; i>0; i--)
        {
            pair<long long int, long long int> temp = *nextprice.begin();
            // cout << i << endl;
            // cout << temp.first << " " << temp.second << endl;
            nextprice.erase(temp);
            maxx = max(maxx, temp.first);
            temp.first = temp.first + nextadd[temp.second];
            nextprice.insert(temp);
            nextadd[temp.second] = nextadd[temp.second] + workerTimes[temp.second];
        }
        return maxx;
    }
};