class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        vector<vector<long long int>> pref(mat.size(), vector<long long int>(mat[0].size()));
        long long int n = mat.size();
        long long int m = mat[0].size();
        for(int j=0; j<m; j++)
        {
            long long int cnt = 0;
            for(int i=0; i<n; i++)
            {
                if(mat[i][j] == 1)
                {
                    cnt = cnt + 1;
                    pref[i][j] = cnt;
                }
                else cnt = 0;
            }
        }
        vector<vector<long long int>> sub(n, vector<long long int>(m));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(mat[i][j] == 0) continue;
                long long int height = pref[i][j];
                for(int k=j; k>=0; k--)
                {
                    if(mat[i][k] == 0) break;
                    height = min(height, pref[i][k]);
                    sub[i][j] = sub[i][j]  + height;
                }
            }
        }
        long long int subrect = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++) subrect = subrect + sub[i][j];
        }
        return subrect;
    }
};