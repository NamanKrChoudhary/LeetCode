class Solution {
public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        long long int n = mat.size();
        long long int m = mat[0].size();
        bool dp[70][5000] = {};
        for(int i=0; i<m; i++) dp[0][mat[0][i]] = true;
        for(int i=1; i<n; i++)
        {
            for(int k=1; k<5000; k++)
            {
                bool check = false;
                for(int j=0; j<m; j++)
                {
                    if(k >= mat[i][j] && dp[i-1][k-mat[i][j]] == true) {check = true; break;}
                }
                dp[i][k] = check;
            }
        }
        int req = 5000;
        for(int i=0; i<5000; i++)
        {
            if(dp[n-1][i] == true) 
            {
                req = min(req, abs(target-i));
            }
        }
        return req;
    }
};