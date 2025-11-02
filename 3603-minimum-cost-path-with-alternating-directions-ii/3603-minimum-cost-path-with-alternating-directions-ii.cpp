class Solution {
public:
    long long minCost(int m, int n, vector<vector<int>>& waitCost) {
        priority_queue<vector<long long int>, vector<vector<long long int>>, greater<vector<long long int>>> s;
        // arr = {cost, second, i, j};
        s.push({1, 1, 0, 0});
        vector<vector<long long int>> mincost(m, vector<long long int>(n, LLONG_MAX));
        mincost[0][0] = 1;
        while(!s.empty())
        {
            vector<long long int> curr = s.top();
            s.pop();
            if(curr[2] < m-1)
            {
                long long int nxti = curr[2]+1, nxtj = curr[3], nxtcost = curr[0] + ((nxti+1)*(nxtj+1));
                long long int nxtsec = curr[1] + 1;
                if(curr[1]%2 == 0)
                {
                    nxtsec = nxtsec + 1;
                    nxtcost = nxtcost + waitCost[nxti-1][nxtj];
                }
                if(nxtcost < mincost[nxti][nxtj])
                {
                    mincost[nxti][nxtj] = nxtcost;
                    s.push({nxtcost, nxtsec, nxti, nxtj});
                }
            }
            if(curr[3] < n-1)
            {
                long long int nxti = curr[2], nxtj = curr[3]+1, nxtcost = curr[0] + ((nxti+1)*(nxtj+1));
                long long int nxtsec = curr[1]+1;
                if(curr[1]%2 == 0)
                {
                    nxtsec = nxtsec + 1;
                    nxtcost = nxtcost + waitCost[nxti][nxtj-1];
                }
                //cout << curr[0] << " " << waitCost[nxti][nxtj-1] << " " << (nxti+1)*(nxtj+1) << endl;
                if(nxtcost < mincost[nxti][nxtj])
                {
                    mincost[nxti][nxtj] = nxtcost;
                    s.push({nxtcost, nxtsec, nxti, nxtj});
                }
            }
        }
        return mincost[m-1][n-1];
    }
};