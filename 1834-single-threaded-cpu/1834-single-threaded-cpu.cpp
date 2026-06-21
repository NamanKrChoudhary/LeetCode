class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        long long int n = tasks.size();
        vector<vector<long long int>> arr(n, vector<long long int>(3));
        for(int i=0; i<n; i++)
        {
            arr[i][0] = tasks[i][0];
            arr[i][1] = tasks[i][1];
            arr[i][2] = i;
        }
        sort(arr.begin(), arr.end());
        priority_queue<vector<long long int>, vector<vector<long long int>>, greater<vector<long long int>>> pq;
        long long int ind = 0;
        vector<int> req;
        while(ind < arr.size())
        {
            long long int currtime = arr[ind][0];
            while(ind < n && currtime == arr[ind][0])
            {
                pq.push({arr[ind][1], arr[ind][2]});
                ind = ind + 1;
            }
            while(!pq.empty())
            {
                vector<long long int> curr = pq.top();
                pq.pop();
                req.push_back(curr[1]);
                currtime = currtime + curr[0];
                while(ind < n && currtime >= arr[ind][0])
                {
                    pq.push({arr[ind][1], arr[ind][2]});
                    ind = ind + 1;
                }
            }
        }
        return req;
    }
};