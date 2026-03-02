class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        long long int n = grid.size();
        vector<pair<long long int, long long int>> arr(n);
        for(int i=0; i<n; i++)
        {
            long long int curr = 0;
            for(int j=n-1; j>=0; j--) 
            {
                if(grid[i][j] == 0) curr = curr + 1;
                else break;
            }
            arr[i] = {curr, i};
        }
        //for(int i=0; i<n; i++) {for(int j=0; j<n; j++) cout << grid[i][j] << " "; cout << endl;} 
        sort(arr.begin(), arr.end(), 
         [](const pair<long long,long long>& a, const pair<long long,long long>& b){
             if (a.first != b.first) return a.first < b.first;
             return a.second > b.second;
         });
        stack<long long int> s;
        for(int i=0; i<n; i++) if(arr[i].first < i) return -1;
        vector<bool> vis(n, false);
        long long int req = 0;
        for(int i=0; i<n; i++)
        {
            long long int reqz = n-1-i;
            long long int mindiff = 1e5;
            long long int ind = -1;
            //long long int minind = 1e5;
            //long long int minval = 1e5;
            for(int j=0; j<n; j++)
            {
                if(!vis[j] && arr[j].first >= reqz)
                {
                    if(arr[j].second-i < mindiff)
                    {
                        mindiff = arr[j].second-i;
                        ind = j;
                    }
                }
            }
            req = req + mindiff;
            vis[ind] = true;
            for(int j=0; j<n; j++)
            {
                if(!vis[j] && arr[j].second <= i+mindiff) arr[j].second = arr[j].second + 1;
            }
        }
        return req;
    }
};