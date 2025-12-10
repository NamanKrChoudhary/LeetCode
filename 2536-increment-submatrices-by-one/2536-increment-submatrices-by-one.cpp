class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<vector<long long int>>> rows(n);
        for(int i=0; i<queries.size(); i++)
        {
            rows[queries[i][0]].push_back({queries[i][1], queries[i][3], 1});
            rows[queries[i][2]].push_back({queries[i][1], queries[i][3], -1});
        }
        vector<long long int> curr(n);
        vector<vector<int>> arr(n, vector<int>(n, 0));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<rows[i].size(); j++)
            {
                if(rows[i][j][2] == 1)
                {
                    curr[rows[i][j][0]]++;
                    if(rows[i][j][1] < n-1) curr[rows[i][j][1]+1]--;
                }
            }
            arr[i][0] = curr[0];
            for(int j=1; j<n; j++)
            {
                arr[i][j] = arr[i][j-1]+curr[j];
            }
            //for(int i=0; i<n; i++) cout << curr[i] << " "; cout << endl;
            for(int j=0; j<rows[i].size(); j++)
            {
                if(rows[i][j][2] == -1)
                {
                    curr[rows[i][j][0]]--;
                    if(rows[i][j][1] < n-1) curr[rows[i][j][1]+1]++;
                }
            }
        }
        return arr;
    }
};