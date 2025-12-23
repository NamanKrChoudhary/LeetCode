class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        long long int n = events.size();
        vector<vector<long long int>> arr;
        for(int i=0; i<n; i++)
        {
            arr.push_back({events[i][0], 1, events[i][2]});
            arr.push_back({events[i][1], 2, events[i][2]});
        }
        sort(arr.begin(), arr.end());
        // vector<long long int> maxarr(arr.size());
        // for(int i=arr.size()-1; i>=0; i--)
        long long int maxx = 0;
        long long int req = 0;
        for(int i=arr.size()-1; i>=0; i--)
        {
            if(arr[i][1] == 1) maxx = max(maxx, arr[i][2]);
            else req = max(req, arr[i][2]+maxx);
        }
        return req;
    }
};