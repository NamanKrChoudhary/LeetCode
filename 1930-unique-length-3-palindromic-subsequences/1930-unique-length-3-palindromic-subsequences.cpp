class Solution {
public:
    int countPalindromicSubsequence(string s) {
        long long int n = s.size();
        vector<vector<long long int>> prev(n, vector<long long int>(26)), aft(n, vector<long long int>(26));
        vector<long long int> pcurr(26, 0);
        for(int i=0; i<n; i++)
        {
            prev[i] = pcurr;
            pcurr[s[i]-'a']++;
        }
        vector<long long int> acurr(26, 0);
        for(int i=n-1; i>=0; i--)
        {
            aft[i] = acurr;
            acurr[s[i]-'a']++;
        }
        set<string> req;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<26; j++)
            {
                if(prev[i][j] > 0 && aft[i][j] > 0)
                {
                    string temp = "";
                    temp.push_back('a'+j);
                    temp.push_back(s[i]);
                    req.insert(temp);
                }
            }
        }
        return req.size();
    }
};