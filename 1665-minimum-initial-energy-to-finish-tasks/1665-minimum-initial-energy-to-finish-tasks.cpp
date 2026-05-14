class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        long long int minn = 0;
        long long int n = tasks.size();
        for(int i=0; i<n; i++) minn = minn + tasks[i][0];
        vector<vector<long long int>> arr(n, vector<long long int>(3));
        for(int i=0; i<n; i++)
        {
            arr[i][0] = tasks[i][1] - tasks[i][0];
            arr[i][1] = tasks[i][1];
            arr[i][2] = tasks[i][0];
        }
        sort(arr.rbegin(), arr.rend());
        long long int extra = 0;
        long long int temp = minn;
        //for(int i=0; i<n; i++) cout << arr[i][0] << " " << arr[i][1] << endl;
        for(int i=0; i<n; i++)
        {
            //cout << minn << endl;
            if(minn >= arr[i][1]) {minn = minn-arr[i][2]; continue;}
            else
            {
                extra = extra + (arr[i][1]-minn);
                minn = arr[i][1];
                minn = minn - arr[i][2];
            }
        }
        //cout << temp << " " << extra << endl;
        return temp + extra;
    }
};