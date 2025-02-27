class Solution {
public:
    int longestPalindromeSubseq(string s) {
        long long int i=0, j=s.size()-1;
        long long int n = s.size();
        vector<vector<long long int>> v(s.size(), vector<long long int>(s.size()));
        // while(i<j)
        // {
        //     if(s[i] == s[j]) v[i][j] = 1;
        //     j--;
        // }
        // i=0; j=s.size()-1;
        // while(i<j)
        // {
        //     if(s[i] == s[j]) v[i][j] = 1;
        //     //cout << s[i] << " " << s[j] << " " << v[i][j] << endl;
        //     i++;
        // }
        //for(int i=0; i<n; i++) {for(int j=0; j<n; j++) cout << v[i][j] << " "; cout << endl;}
        i=0; j=s.size()-1;
        long long int maxx = 1;
        for(i=0; i<s.size(); i++)
        {
            j = s.size()-1;
            while(i<=j)
            {
                if(s[i] == s[j] )
                {
                    if(i == j)
                    {
                        if((i>0 && j<s.size()-1))v[i][j] = v[i-1][j+1]+1;
                        else v[i][j] = 1;
                    }
                    else
                    {
                        if((i>0 && j<s.size()-1))v[i][j] = v[i-1][j+1]+2;
                        else v[i][j] = 2;
                    }
                }
                else
                {
                    long long int len1 = 0, len2 = 0;
                    if(j<s.size()-1) len2 = v[i][j+1];
                    if(i>0) len1 = v[i-1][j];
                    v[i][j] = max(len1, len2);
                }
                maxx = max(maxx, v[i][j]);
                //cout << v[i][j] << " ";
                j--;
            }
            //cout << endl;
        }
        return maxx;

    }
};