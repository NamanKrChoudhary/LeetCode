class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        long long int n = mat.size(), m = mat[0].size();
        vector<long long int>rowsum(n, 0), colsum(m,0);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++) rowsum[i] = rowsum[i] + mat[i][j];
        }
        for(int j=0; j<m; j++)
        {
            for(int i=0; i<n; i++) colsum[j] = colsum[j] + mat[i][j];
        }
        long long int req = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++) if(colsum[j] == 1 && rowsum[i] == 1 && mat[i][j] == 1) req = req + 1;
        }
        return req;
    }
};