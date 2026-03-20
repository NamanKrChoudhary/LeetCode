class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        long long int n = grid.size();
        long long int m = grid[0].size();
        vector<vector<int>> req(n-k+1, vector<int>(m-k+1,0));
        if(k == 1) return req;
        for(int i=0; i<n-k+1; i++)
        {
            for(int j=0; j<m-k+1; j++)
            {
                set<int> s;
                for(int r=i; r<i+k; r++)
                {
                    for(int c=j; c<j+k; c++)
                    {
                        s.insert(grid[r][c]);
                    }
                }
                vector<int> arr;
                for(auto k: s) arr.push_back(k);
                int minn = 0;
                if(arr.size() > 1) minn = arr[1]-arr[0];
                for(int k=0; k<arr.size(); k++) cout << arr[k] << " "; cout << endl;
                for(int k=2; k<arr.size(); k++) minn = min(minn, arr[k]-arr[k-1]);
                req[i][j] = minn;
            }
        }
        return req;
    }
};