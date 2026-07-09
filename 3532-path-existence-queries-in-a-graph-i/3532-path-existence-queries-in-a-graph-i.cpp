class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        //long long int n = nums.size();
        vector<long long int> prev(n);
        for(int i=1; i<n; i++) 
        {
            if(nums[i]-nums[i-1] <= maxDiff) prev[i] = prev[i-1];
            else prev[i] = i;
        }
        vector<bool> req(queries.size(), false);
        for(int i=0; i<queries.size(); i++) 
        {
            long long int minn = min(queries[i][0], queries[i][1]);
            long long int maxx = max(queries[i][0], queries[i][1]);
            if(prev[maxx] <= minn) req[i] = true;
        }
        return req;
    }
};