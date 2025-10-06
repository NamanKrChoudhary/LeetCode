class Solution {
public:
    vector<int> findCoins(vector<int>& numWays) {
        int n = numWays.size();
        vector<vector<int>> prevwaysum;
        vector<int> coins;
        vector<int> surrogate;
        for(int i=0; i<numWays.size(); i++)
        {
            if(numWays[i] > 0)
            {
                if(prevwaysum.size() == 0)
                {
                    if(numWays[i] > 1) return surrogate;
                    vector<int> curr(n+1);
                    curr[0] = 1;
                    for(int j=i+1; j <= n; j=j+i+1)
                    {
                        curr[j] = 1;
                    }
                    prevwaysum.push_back(curr);
                    coins.push_back(i+1);
                }
                else
                {
                    if(numWays[i] - prevwaysum[prevwaysum.size()-1][i+1] > 1 || numWays[i] < prevwaysum[prevwaysum.size()-1][i+1]) return surrogate;
                    else if(numWays[i] - prevwaysum[prevwaysum.size()-1][i+1] == 1)
                    {
                        vector<int> curr(n+1);
                        curr[0] = 1;
                        for(int sum = 1; sum <= n; sum++)
                        {
                            int temp = sum;
                            int waysum = 0;
                            for(int cno = 0; cno <= sum; cno=cno+i+1)
                            {
                                waysum = waysum + prevwaysum[prevwaysum.size()-1][sum-(cno)];
                            }
                            curr[sum] = waysum;
                        }
                        prevwaysum.push_back(curr);
                        coins.push_back(i+1);
                    }
                }
            }
            else
            {
                if(prevwaysum.size() != 0 && prevwaysum[prevwaysum.size()-1][i+1] != 0) return surrogate;
            }
        }
        // for(int i=0; i<prevwaysum.size(); i++)
        // {
        //     cout << coins[i] << endl;
        //     for(int j=0; j<=n; j++) cout << prevwaysum[i][j] << " "; cout << endl;
        // }
        return coins;
    }
};