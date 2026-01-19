class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        long long int n = mat.size(), m = mat[0].size(), th = threshold;
        vector<vector<long long int>> rowpref(n, vector<long long int>(m,0)), rowcolpref(n, vector<long long int>(m,0)), colpref(n, vector<long long int>(m,0));
        for(int i=0; i<n; i++) rowpref[i][0] = mat[i][0];
        for(int i=0; i<n; i++)
        {
            for(int j=1; j<m; j++) rowpref[i][j] = mat[i][j] + rowpref[i][j-1];
        }
        for(int i=0; i<m; i++) rowcolpref[0][i] = rowpref[0][i];
        for(int j=0; j<m; j++)
        {
            for(int i=1; i<n; i++) rowcolpref[i][j] = rowpref[i][j] + rowcolpref[i-1][j];
        }
        long long int minn = min(n,m);
        for(int i=0; i<m; i++) colpref[0][i] = mat[0][i];
        for(int j=0; j<m; j++)
        {
            for(int i=1; i<n; i++) colpref[i][j] = colpref[i-1][j] + mat[i][j];
        }
        for(int sz=minn; sz>0; sz--)
        {
            for(int i=0; i+sz-1<n; i++)
            {
                for(int j=0; j+sz-1<m; j++)
                {
                    long long int right = rowcolpref[i+sz-1][j+sz-1] - rowcolpref[i][j+sz-1] + rowpref[i][j+sz-1];
                    long long int left = rowcolpref[i+sz-1][j] - rowcolpref[i][j] + rowpref[i][j];
                    long long int strip = colpref[i+sz-1][j] - colpref[i][j] + mat[i][j];
                    long long int curr = right - left + strip;
                    if(curr <= th) return sz;
                }
            }
        }
        return 0;
    }
};