class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<long long int>> v(word1.size(), vector<long long int>(word2.size()));
        long long int maxx = 0;
        for(int i=0; i<word1.size(); i++)
        {
            for(int j=0; j<word2.size(); j++)
            {
                if(word1[i] == word2[j])
                {
                    if(i>0 && j>0) v[i][j] = v[i-1][j-1]+1;
                    else v[i][j] = 1;
                }
                else
                {
                    long long int l1 =0, l2 = 0;
                    if(i>0) l1 = v[i-1][j];
                    if(j>0) l2 = v[i][j-1];
                    v[i][j] = max(l1, l2);
                }
                maxx = max(maxx, v[i][j]);
            }
        }
        return (word1.size()-maxx)+(word2.size()-maxx);
    }
};