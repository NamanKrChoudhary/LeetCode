class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        long long int n = mat.size(), m = mat[0].size();
        for(int i=0; i<n; i++)
        {
            if(i%2 == 0)
            {
                for(int j=0, l=((k)%m); j<m; j++, l++)
                {
                    if(mat[i][j] != mat[i][(l%m)]) return false;
                }
            }
            else
            {
                for(int j=m-1, l=(m-k-1)%m; j>=0; j--, l--)
                {
                    if(mat[i][j] != mat[i][(l+m)%m]) return false;
                }
            }
        }
        return true;
    }
};