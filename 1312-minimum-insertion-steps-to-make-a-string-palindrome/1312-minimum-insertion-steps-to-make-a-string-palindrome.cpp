class Solution {
public:
    int minInsertions(string s) {
        vector<vector<long long int>> arr(s.size(), vector<long long int>(s.size()));
        long long int maxx = 0, n = s.size();
        for(int i=0; i<s.size(); i++)
        {
            long long int j = s.size()-1;
            while(j>=i)
            {
                if(s[i] == s[j])
                {
                    if(i==j && i>0 && j<s.size()-1) arr[i][j] = arr[i-1][j+1]+1;
                    else if(i == j) arr[i][j] = 1;
                    else if(i>0 && j<s.size()-1) arr[i][j] = arr[i-1][j+1]+2;
                    else arr[i][j] = 2;
                }
                else
                {
                    long long int len1 = 0, len2 = 0, len3 = 0;
                    if(i>0 && j<s.size()-1 && s[i-1] == s[j+1]) len1 = arr[i-1][j+1];
                    if(i>0) len2 = arr[i-1][j];
                    if(j<s.size()-1) len3 = arr[i][j+1];
                    arr[i][j] = max(max(len1, len2), len3);
                }
                maxx = max(arr[i][j],maxx);
                j--;
            }
        }
        cout << maxx << endl;
        return (s.size() - maxx);
    }
};