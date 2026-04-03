class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        long long int n = robots.size();
        vector<vector<long long int>> arr;
        for(int i=0; i<n; i++)
        {
            arr.push_back({robots[i], 1, distance[i]});
        }
        set<long long int> robopos;
        for(int i=0; i<n; i++) robopos.insert(robots[i]);
        long long int extra = 0;
        for(int i=0; i<walls.size(); i++)
        {
            if(robopos.find(walls[i]) != robopos.end()) extra = extra + 1;
            else arr.push_back({walls[i], 2});
        }
        sort(arr.begin(), arr.end());
        long long int wallnos = 0;
        long long int prevpos = -1;
        long long int distcov = -1;
        map<long long int, long long int> right;
        for(int i=0; i<arr.size(); i++)
        {
            if(prevpos == -1)
            {
                if(arr[i][1] == 2) continue;
                else 
                {
                    prevpos = arr[i][0];
                    distcov = arr[i][0] + arr[i][2];
                }
            }
            else
            {
                if(arr[i][1] == 2)
                {
                    if(arr[i][0] > distcov)
                    {
                        right[prevpos] = wallnos;
                        prevpos = -1;
                        distcov = -1;
                        wallnos = 0;
                    }
                    else wallnos = wallnos + 1;
                }
                else
                {
                    right[prevpos] = wallnos;
                    prevpos = arr[i][0];
                    distcov = arr[i][0]+arr[i][2];
                    wallnos = 0;
                }
            }
        }
        if(prevpos != -1)
        {
            right[prevpos] = wallnos;
            wallnos = 0;
            prevpos = -1;
            distcov = -1;
        }
        map<long long int, long long int> left;
        for(int i=arr.size()-1; i>=0; i--)
        {
            if(prevpos == -1)
            {
                if(arr[i][1] == 2) continue;
                else 
                {
                    prevpos = arr[i][0];
                    distcov = arr[i][0] - arr[i][2];
                }
            }
            else
            {
                if(arr[i][1] == 2)
                {
                    if(arr[i][0] < distcov)
                    {
                        right[prevpos] = wallnos;
                        prevpos = -1;
                        distcov = -1;
                        wallnos = 0;
                    }
                    else wallnos = wallnos + 1;
                }
                else
                {
                    right[prevpos] = wallnos;
                    prevpos = arr[i][0];
                    distcov = arr[i][0]+arr[i][2];
                    wallnos = 0;
                }
            }
        }
        if(prevpos != -1)
        {
            right[prevpos] = wallnos;
            wallnos = 0;
            prevpos = -1;
            distcov = -1;
        }
        vector<long long int> roboind;
        for(int i=0; i<arr.size(); i++) if(arr[i][1] == 1) roboind.push_back(i);
        map<pair<long long int, long long int>, long long int> mid;
        for(int i=1; i<roboind.size(); i++)
        {
            long long int wallno = 0;
            for(int j=roboind[i-1]+1; j<roboind[i]; j++) wallno = wallno + 1;
            mid[{i-1, i}] = wallno; 
        }
        vector<vector<long long int>> dp(n, vector<long long int>(2));
        dp[0][0] = left[arr[roboind[0]][0]];
        dp[0][1] = right[arr[roboind[0]][0]];
        for(int i=1; i<n; i++)
        {
            dp[i][1] = max(dp[i-1][0]+right[arr[roboind[i]][0]], dp[i-1][1]+right[arr[roboind[i]][0]]);
            if(arr[roboind[i]][0]-arr[roboind[i-1]][0] <= arr[roboind[i]][2]+arr[roboind[i-1]][2])
            {
                dp[i][0] = max(dp[i-1][0]+ left[arr[roboind[i]][0]], dp[i-1][1]-right[arr[roboind[i-1]][0]]+mid[{i-1, i}]);
                //cout << right[arr[roboind[i]][0]] << " " << mid[{i-1, i}] << endl;
            }
            else
            {
                dp[i][0] = max(dp[i-1][0]+left[arr[roboind[i]][0]], dp[i-1][1]+left[arr[roboind[i]][0]]);
            }
        }
        //for(int i=0; i<n; i++) cout << dp[i][0] << " " << dp[i][1] << endl;
        //cout << extra << endl;
        return max(dp[n-1][0], dp[n-1][1])+extra;
    }
};