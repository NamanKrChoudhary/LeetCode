class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size(); int m = matrix[0].size();
        vector<vector<int>> right(n, vector<int>(m)), down(n, vector<int>(m));
        for(int i=0; i<n; i++)
        {
            int prev = -1;
            for(int j=m-1; j>=0; j--)
            {
                if(matrix[i][j] == 1){ prev = max(prev, j); right[i][j] = prev;}
                else {prev = -1;}
            }
        }
        for(int j=0; j<m; j++)
        {
            int prev = -1;
            for(int i=n-1; i>=0; i--)
            {
                if(matrix[i][j] == 1) {prev = max(prev, i); down[i][j] = prev;}
                else prev = -1;
            }
        }
        long long int ans = 0;
        for(int i=n-1; i>=0; i--)
        {
            for(int j=m-1; j>=0; j--)
            {
                if(matrix[i][j] == 1)
                {
                    long long int l = j;
                    int minn = down[i][j]-i+1;
                    for(int k=j; k<=right[i][j]; k++)
                    {
                        minn = min(minn, (down[i][k]-i+1));
                        if(minn >= (k-j+1)) ans = ans + 1;
                    }
                }
            }
        }
        return ans;
    }
};