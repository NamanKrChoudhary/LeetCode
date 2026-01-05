class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long int n = matrix.size();
        long long int tot = 0, minn = 1e9, cnt = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(matrix[i][j] < 0) cnt = cnt + 1;
                tot = tot + abs(matrix[i][j]);
                minn = min(minn, static_cast<long long int>(abs(matrix[i][j])));
            }
        }
        if(cnt%2 == 1) tot = tot - (2*minn);
        return tot;
    }
};