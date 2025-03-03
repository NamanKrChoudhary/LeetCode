class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<int>> v(t.size(), vector<int>(s.size()));
        for(int i=0; i<t.size(); i++)
        {
            long long int prev = 0;
            for(int j=i; j<s.size()-(t.size()-i-1); j++)
            {
                if(s[j] == t[i])
                {
                    if(i>0 && j>0) v[i][j] = prev + v[i-1][j-1];
                    else v[i][j] = 1+prev;
                    prev = v[i][j];
                }
                else
                {
                    v[i][j] = prev;
                }
            }
        }
        return v[t.size()-1][s.size()-1];
    }
};