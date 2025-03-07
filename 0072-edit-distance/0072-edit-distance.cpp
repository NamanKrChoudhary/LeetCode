class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<long long int>> v(word1.size()+1, vector<long long int>(word2.size()+1));
        long long int n = word1.size(), m= word2.size();
        long long int minn = n+m;
        for(int j=0; j<=m; j++) v[0][j] = j;
        for(int i=0; i<=n; i++) v[i][0] = i;
        for(int i=1; i<=word1.size(); i++)
        {
            for(int j=1; j<=word2.size(); j++)
            {
                if(word1[i-1] == word2[j-1])
                {
                    long long int lt = v[i-1][j-1], lnt = v[i-1][j]+1;
                    v[i][j] = min(lt, lnt);  
                }
                else
                {
                    long long int linst = v[i][j-1]+1, ldel = v[i-1][j]+1, lch = v[i-1][j-1]+1;

                    v[i][j] = min(linst, min(ldel, lch));
                }
            }
        }
        //for(int i=0; i<=n;i++) {for(int j=0; j<=m; j++) cout << v[i][j] << " "; cout << endl;}
        return v[n][m] ;
    }
};