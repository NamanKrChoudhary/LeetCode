class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        long long int n = strs.size();
        long long int len = strs[0].size();
        vector<bool> off(len, false);
        vector<bool> tocompare(n-1, true);
        bool ineq = false, eq = false;
        for(int i=0; i<len; i++)
        {
            vector<bool> temp = tocompare;
            for(int j=1; j<n; j++)
            {
                if(tocompare[j-1] == true)
                {
                    if(strs[j][i] < strs[j-1][i])
                    {
                        ineq = true;
                        break;
                    }
                    else if(strs[j][i] == strs[j-1][i])
                    {
                        eq = true;
                    }
                    else
                    {
                        temp[j-1] = false;
                    }
                }
            }
            //if(i == 0) for(int j=0; j<n-1; j++) cout << tocompare[j] << " ";
            if(ineq == true)
            {
                ineq = false;
                eq = false;
                off[i] = true;
            }
            else if(eq == true)
            {
                eq = false;
                tocompare = temp;
            }
            else break;
        }
        long long int cnt = 0;
        for(int i=0; i<len; i++) if(off[i]) cnt = cnt + 1;
        return cnt;
    }
};