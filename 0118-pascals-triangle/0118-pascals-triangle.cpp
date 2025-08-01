class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> arr(numRows);
        int n = numRows;
        for(int i=0; i<n; i++)
        {
            arr[i].push_back(1);
            for(int j=1; j<i; j++) arr[i].push_back(arr[i-1][j-1]+arr[i-1][j]);
            if(i > 0) arr[i].push_back(1);
        }
        return arr;
    }
};