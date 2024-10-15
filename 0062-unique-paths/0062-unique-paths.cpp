class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> arr(m, vector<int>(n));
        arr[m-1][n-1] = 1;
        for(int i=m-1; i>=0; i--)
        {
            for(int j=n-1; j>=0; j--)
            {
                if(j<n-1) arr[i][j] = arr[i][j]+arr[i][j+1];
                if(i<m-1) arr[i][j] = arr[i][j] + arr[i+1][j];
            }
        }
        return arr[0][0];
    }
};