class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long int>> mincost(26, vector<long long int>(26,-1));
        for(int i=0; i<original.size(); i++)
        {
            if(mincost[original[i]-'a'][changed[i]-'a'] == -1) mincost[original[i]-'a'][changed[i]-'a'] = cost[i];
            else mincost[original[i]-'a'][changed[i]-'a'] = min(mincost[original[i]-'a'][changed[i]-'a'], static_cast<long long int>(cost[i]));
        }
        for(int k=0; k<26; k++)
        {
            for(int i=0; i<26; i++)
            {
                for(int j=0; j<26; j++)
                {
                    if(j == i) mincost[i][j] = 0;
                    if(mincost[i][j] != -1 && mincost[i][k] != -1 && mincost[k][j] != -1)mincost[i][j] = min(mincost[i][k]+mincost[k][j], mincost[i][j]);
                    else if(mincost[i][k] != -1 && mincost[k][j] != -1) mincost[i][j] = mincost[i][k] + mincost[k][j]; 
                }
            }
        }
        long long int req = 0;
        for(int i=0; i<source.size(); i++)
        {
            if(mincost[source[i]-'a'][target[i]-'a'] == -1) return -1;
            req = req + mincost[source[i]-'a'][target[i]-'a'];
        }
        return req;
    }
};