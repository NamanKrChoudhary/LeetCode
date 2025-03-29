class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> right(n, vector<int>(m));
        int prev = -1;
        for(int i=0; i<n; i++)
        {
            prev = -1;
            for(int j = m-1; j>=0; j--)
            {
                if(matrix[i][j] == '1') {prev = max(prev, j); right[i][j] = prev;}
                else prev = -1;
            }
        }
        vector<vector<int>> down(n, vector<int>(m));
        prev = -1;
        for(int j=0; j<m; j++)
        {
            prev = -1; 
            for(int i=n-1; i>=0; i--)
            {
                if(matrix[i][j] == '1') {prev = max(prev, i); down[i][j] = prev;}
                else prev = -1;
            }
        }
        vector<vector<pair<int, int>>> v(n, vector<pair<int, int>>(m));
        int maxx = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(matrix[i][j] == '1')
                {
                    int r=j,d=down[i][j];
                    for(int k=r; k<=right[i][j]; k++)
                    {
                        r = k;
                        d = min(d, down[i][k]);
                        int curr = (r-j+1)*(d-i+1);
                        maxx = max(curr, maxx);
                    }
                }
            }
        }
        return maxx;

    }
};