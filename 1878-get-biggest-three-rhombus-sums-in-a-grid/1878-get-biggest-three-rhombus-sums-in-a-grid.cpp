class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        set<long long int> s;
        long long int n = grid.size(), m = grid[0].size();
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                for(int k=0; i+k<n; k=k+2)
                {
                    //cout << i << " " << j << " " << k << endl;
                    if((j-(k/2) < 0) || (j+(k/2) >= m)) break;
                    long long int sum = 0;
                    long long int curri = i, currj = j;
                    if(k == 0) sum = sum + grid[curri][currj];
                    while(currj>j-(k/2))
                    {
                        sum = sum + grid[curri][currj];
                        curri = curri+1;
                        currj = currj-1;
                    }
                    while(currj < j)
                    {
                        sum = sum + grid[curri][currj];
                        curri = curri + 1;
                        currj = currj + 1;
                    }
                    while(currj < j+(k/2))
                    {
                        sum = sum + grid[curri][currj];
                        curri = curri-1;
                        currj = currj+1;
                    }
                    while(currj > j)
                    {
                        sum = sum + grid[curri][currj];;
                        curri = curri-1;
                        currj = currj-1;
                    }
                    // cout << i << " " << j << " " << k << endl;
                    // cout << sum << endl;
                    s.insert(sum);
                    if(s.size() > 3) 
                    {
                        auto it = s.begin();
                        s.erase(it);
                    }
                }
            }
        }
        vector<int> req;
        for(auto it: s) req.push_back(it);
        reverse(req.begin(), req.end());
        return req;
    }
};