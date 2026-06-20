class Solution {
public:
    long long maxRatings(vector<vector<int>>& units) {
        long long int n = units.size(), m = units[0].size();
        vector<pair<long long int,long long int>> el(n);
        long long int firstsum = 0;
        for(int i=0; i<n; i++) sort(units[i].begin(), units[i].end());
        for(int i=0; i<n; i++) 
        {
            firstsum = firstsum + units[i][0];
            el[i].first = units[i][0];
        }
        if(m == 1) return firstsum;
        long long int secondsum = 0;
        for(int i=0; i<n; i++)
        {
            secondsum = secondsum + units[i][1];
            el[i].second = units[i][1];
        }
        long long int maxx = 0;
        sort(el.begin(), el.end());
        for(int i=0; i<n; i++)
        {
            maxx = max(maxx, secondsum-el[i].second+el[0].first);
        }
        return maxx;
    }
};