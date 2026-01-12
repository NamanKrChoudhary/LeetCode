class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        long long int n = points.size();
        if(n == 1) return 0;
        long long int req = 0;
        for(int i=1; i<n; i++)
        {
            long long int len = abs(points[i][0]-points[i-1][0]);
            long long int bre = abs(points[i][1]-points[i-1][1]);
            long long int diff = max(len, bre) - min(len, bre);
            req = req + max(len, bre);
        }
        return req;
    }
};