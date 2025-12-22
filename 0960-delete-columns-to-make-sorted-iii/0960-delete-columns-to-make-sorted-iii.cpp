class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        long long int n = strs.size();
        long long int len = strs[0].size();
        vector<long long int> lis(strs[0].size());
        for(int i=0; i<len; i++)
        {
            long long int currmaxx = 1;
            for(int j=i-1; j>=0; j--)
            {
                bool check = true;
                for(int k=0; k<n; k++)
                {
                    if(strs[k][i] < strs[k][j]){check = false; break;}
                }
                if(check) currmaxx = max(currmaxx, lis[j]+1);
            }
            lis[i] = currmaxx;
        }
        long long int maxx = 1;
        //for(int i=0; i<len; i++)
        for(int i=0; i<len; i++) maxx = max(maxx, lis[i]);
        return len-maxx;
    }
};