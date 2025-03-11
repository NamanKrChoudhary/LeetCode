class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> v(s.size()+1, vector<bool>(p.size()+1));
        long long int n=s.size(), m=p.size();
        bool check = true; v[0][0] = true;
        for(int i=1; i<=m; i++)
        {
            if(p[i-1] != '*') check = false;
            v[0][i] = check;
        }
        for(int i=1; i<=n; i++) v[i][0] = false;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(s[i-1] == p[j-1]) v[i][j] = v[i-1][j-1];
                else if(p[j-1] == '?') v[i][j] = v[i-1][j-1];
                else if(p[j-1] == '*') v[i][j] = v[i-1][j-1] || v[i-1][j] || v[i][j-1];
                else v[i][j] = false;
            }
        }
        //cout << v[0][1] << " " << v[1][1] << " " << v[2][1] << endl;
        return v[n][m];
    }
};